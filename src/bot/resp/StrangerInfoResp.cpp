//
// Created by 17186 on 2/22/2023.
//

#include "StrangerInfoResp.h"

int64_t StrangerInfoResp::user_id() const {
    return this->raw_resp["data"]["user_id"].asInt64();
}

std::string StrangerInfoResp::nickname() const {
    return this->raw_resp["data"]["nickname"].asString();
}

std::string StrangerInfoResp::sex() const {
    return this->raw_resp["data"]["sex"].asString();
}

int32_t StrangerInfoResp::age() const {
    return this->raw_resp["data"]["age"].asInt();
}

std::string StrangerInfoResp::qid() const {
    return this->raw_resp["data"]["qid"].asString();
}

int32_t StrangerInfoResp::level() const {
    return this->raw_resp["data"]["level"].asInt();
}

int32_t StrangerInfoResp::login_days() const {
    return this->raw_resp["data"]["login_days"].asInt();
}
