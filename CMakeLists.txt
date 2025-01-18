cmake_minimum_required(VERSION 3.27.9)
project(IdOp)

set(CMAKE_CXX_STANDARD 14)

#include_directories(examples)
include_directories(includes)

#add_custom_target(preprocess
#        COMMAND g++ -E -P
#        -I${CMAKE_CURRENT_SOURCE_DIR}/include
#        -I${Boost_INCLUDE_DIRS}
#        ${CMAKE_CURRENT_SOURCE_DIR}/examples/IdOpExamples.cpp
#        -o IdOpExamples.cpp
#        COMMENT "Generating preprocessed output for IdOpExamples.cpp"
#)

add_executable(SyntaxSmithExamples
        example/simpleExamples.cpp)
