//
// Created by 17186 on 2/22/2023.
//

#include "GroupRequestEvent.h"

std::string GroupRequestEvent::sub_type() const {
    return this->raw_request["sub_type"].asString();
}

int64_t GroupRequestEvent::group_id() const {
    return this->raw_request["group_id"].asInt64();
}

int64_t GroupRequestEvent::user_id() const {
    return this->raw_request["user_id"].asInt64();
}

std::string GroupRequestEvent::comment() const {
    return this->raw_request["comment"].asString();
}

std::string GroupRequestEvent::flag() const {
    return this->raw_request["flag"].asString();
}
