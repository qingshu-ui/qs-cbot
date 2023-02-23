//
// Created by 17186 on 2/23/2023.
//

#include "ForwardMessageResp.h"

Json::Value ForwardMessageResp::messages() const {
    return this->raw_resp["data"]["messages"];
}
