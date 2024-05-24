#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    auto* graph = new Graph();
    graph->insertVertex(1);
    graph->insertVertex(2);
    graph->insertVertex(3);
    graph->insertEdge(1,3,9);
    graph->print();
    int* endVertices = graph->endVertices(9);
    cout << "End vertices edge 9: " << endVertices[0] << " " << endVertices[1] << endl;
    cout << "Get edge: " << graph->getEdge(1,3) << endl;
    cout << "Opposite of 1 edge = 9: " << graph->opposite(1,9) << endl;
    graph->insertVertex(4);
    graph->insertVertex(5);
    graph->insertEdge(4,5,10);
    graph->insertEdge(1,4,11);
    cout << "Opposite of 1 edge = 11: " << graph->opposite(1,11) << endl;
    endVertices = graph->endVertices(11);
    cout << "End vertices edge 11: " << endVertices[0] << " " << endVertices[1] << endl;
    return 0;
}
