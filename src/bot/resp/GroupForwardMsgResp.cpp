//
// Created by 17186 on 2/22/2023.
//

#include "GroupForwardMsgResp.h"

int64_t GroupForwardMsgResp::message_id() const {
    return this->raw_resp["data"]["message_id"].asInt64();
}

std::string GroupForwardMsgResp::forward_id() const {
    return this->raw_resp["data"]["forward_id"].asString();
}
