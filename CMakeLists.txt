cmake_minimum_required(VERSION 3.31)
project(ComputePipelineTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ComputePipelineTest Source/SimplePipelineTest.cpp)

add_subdirectory(ComputePipeline)
target_link_libraries(ComputePipelineTest PUBLIC ComputePipeline)
target_include_directories(ComputePipelineTest PUBLIC ComputePipeline/Include)
