cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 23)


project(PipeNetwork)

enable_testing()


add_subdirectory(linalg)
add_subdirectory(lib)


add_executable(PipeNetwork drivers/main.cpp)
target_link_libraries(PipeNetwork PRIVATE PipeNetworkLib)

add_executable(PipeNetworkTest  lib/test/PipeNetworkTest.cpp)
target_link_libraries(PipeNetworkTest PRIVATE PipeNetworkLib)

