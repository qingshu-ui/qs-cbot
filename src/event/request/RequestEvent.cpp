//
// Created by 17186 on 2/22/2023.
//

#include "RequestEvent.h"

RequestEvent::RequestEvent(const Json::Value &request) {
    this->raw_request = request;
}

int64_t RequestEvent::time() const {
    return this->raw_request["time"].asInt64();
}

int64_t RequestEvent::self_id() const {
    return this->raw_request["self_id"].asInt64();
}

std::string RequestEvent::post_type() const {
    return this->raw_request["post_type"].asString();
}

std::string RequestEvent::request_type() const {
    return this->raw_request["request_type"].asString();
}
