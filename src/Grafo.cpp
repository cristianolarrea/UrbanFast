#include "../include/Grafo.hpp"

Graph::Graph() {this->nVertices=0;}

void Graph::addVertex(Vertex* vertex) {
    vertices.push_back(vertex);
    this->nVertices++;
}

void Graph::addStreet(Edge* edge) {
    this->streets.push_back(edge);
    edge->vertex1->streets_connected.push_back(make_tuple(edge, edge->starting_number));
    edge->vertex2->streets_connected.push_back(make_tuple(edge, edge->ending_number));
}

void Graph::displayInfo() const {
    cout << "STREETS:" << endl;
    for (const auto& street : streets) {
        cout << street->name << endl;
    }
    cout << endl;
}