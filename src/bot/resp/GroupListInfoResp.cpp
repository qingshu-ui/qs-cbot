//
// Created by 17186 on 2/22/2023.
//

#include "GroupListInfoResp.h"

GroupInfoResp GroupListInfoResp::get_group_info(const int32_t &index) {
    if (index < this->size() && index >= 0) {
        return {this->raw_resp["data"][index]};
    }
    return {this->raw_resp["data"][this->size() - 1]};
}

int32_t GroupListInfoResp::size() {
    return this->raw_resp["data"].size();
}
