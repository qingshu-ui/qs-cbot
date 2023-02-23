//
// Created by 17186 on 2/22/2023.
//

#include "GroupInfoResp.h"

int64_t GroupInfoResp::group_id() const {
    return this->raw_resp["data"]["group_id"].asInt64();
}

std::string GroupInfoResp::group_name() const {
    return this->raw_resp["data"]["group_name"].asString();
}

std::string GroupInfoResp::group_memo() const {
    return this->raw_resp["data"]["group_memo"].asString();
}

uint32_t GroupInfoResp::group_create_time() const {
    return this->raw_resp["data"]["group_create_time"].asUInt();
}

uint32_t GroupInfoResp::group_level() const {
    return this->raw_resp["data"]["group_level"].asUInt();
}

int32_t GroupInfoResp::member_count() const {
    return this->raw_resp["data"]["member_count"].asInt();
}

int32_t GroupInfoResp::max_member_count() const {
    return this->raw_resp["data"]["max_member_count"].asInt();
}
