#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Elements.hpp"

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

class Graph {

public:
    vector<Vertex*> vertices;
    vector<Edge*> streets;
    int nVertices;

    Graph();

    void addVertex(Vertex* vertex);
    void addStreet(Edge* edge);
    
    void displayInfo() const;
};


#endif 