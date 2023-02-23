//
// Created by 17186 on 2/22/2023.
//

#include "MessageResp.h"

int32_t MessageResp::message_id() const {
    return this->raw_resp["data"]["message_id"].asInt();
}
