//
// Created by 17186 on 2/22/2023.
//

#include "RespBody.h"

RespBody::RespBody(const Json::Value &resp) {
    this->raw_resp = resp;
}
