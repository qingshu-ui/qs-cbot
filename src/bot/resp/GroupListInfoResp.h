//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_GROUPLISTINFORESP_H
#define CQ_WEBSOCKET_SERVER_GROUPLISTINFORESP_H


#include "RespBody.h"
#include "GroupInfoResp.h"

class GroupListInfoResp: public RespBody{
public:
    using RespBody::RespBody;

    GroupInfoResp get_group_info(const int32_t& index);

    int32_t size();
};


#endif //CQ_WEBSOCKET_SERVER_GROUPLISTINFORESP_H
