//
// Created by 17186 on 2/23/2023.
//

#include "GroupMemberInfoResp.h"

int64_t GroupMemberInfoResp::group_id() const {
    return this->raw_resp["data"]["group_id"].asInt64();
}

int64_t GroupMemberInfoResp::user_id() const {
    return this->raw_resp["data"]["user_id"].asInt64();
}

std::string GroupMemberInfoResp::nickname() const {
    return this->raw_resp["data"]["nickname"].asString();
}

std::string GroupMemberInfoResp::card() const {
    return this->raw_resp["data"]["card"].asString();
}

std::string GroupMemberInfoResp::sex() const {
    return this->raw_resp["data"]["sex"].asString();
}

int32_t GroupMemberInfoResp::age() const {
    return this->raw_resp["data"]["age"].asInt();
}

std::string GroupMemberInfoResp::area() const {
    return this->raw_resp["data"]["area"].asString();
}

int32_t GroupMemberInfoResp::join_time() const {
    return this->raw_resp["data"]["join_time"].asInt();
}

int32_t GroupMemberInfoResp::last_sent_time() const {
    return this->raw_resp["data"]["last_sent_time"].asInt();
}

std::string GroupMemberInfoResp::level() const {
    return this->raw_resp["data"]["level"].asString();
}

std::string GroupMemberInfoResp::role() const {
    return this->raw_resp["data"]["role"].asString();
}

bool GroupMemberInfoResp::unfriendly() const {
    return this->raw_resp["data"]["unfriendly"].asBool();
}

std::string GroupMemberInfoResp::title() const {
    return this->raw_resp["data"]["title"].asString();
}

int64_t GroupMemberInfoResp::title_expire_time() const {
    return this->raw_resp["data"]["title_expire_time"].asInt64();
}

bool GroupMemberInfoResp::card_changeable() const {
    return this->raw_resp["data"]["card_changeable"].asBool();
}

int64_t GroupMemberInfoResp::shut_up_timestamp() const {
    return this->raw_resp["data"]["shut_up_timestamp"].asInt64();
}
