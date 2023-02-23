//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_GROUPINFORESP_H
#define CQ_WEBSOCKET_SERVER_GROUPINFORESP_H


#include "RespBody.h"

class GroupInfoResp : public RespBody {
public:
    using RespBody::RespBody;

    int64_t group_id() const;

    std::string group_name() const;

    std::string group_memo() const;

    uint32_t group_create_time() const;

    uint32_t group_level() const;

    int32_t member_count() const;

    int32_t max_member_count() const;
};


#endif //CQ_WEBSOCKET_SERVER_GROUPINFORESP_H
