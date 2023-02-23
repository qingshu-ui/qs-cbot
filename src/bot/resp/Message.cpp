//
// Created by 17186 on 2/22/2023.
//

#include "Message.h"

bool Message::group() const {
    return this->raw_resp["data"]["group"].asBool();
}

int64_t Message::group_id() const {
    return this->raw_resp["data"]["group_id"].asInt64();
}

int32_t Message::message_id() const {
    return this->raw_resp["data"]["message_id"].asInt();
}

int32_t Message::real_id() const {
    return this->raw_resp["data"]["real_id"].asInt();
}

std::string Message::message_type() const {
    return this->raw_resp["data"]["message_type"].asString();
}

Sender Message::sender() const {
    return {this->raw_resp["data"]["sender"]};
}

int32_t Message::time() const {
    return this->raw_resp["data"]["time"].asInt();
}

std::string Message::message() const {
    return this->raw_resp["data"]["message"].asString();
}

std::string Message::to_string() const {
    Json::FastWriter w;
    return w.write(this->raw_resp);
}
