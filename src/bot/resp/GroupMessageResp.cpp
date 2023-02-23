//
// Created by 17186 on 2/22/2023.
//

#include "GroupMessageResp.h"

int32_t GroupMessageResp::message_id() const {
    return this->raw_resp["data"]["message_id"].asInt();
}
