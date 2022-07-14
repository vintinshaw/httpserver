cmake_minimum_required(VERSION 3.22)
project(httpserver)

set(CMAKE_CXX_STANDARD 17)

add_executable(httpserver main.cpp common/mongoose.c common/mongoose.h httpserver/http_server.cpp httpserver/http_server.h httpserver/handler.cpp httpserver/handler.h)
