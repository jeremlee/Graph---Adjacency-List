//
// Created by Lee on 23/05/2024.
//

#ifndef ADJACENCY_LIST_EDGE_H
#define ADJACENCY_LIST_EDGE_H


class Edge {
public:
    int v1;
    int v2;
    char name;
    Edge(int v1, int v2, char name){
        this->v1 = v1;
        this->v2 = v2;
        this->name = name;
    }
};


#endif //ADJACENCY_LIST_EDGE_H
