#include "../src/Elements.cpp"
#include "../src/Grafo.cpp"

int main() {
    DistributionCenter dc("DC 1", "123 Main St", 1);
    Seller seller("Chico Moedas", "Galeto Sat's", 20);
    Client client("Luisa Sonza", "Praia do Flamengo", 3);
    Deliveryman deliveryman("Whindersson Nunes", "Praia de Botafogo", 1, "Car", 100.0);

    Graph graph;

    graph.addDistributionCenter(dc);
    graph.addSeller(seller);
    graph.addDeliveryman(deliveryman);

    Corner corner1;
    Corner corner2;
    Corner corner3;

    graph.addCorner(corner1);
    graph.addCorner(corner2);
    graph.addCorner(corner3);

    Edge edge1("Galeto Sat's", 10.0, &corner1, &corner2);
    Edge edge2("Praia do Flamengo", 20.0, &corner2, &corner3);
    Edge edge3("Praia de Botafogo", 30.0, &corner3, &corner1);

    graph.addStreet(edge1);
    graph.addStreet(edge2);
    graph.addStreet(edge3);

    cout << "CORNERS:" << endl;

    cout << "Corner " << corner1.id << endl;
    for (const auto& street : corner1.streets_connected) {
        cout << street.name << endl;
    }

    cout << endl;

    cout << "Corner " << corner2.id << endl;
    for (const auto& street : corner2.streets_connected) {
        cout << street.name << endl;
    }

    cout << endl;

    cout << "Corner " << corner3.id << endl;
    for (const auto& street : corner3.streets_connected) {
        cout << street.name << endl;
    }

    cout << endl;

    graph.displayInfo();

    return 0;
}