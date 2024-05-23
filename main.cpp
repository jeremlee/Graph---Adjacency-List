#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph* graph = new Graph();
    graph->insertVertex(1);
    graph->insertVertex(2);
    graph->insertVertex(3);
    graph->insertVertex(4);
    graph->insertVertex(5);
    graph->insertEdge(1,3,'a');
    graph->insertEdge(1, 5,'b');
    graph->print();
    return 0;
}
