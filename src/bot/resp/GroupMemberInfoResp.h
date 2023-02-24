//
// Created by 17186 on 2/23/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_GROUPMEMBERINFORESP_H
#define CQ_WEBSOCKET_SERVER_GROUPMEMBERINFORESP_H


#include "RespBody.h"

class GroupMemberInfoResp : public RespBody {
public:
    using RespBody::RespBody;

    int64_t group_id() const;

    int64_t user_id() const;

    std::string nickname() const;

    std::string card() const;

    std::string sex() const;

    int32_t age() const;

    std::string area() const;

    int32_t join_time() const;

    int32_t last_sent_time() const;

    std::string level() const;

    std::string role() const;

    bool unfriendly() const;

    std::string title() const;

    int64_t title_expire_time() const;

    bool card_changeable() const;

    int64_t shut_up_timestamp() const;

};


#endif //CQ_WEBSOCKET_SERVER_GROUPMEMBERINFORESP_H
