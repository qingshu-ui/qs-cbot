//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_QIDACCOUNTINFO_H
#define CQ_WEBSOCKET_SERVER_QIDACCOUNTINFO_H


#include "RespBody.h"

class QidAccountInfo : public RespBody {
public:
    using RespBody::RespBody;

    int64_t master_id() const;

    std::string ext_name() const;

    int64_t create_time() const;
};


#endif //CQ_WEBSOCKET_SERVER_QIDACCOUNTINFO_H
