#include "Grafo.hpp"



// Métodos do Grafo

Graph::Graph() {}

void Graph::addCorner(const Vertex& vertex) {
    corners.push_back(vertex);
}

void Graph::addStreet(const Edge& edge) {
    streets.push_back(edge);
}

void Graph::addDistributionCenter(const DistributionCenter& dc) {
    distributionCenters.push_back(dc);
}

void Graph::addSeller(const Seller& seller) {
    sellers.push_back(seller);
}

void Graph::addDeliveryman(const Deliveryman& deliveryman) {
    deliverymen.push_back(deliveryman);
}

void Graph::removeCorner(const Vertex& vertex) {
    for (auto it = corners.begin(); it != corners.end(); ++it) {
        if (it->name == vertex.name) {
            corners.erase(it);
            break;
        }
    }
}

void Graph::removeStreet(const Edge& edge) {
    for (auto it = streets.begin(); it != streets.end(); ++it) {
        if (it->name == edge.name) {
            streets.erase(it);
            break;
        }
    }
}

void Graph::removeDistributionCenter(const DistributionCenter& dc) {
    for (auto it = distributionCenters.begin(); it != distributionCenters.end(); ++it) {
        if (it->name == dc.name) {
            distributionCenters.erase(it);
            break;
        }
    }
}

void Graph::removeSeller(const Seller& seller) {
    for (auto it = sellers.begin(); it != sellers.end(); ++it) {
        if (it->name == seller.name) {
            sellers.erase(it);
            break;
        }
    }
}

void Graph::removeDeliveryman(const Deliveryman& deliveryman) {
    for (auto it = deliverymen.begin(); it != deliverymen.end(); ++it) {
        if (it->name == deliveryman.name) {
            deliverymen.erase(it);
            break;
        }
    }
}

