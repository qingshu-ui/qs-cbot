//
// Created by 17186 on 2/23/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_FORWARDMESSAGERESP_H
#define CQ_WEBSOCKET_SERVER_FORWARDMESSAGERESP_H


#include "RespBody.h"

class ForwardMessageResp : public RespBody {
public:
    using RespBody::RespBody;

    Json::Value messages() const;
};


#endif //CQ_WEBSOCKET_SERVER_FORWARDMESSAGERESP_H
