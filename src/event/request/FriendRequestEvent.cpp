//
// Created by 17186 on 2/22/2023.
//

#include "FriendRequestEvent.h"

int64_t FriendRequestEvent::user_id() const {
    return this->raw_request["user_id"].asInt64();
}

std::string FriendRequestEvent::comment() const {
    return this->raw_request["comment"].asString();
}

std::string FriendRequestEvent::flag() const {
    return this->raw_request["flag"].asString();
}
