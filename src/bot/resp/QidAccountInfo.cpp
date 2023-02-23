//
// Created by 17186 on 2/22/2023.
//

#include "QidAccountInfo.h"

int64_t QidAccountInfo::master_id() const {
    return this->raw_resp["data"]["master_id"].asInt64();
}

std::string QidAccountInfo::ext_name() const {
    return this->raw_resp["data"]["ext_name"].asString();
}

int64_t QidAccountInfo::create_time() const {
    return this->raw_resp["data"]["create_time"].asInt64();
}
