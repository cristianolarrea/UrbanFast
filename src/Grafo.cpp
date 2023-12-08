#include "../include/Grafo.hpp"

// Métodos do Grafo

Graph::Graph() {}

void Graph::addCorner(const Corner& vertex) {
    corners.push_back(vertex);
}

void Graph::addStreet(const Edge& edge) {
    streets.push_back(edge);
    edge.vertex1->streets.push_back(edge);
    edge.vertex2->streets.push_back(edge);
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

void Graph::displayInfo() const {
    cout << "Corners:" << endl;
    for (const auto& corner : corners) {
        cout << "Corner " << corner.id << endl;
        cout << "Streets:" << endl;
        for (const auto& street : corner.streets) {
            cout << street.name << endl;
        }
        cout << endl;
    }
    cout << endl;

    cout << "Streets:" << endl;
    for (const auto& street : streets) {
        cout << street.name << endl;
    }
    cout << endl;

    cout << "Distribution Centers:" << endl;
    for (const auto& dc : distributionCenters) {
        dc.displayInfo();
    }
    cout << endl;

    cout << "Sellers:" << endl;
    for (const auto& seller : sellers) {
        seller.displayInfo();
    }
    cout << endl;

    cout << "Deliverymen:" << endl;
    for (const auto& deliveryman : deliverymen) {
        deliveryman.displayInfo();
    }
    cout << endl;
}