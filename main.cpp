#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    auto* graph = new Graph();
    graph->insertVertex(1);
    graph->insertVertex(2);
    graph->insertVertex(3);
    graph->insertVertex(4);
    graph->insertVertex(5);
    graph->insertEdge(1,3,'a');
    graph->insertEdge(1, 5,'b');
    graph->print();
    graph->removeVertex(1);
    graph->insertVertex(1);
    graph->insertEdge(1,2,'c');
    graph->insertEdge(2,5,'d');
    graph->print();
    graph->removeEdge('c');
    graph->insertEdge(3,4,'e');
    graph->print();
    return 0;
}
