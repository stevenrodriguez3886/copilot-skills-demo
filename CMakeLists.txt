cmake_minimum_required(VERSION 3.16)
project(TelemetryDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(telemetry_core STATIC
    src/packet_processor.cpp
)