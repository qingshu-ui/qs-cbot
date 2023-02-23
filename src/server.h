//
// Created by 17186 on 2/22/2023.
//

#ifndef CQHTTP_SERVER_H
#define CQHTTP_SERVER_H

#include <drogon/WebSocketController.h>
#include "bot/Bot.h"

extern std::map<int64_t, std::shared_ptr<Bot>> bots;
extern std::mutex m_mutex;

extern Json::Value m_resp;

class ServerController : public drogon::WebSocketController<ServerController> {
public:
    void handleNewMessage(const drogon::WebSocketConnectionPtr &ptr, std::string &&message,
                          const drogon::WebSocketMessageType &messageType) override;

    void handleNewConnection(const drogon::HttpRequestPtr &ptr,
                             const drogon::WebSocketConnectionPtr &connectionPtr) override;

    void handleConnectionClosed(const drogon::WebSocketConnectionPtr &ptr) override;

    static void initPathRouting() {
        registerSelf__("/", {});
    }

};

namespace BotConnectHandler {

    void botClassification(const Json::Value &conn, const drogon::WebSocketConnectionPtr &ptr);

    void botConnection(const Json::Value &conn, const drogon::WebSocketConnectionPtr &ptr);

    void botDisconnection(const Json::Value &conn, const drogon::WebSocketConnectionPtr &ptr);

}

namespace PostType {
    extern const std::string MESSAGE;
    extern const std::string REQUEST;
    extern const std::string NOTICE;
    extern const std::string META_EVENT;
}

namespace MetaEventType {
    extern const std::string LIFECYCLE;
    extern const std::string HEARTBEAT;
}

#endif //CQHTTP_SERVER_H
