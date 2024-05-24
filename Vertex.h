//
// Created by Lee on 23/05/2024.
//

#ifndef ADJACENCY_LIST_VERTEX_H
#define ADJACENCY_LIST_VERTEX_H


class Vertex { //no remove
    int name;
    int in_edges[10];
    int out_edges[10];
    int in_count;
    int out_count;
public:
    Vertex(int name){
        this->name = name;
        in_count = 0;
        out_count = 0;
    }
    int getName(){
        return name;
    }
    int getOutCount(){
        return out_count;
    }
    int getInCount(){
        return in_count;
    }
    int* getInEdges(){
        return in_edges;
    }
    int* getOutEdges(){
        return out_edges;
    }
    void addIncomingEdge(int x){
        if(in_count == 10) return;
        in_edges[in_count++] = x;
    }
    void addOutcomingEdge(int x){
        if(out_count == 10) return;
        out_edges[out_count++] = x;
    }
};


#endif //ADJACENCY_LIST_VERTEX_H
