//
// Created by 17186 on 2/23/2023.
//

#include "ImageInfoResp.h"

int32_t ImageInfoResp::size() const {
    return this->raw_resp["data"]["size"].asInt();
}

std::string ImageInfoResp::filename() const {
    return this->raw_resp["data"]["filename"].asString();
}

std::string ImageInfoResp::url() const {
    return this->raw_resp["data"]["url"].asString();
}
