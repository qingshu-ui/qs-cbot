//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_MESSAGERESP_H
#define CQ_WEBSOCKET_SERVER_MESSAGERESP_H


#include "RespBody.h"

class MessageResp : public RespBody {
public:
    using RespBody::RespBody;

    int32_t message_id() const;
};


#endif //CQ_WEBSOCKET_SERVER_MESSAGERESP_H
