//
// Created by 17186 on 2/22/2023.
//

#include "GroupMessageEvent.h"

Anonymous::Anonymous(const Json::Value &anonymous) {
    this->raw_anonymous = anonymous;
}

int64_t Anonymous::id() const {
    return this->raw_anonymous["id"].asInt64();
}

std::string Anonymous::name() const {
    return this->raw_anonymous["name"].asString();
}

std::string Anonymous::flag() const {
    return this->raw_anonymous["flag"].asString();
}

GroupMessageSender GroupMessageEvent::sender() const {
    return GroupMessageSender(this->raw_msg["sender"]);
}

int64_t GroupMessageEvent::group_id() const {
    return this->raw_msg["group_id"].asInt64();
}

Anonymous GroupMessageEvent::anonymous() const {
    return Anonymous(this->raw_msg["anonymous"]);
}
