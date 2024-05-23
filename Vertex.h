//
// Created by Lee on 23/05/2024.
//

#ifndef ADJACENCY_LIST_VERTEX_H
#define ADJACENCY_LIST_VERTEX_H


class Vertex {
public:
    int element;
    int* adjacency_list;
    int list_size;
    Vertex(){
        element = -1;
        adjacency_list = new int[10];
        list_size = 0;
    }
    Vertex(int element){
        this->element = element;
        adjacency_list = new int[10];
        list_size = 0;
    }
    void addNode(int node){
        if(list_size < 10){
            adjacency_list[list_size++] = node;
        }
    }

};


#endif //ADJACENCY_LIST_VERTEX_H
