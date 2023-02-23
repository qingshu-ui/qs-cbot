//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_REQUESTEVENT_H
#define CQ_WEBSOCKET_SERVER_REQUESTEVENT_H

#include <json/json.h>

class RequestEvent {
public:
    Json::Value raw_request;

    RequestEvent(const Json::Value &request);

    virtual int64_t time() const;

    virtual int64_t self_id() const;

    virtual std::string post_type() const;

    virtual std::string request_type() const;

};


#endif //CQ_WEBSOCKET_SERVER_REQUESTEVENT_H
