//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_ACTIONS_H
#define CQ_WEBSOCKET_SERVER_ACTIONS_H

#include <iostream>

namespace Action {
    // 发送私聊消息
    extern const std::string SEND_PRIVATE_MSG;
    // 发送群消息
    extern const std::string SEND_GROUP_MSG;
    // 发送合并转发 ( 群 )
    extern const std::string SEND_GROUP_FORWARD_MSG;
    // 发送消息
    extern const std::string SEND_MSG;
    // 撤回消息
    extern const std::string DELETE_MSG;
    // 获取消息
    extern const std::string GET_MSG;
    // 获取合并转发内容
    extern const std::string GET_FORWARD_MSG;
    // 获取图片信息
    extern const std::string GET_IMAGE;
    // 标记消息已读
    extern const std::string MARK_MSG_AS_READ;
    // 群组踢人
    extern const std::string SET_GROUP_KICK;
    // 群组单人禁言
    extern const std::string SET_GROUP_BAN;
    // 群组匿名用户禁言
    extern const std::string SET_GROUP_ANONYMOUS_BAN;
    // 群组全员禁言
    extern const std::string SET_GROUP_WHOLE_BAN;
    // 群组设置管理员
    extern const std::string SET_GROUP_ADMIN;
    // 群组匿名
    extern const std::string SET_GROUP_ANONYMOUS;
    // 设置群名片 ( 群备注 )
    extern const std::string SET_GROUP_CARD;
    // 设置群名
    extern const std::string SET_GROUP_NAME;
    // 退出群组
    extern const std::string SET_GROUP_LEAVE;
    // 设置群组专属头衔
    extern const std::string SET_GROUP_SPECIAL_TITLE;
    // 群打卡
    extern const std::string SEND_GROUP_SIGN;
    // 处理加好友请求
    extern const std::string SET_FRIEND_ADD_REQUEST;
    // 处理加群请求／邀请
    extern const std::string SET_GROUP_ADD_REQUEST;
    // 获取登录号信息
    extern const std::string GET_LOGIN_INFO;
    // 获取企点账号信息
    extern const std::string QIDIAN_GET_ACCOUNT_INFO;
    // 设置登录号资料
    extern const std::string SET_QQ_PROFILE;
    // 获取陌生人信息
    extern const std::string GET_STRANGER_INFO;
    // 获取好友列表
    extern const std::string GET_FRIEND_LIST;
    // 获取单向好友列表
    extern const std::string GET_UNIDIRECTIONAL_FIREND_LIST;
    // 删除好友
    extern const std::string DELETE_FRIEND;
    // 获取群信息
    extern const std::string GET_GROUP_INFO;
    // 获取群列表
    extern const std::string GET_GROUP_LIST;
    // 获取群成员信息
    extern const std::string GET_GROUP_MEMBER_INFO;
    // 获取群成员列表
    extern const std::string GET_GROUP_MEMBER_LIST;
    // 获取群荣誉信息
    extern const std::string GET_GROUP_HONOR_INFO;
    // 获取 Cookies
    extern const std::string GET_COOKIES;
    // 获取 CSRF Token
    extern const std::string GET_CRSF_TOKEN;
    // 获取 QQ 相关接口凭证
    extern const std::string GET_CREDENTIALS;
    // 获取语音
    extern const std::string GET_RECORD;
    // 检查是否可以发送图片
    extern const std::string CAN_SEND_IMAGE;
    // 检查是否可以发送语音
    extern const std::string CAN_SEND_RECORD;
    // 获取版本信息
    extern const std::string GET_VERSION_INFO;
    // 重启 go-cqhttp
    extern const std::string SET_RESTART;
    // 清理缓存
    extern const std::string CLEAN_CACHE;
    // 设置群头像
    extern const std::string SET_GROUP_PORTRAIT;
    // 获取中文分词 ( 隐藏 API )
    extern const std::string _GET_WORD_SLICES;
    // 图片 OCR
    extern const std::string OCR_IMAGE;
    // 获取群系统消息
    extern const std::string GET_GROUP_SYSTEM_MSG;
    // 上传私聊文件
    extern const std::string UPLOAD_PRIVATE_FILE;
    // 上传群文件
    extern const std::string UPLOAD_GROUP_FILE;
    // 获取群文件系统信息
    extern const std::string GET_GROUP_FILE_SYSTEM_INFO;
    // 获取群根目录文件列表
    extern const std::string GET_GROUP_ROOT_FILES;
    // 获取群子目录文件列表
    extern const std::string GET_GROUP_FILES_BY_FOLDER;
    // 创建群文件文件夹
    extern const std::string CREATE_GROUP_FILE_FOLDER;
    // 删除群文件文件夹
    extern const std::string DELETE_GROUP_FOLDER;
    // 删除群文件
    extern const std::string DELETE_GROUP_FILE;
    // 获取群文件资源链接
    extern const std::string GET_GROUP_FILE_URL;
    // 获取状态
    extern const std::string GET_STATUS;
    // 获取群 @全体成员 剩余次数
    extern const std::string GET_GROUP_AT_ALL_REMAIN;
    // 对事件执行快速操作 ( 隐藏 API )
    extern const std::string _HANDLE_QUICK_OPERATION;
    // 发送群公告
    extern const std::string _SEND_GROUP_NOTICE;
    // 获取群公告
    extern const std::string _GET_GROUP_NOTICE;
    // 重载事件过滤器
    extern const std::string RELOAD_EVENT_FILTER;
    // 下载文件到缓存目录
    extern const std::string DOWNLOAD_FILE;
    // 获取当前账号在线客户端列表
    extern const std::string GET_ONLINE_CLIENTS;
    // 获取群消息历史记录
    extern const std::string GET_GROUP_MSG_HISTORY;
    // 设置精华消息
    extern const std::string SET_ESSENCE_MSG;
    // 移出精华消息
    extern const std::string DELETE_ESSENCE_MSG;
    // 获取精华消息列表
    extern const std::string GET_ESSENCE_MSG_LIST;
    // 检查链接安全性
    extern const std::string CHECK_URL_SAFELY;
    // 获取在线机型
    extern const std::string _GET_MODEL_SHOW;
    // 设置在线机型
    extern const std::string _SET_MODEL_SHOW;
    // 删除单向好友
    extern const std::string DELETE_UNIDIRECTIONAL_FRIEND;
    // 发送合并转发 ( 好友 )
    extern const std::string SEND_PRIVATE_FORWARD_MSG;
}

#endif //CQ_WEBSOCKET_SERVER_ACTIONS_H
