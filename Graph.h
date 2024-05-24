//
// Created by Lee on 23/05/2024.
//
#include<iostream>
#include"Vertex.h"
#include "Edge.h"

#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H
using namespace std;

class Graph {
   Vertex** vertices;
   int numOfVertices;
   Edge** edges;
   int numOfEdges;
public:
    Graph(){
        numOfVertices = 0;
        vertices = new Vertex*[10];
        for(int i=0;i<10;i++){
            vertices[i] = nullptr;
        }
        edges = new Edge*[10];
        numOfEdges = 0;
    }
    int numEdges(){
        return numOfEdges;
    }
    int numVertices(){
        return numOfVertices;
    }
    char getEdge(int u, int v){
        for(int i=0;i<numOfEdges;i++){
            if((edges[i]->v1 == u && edges[i]->v2 == v) ||(edges[i]->v1 == v && edges[i]->v2 == u)){
                return edges[i]->name;
            }
        }
        return '\0';
    }
    int outDegree(int v){
        Vertex* vertex;
        for(int i=0;i<numOfVertices;i++){
            if(vertices[i]->element == v){
                vertex = vertices[i];
            }
        }
        if(vertex){
            return vertex->list_size;
        }
        return 0;
    }
    int inDegree(int v){
        return outDegree(v); //undirected graph
    }
    void insertVertex(int v){
        if(numOfVertices<10){
            vertices[numOfVertices++] = new Vertex(v);
        }
    }
    void insertEdge(int u,int v, char x){
        if(numOfEdges == 10){
            return; //full
        }
        int count = 0; //must be 2 to be successful, assuming there are no duplicate vertices
        for(int i=0;i<numOfVertices;i++){
            if(vertices[i]->element == u){
                vertices[i]->addNode(v);
                count++;
            }
            if(vertices[i]->element == v){
                vertices[i]->addNode(u);
                count++;
            }
        }
        if(count == 2){
            edges[numOfEdges++] = new Edge(u,v,x);
        } else{
            return;
        }
    }
    void removeVertex(int v){
        int idx = -1;
        Vertex* deleteThis;
        for(int i=0;i<numOfVertices;i++){
            if(vertices[i]->element == v){
                idx = i;
                deleteThis = vertices[i];
                break;
            }
        }
        if(idx == -1) return; //wa nakit-an
        for(int i=idx;i<numOfVertices-1;i++){
            vertices[i] = vertices[i+1];
        }
        delete deleteThis;
        numOfVertices--;
        Edge* deleteThisEdge;
        int edgeIdx = -1;
        for(int i=0;i<numOfEdges;i++){
            if(edges[i]->v1 == v|| edges[i]->v2 == v){
                deleteThisEdge = edges[i];
                delete deleteThisEdge;
                for(int j=i;j<numOfEdges;j++){
                    edges[j] = edges[j+1];
                }
                numOfEdges--;
                i--;
            }
        }
        for(int i=0;i<numOfVertices;i++){
            for(int j=0;j<vertices[i]->list_size;j++){
                if(vertices[i]->adjacency_list[j] == v){
                    vertices[i]->removeNode(v);
                }
            }
        }
    }
    void removeEdge(char e){
        Edge* toRemove = nullptr;
        int idx = -1;
        for(int i=0;i<numOfEdges;i++){
            if(edges[i]->name == e){
                toRemove = edges[i];
                break;
            }
        }
        if(!toRemove) return; //wa nakita
        for(int i=0;i<numOfVertices;i++){
            if(vertices[i]->element == toRemove->v1){
                vertices[i]->removeNode(toRemove->v2);
            } else if(vertices[i]->element == toRemove->v2){
                vertices[i]->removeNode(toRemove->v1);
            }
        }
        for(int i=idx;i<numOfEdges-1;i++){
            edges[i] = edges[i+1];
        }
        numOfEdges--;
    }
    void print(){
        cout << "Edges: ";
        for(int i=0;i<numOfEdges;i++){
            cout << edges[i]->name << " ";
        }
        cout << endl;
        cout << "Vertices (Adjacency List): " << endl;
        for(int i=0;i<numOfVertices;i++){
            cout << vertices[i]->element << " -> ";
            for(int j=0;j<vertices[i]->list_size;j++){
                if(vertices[i]->adjacency_list[j]){
                    cout << vertices[i]->adjacency_list[j] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};


#endif //ADJACENCY_LIST_GRAPH_H
