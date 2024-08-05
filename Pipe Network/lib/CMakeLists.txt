cmake_minimum_required(VERSION 3.27)



add_library(PipeNetworkLib
            src/Node.cpp 
            src/PipeNetwork.cpp 
            src/Tube.cpp 
            )

target_link_libraries(PipeNetworkLib PUBLIC linalg)   
target_include_directories(PipeNetworkLib PUBLIC include)



