//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_RESPBODY_H
#define CQ_WEBSOCKET_SERVER_RESPBODY_H

#include <json/json.h>
#include <json/value.h>

class RespBody {
public:
    Json::Value raw_resp;

    RespBody(const Json::Value &resp);

};


#endif //CQ_WEBSOCKET_SERVER_RESPBODY_H
