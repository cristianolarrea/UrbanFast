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
    vector<Vertex> vertexes;
    vector<Edge> streets;
    vector<DistributionCenter> distributionCenters;
    vector<Seller> sellers;
    vector<Deliveryman> deliverymen;

    Graph();

    void addVertex(const Vertex& vertex);
    void addStreet(const Edge& edge);
    void addDistributionCenter(const DistributionCenter& dc);
    void addSeller(const Seller& seller);
    void addDeliveryman(const Deliveryman& deliveryman);
    
    void displayInfo() const;
};


#endif 