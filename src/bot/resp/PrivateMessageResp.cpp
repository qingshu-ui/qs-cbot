//
// Created by 17186 on 2/22/2023.
//

#include "PrivateMessageResp.h"

int32_t PrivateMessageResp::message_id() const {
    return this->raw_resp["data"]["message_id"].asInt();
}
