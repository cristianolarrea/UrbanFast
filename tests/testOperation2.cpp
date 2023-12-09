#include "../src/Operations.cpp"

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int main() {

    Graph graph;

    Vertex esq1;
    Vertex esq2;
    Vertex esq3;
    Vertex esq4;
    Vertex esq5;
    Vertex esq6;
    graph.addVertex(&esq1);
    graph.addVertex(&esq2);
    graph.addVertex(&esq3);
    graph.addVertex(&esq4);
    graph.addVertex(&esq5);
    graph.addVertex(&esq6);
    
    Seller s1("s1", "Rua 2", 30);
    Seller s2("s2", "Rua 5", 77);
    Seller s3("s3", "Rua 8", 100);
    Seller s4("s4", "Rua 7", 90);
    graph.addVertex(&s1);
    graph.addVertex(&s2);
    graph.addVertex(&s3);
    graph.addVertex(&s4);

    Deliveryman d1("d1", "Rua 1", 10, "Car", 100);
    Deliveryman d2("d2", "Rua 4", 100, "Motorcycle", 20);
    Deliveryman d3("d3", "Rua 8", 20, "Truck", 200);
    graph.addVertex(&d1);
    graph.addVertex(&d2);
    graph.addVertex(&d3);

    Client c1("c1", "Rua 9", 37);
    Client c2("c2", "Rua 10", 12);
    Client c3("c3", "RUa 8", 120);
    graph.addVertex(&c1);
    graph.addVertex(&c2);
    graph.addVertex(&c3);

    Edge edge1("Rua 2", &esq1, &s1, 20, 30);
    Edge edge2("Rua 2", &s1, &esq2, 30, 40);
    Edge edge3("Rua 9", &esq2, &c1, 20, 37);
    Edge edge4("Rua 1", &esq1, &d1, 1, 10);
    Edge edge5("Rua 1", &d1, &esq4, 10, 20);
    Edge edge6("Rua 10", &esq4, &c2, 7, 12);
    Edge edge7("Rua 3", &esq2, &esq3, 40, 60);
    Edge edge8("Rua 4", &esq3, &d2, 90, 100);
    Edge edge9("Rua 4", &d2, &esq5, 100, 200);
    Edge edge10("Rua 8", &esq5, &d3, 10, 20);
    Edge edge11("Rua 8", &d3, &s3, 20, 100);
    Edge edge12("Rua 8", &s3, &c3, 100, 120);
    Edge edge13("Rua 7", &d3, &s4, 30, 90);
    Edge edge14("Rua 7", &d3, &esq6, 20, 30);
    Edge edge15("Rua 5", &esq3, &s2, 70, 77);
    Edge edge16("Rua 5", &esq4, &s2, 77, 200);
    Edge edge17("Rua 6", &esq5, &esq4, 20, 200);

    graph.addStreet(&edge1);
    graph.addStreet(&edge2);
    graph.addStreet(&edge3);
    graph.addStreet(&edge4);
    graph.addStreet(&edge5);
    graph.addStreet(&edge6);
    graph.addStreet(&edge7);
    graph.addStreet(&edge8);
    graph.addStreet(&edge9);
    graph.addStreet(&edge10);
    graph.addStreet(&edge11);
    graph.addStreet(&edge12);
    graph.addStreet(&edge13);
    graph.addStreet(&edge14);
    graph.addStreet(&edge15);
    graph.addStreet(&edge16);
    graph.addStreet(&edge17);

    Product p1("p1", 20.0, 30.0);

    Request request(c3, s3, p1, 10);

    vector<Vertex*> deliverymen = operation1(graph, 2, request);

    // get the deliveryman with the shortest path
    Vertex* deliveryman = deliverymen[0];

    cout << "" << endl;
    cout << "ENTREGADOR: " << deliveryman->name << endl;
    cout << "CLIENTE: " << request.client.name << endl;
    cout << "VENDEDOR: " << request.seller.name << endl;
    cout << "" << endl;

    vector<Edge*> path = operation2(graph, *deliveryman, request);

    cout << "" << endl;

    for (int i=0; i<path.size(); i++) {
        cout << path[i]->name << endl;
    }

    return 0;
}