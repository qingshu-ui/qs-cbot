//
// Created by 17186 on 2/22/2023.
//

#include "FriendListResp.h"

int64_t Friend::user_id() const {
    return this->raw_friend["user_id"].asInt64();
}

std::string Friend::nickname() const {
    return this->raw_friend["nickname"].asString();
}

std::string Friend::remark() const {
    return this->raw_friend["remark"].asString();
}

Friend FriendListResp::get_friend(const int32_t &index) const {
    if (index < this->size() && index >= 0) {
        return {this->raw_resp["data"][index]};
    }
    return {};
}

int32_t FriendListResp::size() const {
    return this->raw_resp["data"].size();
}
