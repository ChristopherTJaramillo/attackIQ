cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(attackIQ LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.54 REQUIRED COMPONENTS filesystem)

add_library(aiq-grpc
        STATIC
        generated/aiq_server.grpc.pb.h
        generated/aiq_server.grpc.pb.cc
        generated/aiq_server.pb.h
        generated/aiq_server.pb.cc)

target_include_directories(aiq-grpc PRIVATE "$ENV{GRPC_HOME}/include")
target_include_directories(aiq-grpc PRIVATE "$ENV{GRPC_HOME}/third_party/protobuf/src")

add_library(aiq-translation-server
        SHARED
        AiqTranslationServer.h
        AiqTranslationServer.cpp)

target_include_directories(aiq-translation-server PRIVATE "$ENV{GRPC_HOME}/include")
target_include_directories(aiq-translation-server PRIVATE "$ENV{GRPC_HOME}/third_party/protobuf/src")

target_link_directories(aiq-translation-server PUBLIC "$ENV{GRPC_HOME}/libs/opt")
target_link_directories(aiq-translation-server PUBLIC "$ENV{GRPC_HOME}/libs/opt/protobuf")

target_link_libraries(aiq-translation-server
        PUBLIC
        aiq-grpc)

target_link_libraries(aiq-translation-server
        PUBLIC
        protobuf
        grpc++
        grpc++_reflection
        dl)

add_executable(attackIQ main.cpp)

target_include_directories(attackIQ PRIVATE "$ENV{GRPC_HOME}/include")
target_include_directories(attackIQ PRIVATE "$ENV{GRPC_HOME}/third_party/protobuf/src")

target_link_libraries(attackIQ
        PUBLIC
        Boost::filesystem)

target_link_libraries(attackIQ
        PUBLIC
        aiq-translation-server)