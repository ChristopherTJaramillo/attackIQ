cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(attackIQ LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.54 REQUIRED COMPONENTS filesystem)

add_executable(attackIQ main.cpp)

target_link_libraries(attackIQ
        PUBLIC
        Boost::filesystem)
