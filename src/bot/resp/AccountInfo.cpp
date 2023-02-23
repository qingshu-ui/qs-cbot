//
// Created by 17186 on 2/22/2023.
//

#include "AccountInfo.h"

int64_t AccountInfo::user_id() const {
    return this->raw_resp["data"]["user_id"].asInt64();
}

std::string AccountInfo::nickname() const {
    return this->raw_resp["data"]["nickname"].asString();
}
