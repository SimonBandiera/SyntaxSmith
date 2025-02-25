cmake_minimum_required(VERSION 3.20)
project(SyntaxSmith VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(includes)

add_library(SyntaxSmith INTERFACE)

target_include_directories(SyntaxSmith INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/includes)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_executable(SyntaxSmithExamples
        example/simpleExamples.cpp)
endif()
