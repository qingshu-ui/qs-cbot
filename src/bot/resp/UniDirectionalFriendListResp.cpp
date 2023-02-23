//
// Created by 17186 on 2/22/2023.
//

#include "UniDirectionalFriendListResp.h"

int64_t UniDirectionalFriendListResp::user_id() const {
    return this->raw_resp["data"]["user_id"].asInt64();
}

std::string UniDirectionalFriendListResp::nickname() const {
    return this->raw_resp["data"]["nickname"].asString();
}

std::string UniDirectionalFriendListResp::source() const {
    return this->raw_resp["data"]["source"].asString();
}
