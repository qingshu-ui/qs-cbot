//
// Created by 17186 on 2/22/2023.
//

#include "MessageEvent.h"

int64_t Sender::user_id() const {
    return this->raw_sender["user_id"].asInt64();
}

std::string Sender::nickname() const {
    return this->raw_sender["nickname"].asString();
}

std::string Sender::sex() const {
    return this->raw_sender["sex"].asString();
}

int32_t Sender::age() const {
    return this->raw_sender["age"].asInt();
}

Sender::Sender(const Json::Value &sender) {
    this->raw_sender = sender;
}

int64_t Sender::group_id() const {
    return raw_sender["group_id"].asInt64();
}

MessageEvent::MessageEvent(const Json::Value &msg) {
    this->raw_msg = msg;
}

std::string MessageEvent::message_type() const {
    return this->raw_msg["message_type"].asString();
}

std::string MessageEvent::sub_type() const {
    return this->raw_msg["sub_type"].asString();
}

int32_t MessageEvent::message_id() const {
    return this->raw_msg["message_id"].asInt();
}

int64_t MessageEvent::user_id() const {
    return this->raw_msg["user_id"].asInt64();
}

std::string MessageEvent::message() const {
    return this->raw_msg["message"].asString();
}

std::string MessageEvent::raw_message() const {
    return this->raw_msg["raw_message"].asString();
}

int MessageEvent::font() const {
    return this->raw_msg["font"].asInt();
}

std::string MessageEvent::to_string() const {
    Json::FastWriter w;
    return w.write(this->raw_msg);
}

GroupMessageSender::GroupMessageSender(const Json::Value &sender) : Sender(sender) {

}

std::string GroupMessageSender::card() const {
    return this->raw_sender["card"].asString();
}

std::string GroupMessageSender::area() const {
    return this->raw_sender["area"].asString();
}

std::string GroupMessageSender::level() const {
    return this->raw_sender["level"].asString();
}

std::string GroupMessageSender::role() const {
    return this->raw_sender["role"].asString();
}

std::string GroupMessageSender::title() const {
    return this->raw_sender["title"].asString();
}
