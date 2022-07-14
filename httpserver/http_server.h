//
// Created by OaixNait on 2022/7/6.
//

#ifndef HTTPSERVER_HTTP_SERVER_H
#define HTTPSERVER_HTTP_SERVER_H
#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include "../common/mongoose.h"

// 定义http返回callback
typedef void OnRspCallback(mg_connection *c, const std::string &);
// 定义http请求handler
using ReqHandler = std::function<std::string(const std::string &, const std::string &, mg_connection *c,
                                             OnRspCallback)>;

class HttpServer {
public:
    HttpServer() {}

    ~HttpServer() = default;

    void Init(const std::string &port); // 初始化设置
    [[noreturn]] bool Start(); // 启动httpserver
    bool Close(); // 关闭
    static void AddHandler(const std::string &url, const ReqHandler &req_handler); // 注册事件处理函数
    static void RemoveHandler(const std::string &url); // 移除时间处理函数
    static std::string s_web_dir; // 网页根目录
    static mg_http_serve_opts s_server_option; // web服务器选项
    static std::unordered_map<std::string, ReqHandler> s_handler_map; // 回调函数映射表
    static const char *s_debug_level;
private:
    // 静态事件响应函数
//    新版本中多了一个参数
    static void OnHttpWebsocketEvent(mg_connection *connection, int event_type, void *event_data, void *fn_data);

    static void HandleHttpEvent(mg_connection *connection, mg_http_message *http_req);

    static void SendHttpRsp(mg_connection *connection, const std::string &rsp);

    static int isWebsocket(const mg_connection *connection); // 判断是否是websoket类型连接
    static void HandleWebsocketMessage(mg_connection *connection, int event_type, mg_ws_message *ws_msg);

    static void SendWebsocketMsg(mg_connection *connection, const std::string &msg); // 发送消息到指定连接
    static void BroadcastWebsocketMsg(const std::string &msg); // 给所有连接广播消息
    static std::unordered_set<mg_connection *> s_websocket_session_set; // 缓存websocket连接

    std::string m_port;    // 端口
    mg_mgr m_mgr;          // 连接管理器
};


#endif //HTTPSERVER_HTTP_SERVER_H
