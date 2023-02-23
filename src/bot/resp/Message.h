//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_MESSAGE_H
#define CQ_WEBSOCKET_SERVER_MESSAGE_H


#include "RespBody.h"
#include "../../event/message/MessageEvent.h"

class Message : public RespBody {

public:
    using RespBody::RespBody;

    bool group() const;

    int64_t group_id() const;

    int32_t message_id() const;

    int32_t real_id() const;

    std::string message_type() const;

    Sender sender() const;

    int32_t time() const;

    std::string message() const;

    std::string to_string() const;
};


#endif //CQ_WEBSOCKET_SERVER_MESSAGE_H
