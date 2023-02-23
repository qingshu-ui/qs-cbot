//
// Created by 17186 on 2/22/2023.
//

#include "server.h"
#include <map>
#include "bot/Bot.h"
#include "event/eventframe.h"
#include <thread>
#include <json/json.h>
#include <mutex>

std::map<int64_t, std::shared_ptr<Bot>> bots;
std::mutex m_mutex;
Json::Value m_resp;

void ServerController::handleNewMessage(const drogon::WebSocketConnectionPtr &ptr, std::string &&message,
                                        const drogon::WebSocketMessageType &messageType) {
    if (messageType != drogon::WebSocketMessageType::Text) {
        return;
    }

    // Multiple threads.
    std::thread([=]() {
        Json::Value message_json(Json::ValueType::objectValue);
        Json::Reader r;
        try {
            if (r.parse(message, message_json)) {
                // Handle resp.
                if (!message_json["echo"].empty() && message_json.isMember("echo")) {
                    m_mutex.lock();
                    m_resp = message_json;
                    m_mutex.unlock();
                    return;
                }
                // Handle new bot connection.
                BotConnectHandler::botClassification(message_json, ptr);
                // Handle event port.
                EventClassification::eventClassification(message_json);
            }
        } catch (...) {
            std::cout << "Failed to handle event.";
        }
    }).detach();
}

void ServerController::handleNewConnection(const drogon::HttpRequestPtr &ptr,
                                           const drogon::WebSocketConnectionPtr &connectionPtr) {
}

void ServerController::handleConnectionClosed(const drogon::WebSocketConnectionPtr &ptr) {
    auto it = bots.begin();
    for (; it != bots.end();) {
        if (!it->second->getRawBot()->connected()) {
            LOG_INFO << it->first << " disconnect.";
            bots.erase(it++);
            continue;
        }
        it++;
    }
}

void BotConnectHandler::botConnection(const Json::Value &conn, const drogon::WebSocketConnectionPtr &ptr) {
    if (conn["sub_type"].asString() == "connect") {
        LOG_INFO << conn["self_id"].asInt64() << " is connected.";
        m_mutex.lock();
        bots[conn["self_id"].asInt64()] = std::make_shared<Bot>(ptr);
        m_mutex.unlock();
    }
}

void BotConnectHandler::botDisconnection(const Json::Value &conn, const drogon::WebSocketConnectionPtr &ptr) {
    if (conn["sub_type"].asString() == "disable") {
        LOG_INFO << conn["self_id"].asInt64() << " is disabled.";
        m_mutex.lock();
        bots.erase(conn["self_id"].asInt64());
        m_mutex.unlock();
    }
}

void BotConnectHandler::botClassification(const Json::Value &conn, const drogon::WebSocketConnectionPtr &ptr) {
    if (conn["post_type"].asString() == PostType::META_EVENT &&
        conn["meta_event_type"].asString() == MetaEventType::LIFECYCLE) {
        if (conn["sub_type"].asString() == "connect") {
            BotConnectHandler::botConnection(conn, ptr);
        }
        if (conn["sub_type"].asString() == "disable") {
            BotConnectHandler::botDisconnection(conn, ptr);
        }
    }
}

const std::string PostType::MESSAGE = "message";
const std::string PostType::REQUEST = "request";
const std::string PostType::NOTICE = "notice";
const std::string PostType::META_EVENT = "meta_event";

const std::string MetaEventType::LIFECYCLE = "lifecycle";
const std::string MetaEventType::HEARTBEAT = "heartbeat";
