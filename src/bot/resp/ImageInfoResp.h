//
// Created by 17186 on 2/23/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_IMAGEINFORESP_H
#define CQ_WEBSOCKET_SERVER_IMAGEINFORESP_H


#include "RespBody.h"

class ImageInfoResp : public RespBody {
public:
    using RespBody::RespBody;

    int32_t size() const;

    std::string filename() const;

    std::string url() const;
};


#endif //CQ_WEBSOCKET_SERVER_IMAGEINFORESP_H
