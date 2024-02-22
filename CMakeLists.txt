cmake_minimum_required(VERSION 3.26)
project(flower-exchange-c)

set(CMAKE_CXX_STANDARD 14)

include_directories(flower-exchange-c)

add_executable(flowers-exchange-c
        ExecReport.cpp
        ExecReport.h
        Order.cpp
        Order.h
        OrderBook.cpp
        OrderBook.h
        fileService.h
        fileService.cpp
        main.cpp)