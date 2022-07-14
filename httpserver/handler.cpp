//
// Created by OaixNait on 2022/7/14.
//
#include "handler.h"

std::string test(const std::string &url, const std::string &body, mg_connection *c, OnRspCallback rsp_callback) {
    auto s = R"({"name":"James","nickname":"goodboy"})";
    rsp_callback(c, s);
    return s;
}

#include "handler.h"
