cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(attackIQ LANGUAGES CXX)

find_package(Boost 1.69 REQUIRED COMPONENTS filesystem)

add_executable(attackIQ main.cpp)

target_link_libraries(attackIQ
        PUBLIC
        Boost::filesystem)