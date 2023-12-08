#ifndef GRAFO_HPP
#define GRAFO_HPP
#include "Nodes.hpp"

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

class Edge {
public:
    string name;
    double distance;
    Vertex* vertex1;
    Vertex* vertex2;
    bool active;

    Edge(const string& n, double w, Vertex* v1, Vertex* v2, bool a = true);
};

class Graph {
public:
    vector<Vertex> corners;
    vector<Edge> streets;
    vector<DistributionCenter> distributionCenters;
    vector<Seller> sellers;
    vector<Deliveryman> deliverymen;

    Graph();

    void addCorner(const Vertex& vertex);
    void addStreet(const Edge& edge);
    void addDistributionCenter(const DistributionCenter& dc);
    void addSeller(const Seller& seller);
    void addDeliveryman(const Deliveryman& deliveryman);
    
    void removeCorner(const Vertex& vertex);
    void removeStreet(const Edge& edge);
    void removeDistributionCenter(const DistributionCenter& dc);
    void removeSeller(const Seller& seller);
    void removeDeliveryman(const Deliveryman& deliveryman);

    void displayInfo() const;
};


#endif 