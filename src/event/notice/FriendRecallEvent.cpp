//
// Created by 17186 on 2/22/2023.
//

#include "FriendRecallEvent.h"

int64_t FriendRecallEvent::user_id() const {
    return this->raw_notice["user_id"].asInt64();
}

int64_t FriendRecallEvent::message_id() const {
    return this->raw_notice["message_id"].asInt64();
}
