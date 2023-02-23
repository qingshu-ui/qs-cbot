//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_GROUPFORWARDMSGRESP_H
#define CQ_WEBSOCKET_SERVER_GROUPFORWARDMSGRESP_H


#include "RespBody.h"

class GroupForwardMsgResp : public RespBody {
public:
    using RespBody::RespBody;

    int64_t message_id() const;

    std::string forward_id() const;
};


#endif //CQ_WEBSOCKET_SERVER_GROUPFORWARDMSGRESP_H
