cmake_minimum_required(VERSION 3.28)
project(adjacency_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(adjacency_list main.cpp

        Graph.h
        Vertex.h
)
