//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_PRIVATEMESSAGERESP_H
#define CQ_WEBSOCKET_SERVER_PRIVATEMESSAGERESP_H


#include "json/value.h"
#include "RespBody.h"

class PrivateMessageResp : public RespBody {
public:
    using RespBody::RespBody;

    int32_t message_id() const;
};


#endif //CQ_WEBSOCKET_SERVER_PRIVATEMESSAGERESP_H
