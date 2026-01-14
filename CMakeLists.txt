cmake_minimum_required(VERSION 3.10)
project(can_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(can_tx
    main_tx.cpp
    src/can/CanDriver.cpp
)

add_executable(can_rx
    main_rx.cpp
    src/can/CanDriver.cpp
)