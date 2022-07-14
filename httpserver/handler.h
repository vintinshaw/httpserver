//
// Created by OaixNait on 2022/7/14.
//

#ifndef HTTPSERVER_HANDLER_H
#define HTTPSERVER_HANDLER_H


#include <string>
#include "../common/mongoose.h"
#include "http_server.h"

std::string test(const std::string &url, const std::string &body, mg_connection *c, OnRspCallback rsp_callback);


#endif //HTTPSERVER_HANDLER_H
