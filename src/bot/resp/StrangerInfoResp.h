//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_STRANGERINFORESP_H
#define CQ_WEBSOCKET_SERVER_STRANGERINFORESP_H


#include "RespBody.h"

class StrangerInfoResp : public RespBody {
public:
    using RespBody::RespBody;

    int64_t user_id() const;

    std::string nickname() const;

    std::string sex() const;

    int32_t age() const;

    std::string qid() const;

    int32_t level() const;

    int32_t login_days() const;
};


#endif //CQ_WEBSOCKET_SERVER_STRANGERINFORESP_H
