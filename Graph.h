//
// Created by Lee on 23/05/2024.
//
#include<iostream>
#include"Vertex.h"

#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H
using namespace std;

class Graph {
   Vertex** s_vertices;
   int num_vert;
   int s_edges[10];
   int num_edge;
public:
    Graph(){
        num_vert = 0;
        num_edge = 0;
        s_vertices = new Vertex*[10];
        for(int i=0;i<10;i++){
            s_vertices[i] = nullptr;
        }
    }
    int* edges(){
        return s_edges;
    }
    int* vertices(){
        int* arr = new int[num_vert];
        for(int i=0;i<num_vert;i++){
            arr[i] = s_vertices[i]->getName();
        }
        return arr;
    }
    int numEdges(){
        return num_edge;
    }
    int numVertices(){
        return num_vert;
    }
    int outDegree(int v){
        for(int i=0;i<num_vert;i++){
            if(s_vertices[i]->getName() == v){
                return s_vertices[i]->getOutCount();
            }
        }
        return -1;
    }
    int inDegree(int v){
        for(int i=0;i<num_vert;i++){
            if(s_vertices[i]->getName() == v){
                return s_vertices[i]->getInCount();
            }
        }
        return -1;
    }
    int* outgoingEdges(int v){
        for(int i=0;i<num_vert;i++){
            if(s_vertices[i]->getName() == v){
                return s_vertices[i]->getOutEdges();
            }
        }
        return nullptr;
    }
    int* incomingEdges(int v){
        for(int i=0;i<num_vert;i++){
            if(s_vertices[i]->getName() == v){
                return s_vertices[i]->getInEdges();
            }
        }
        return nullptr;
    }
    int getEdge(int u, int v){
        Vertex* uu = nullptr;
        Vertex* vv = nullptr;
        for(int i=0;i<num_vert;i++){
            if(s_vertices[i]->getName() == u){
                uu = s_vertices[i];
            }
            if(s_vertices[i]->getName() == v){
                vv = s_vertices[i];
            }
        }
        if(!uu || !vv) return -1;
        int* out = uu->getOutEdges();
        int* in = vv->getInEdges();
        for(int i=0;i<uu->getOutCount();i++){
            for(int j=0;j<vv->getInCount();j++){
                if(out[i] == in[j]){
                    return out[i];
                }
            }
        }
        return -1;
    }
    int* endVertices(int e){
        int* end = new int[2];
        end[0] = -1;
        end[1] = -1;
        int* in;
        int* out;
        for(int i=0;i<num_vert;i++){
            out = s_vertices[i]->getOutEdges();
            in = s_vertices[i]->getInEdges();
            for(int j=0;j<s_vertices[i]->getOutCount();j++){
                if(out[j] == e){
                    end[0] = s_vertices[i]->getName();
                }
            }
            for(int j=0;j<s_vertices[i]->getInCount();j++){
                if(in[j] == e){
                    end[1] = s_vertices[i]->getName();
                }
            }
        }
        return end;
    }

    int opposite(int v, int e){
        int vIdx = -1;
        int* in;
        int* out;
        for(int i=0;i<num_vert;i++){
            if(s_vertices[i]->getName() == v){
                vIdx = i;
                break;
            }
        }
        for(int i=0;i<num_vert;i++){
            if(i == vIdx) continue;
            out = s_vertices[i]->getOutEdges();
            in = s_vertices[i]->getInEdges();
            for(int j=0;j<s_vertices[i]->getOutCount();j++){
                if(out[j] == e){
                    return s_vertices[i]->getName();
                }
            }
            for(int j=0;j<s_vertices[i]->getInCount();j++){
                if(in[j] == e){
                    return s_vertices[i]->getName();
                }
            }
        }
        return -1;
    }

    void insertVertex(int x){
        if(num_vert == 10) return;
        s_vertices[num_vert++] = new Vertex(x);
    }
    void insertEdge(int u, int v, int x){
        if(num_edge == 10) return;
        Vertex* uu = nullptr;
        Vertex* vv = nullptr;
        for(int i=0;i<num_vert;i++){
            if(s_vertices[i]->getName() == u){
                uu = s_vertices[i];
            }
            if(s_vertices[i]->getName() == v){
                vv = s_vertices[i];
            }
        }
        if(!uu || !vv) return;
        uu->addOutcomingEdge(x);
        vv->addIncomingEdge(x);
        s_edges[num_edge++] = x;
    }
    void print(){
        for(int i=0;i<num_vert;i++){
            cout << "Vertex " << s_vertices[i]->getName() << " ";
            cout << " | Incoming: ";
            int* in = s_vertices[i]->getInEdges();
            for(int j=0;j<s_vertices[i]->getInCount();j++){
                cout << in[j] << " ";
            }
            cout << " | ";
            cout << "Outcoming: ";
            int* out = s_vertices[i]->getOutEdges();
            for(int j=0;j<s_vertices[i]->getOutCount();j++){
                cout << out[j] << " ";
            }
            cout << endl;
        }
    }
};


#endif //ADJACENCY_LIST_GRAPH_H
