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
    void removeNode(int num){
        int idx = -1;
        for(int i=0;i<list_size;i++){
            if(adjacency_list[i] == num){
                idx = i;
            }
        }
        if(idx == -1) return; //wa nakit-an
        for(int i=idx;i<list_size-1;i++){
            adjacency_list[i] = adjacency_list[i+1];
        }
        list_size--;
    }

};


#endif //ADJACENCY_LIST_VERTEX_H
