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

    Vertex vertex1;
    Vertex vertex2;
    Vertex vertex3;

    graph.addVertex(vertex1);
    graph.addVertex(vertex2);
    graph.addVertex(vertex3);
    graph.addVertex(client);
    graph.addVertex(deliveryman);
    graph.addVertex(seller);

    Edge edge1("Rua 1", &vertex1, &vertex2, 1, 10);
    Edge edge2("Rua 2", &vertex2, &vertex3, 2, 10);
    Edge edge3("Rua 3", &vertex3, &vertex1, 3, 10);
    Edge edge4("Rua 4", &vertex1, &client, 4, 10);
    Edge edge5("Rua 5", &vertex2, &seller, 5, 10);
    Edge edge6("Rua 6", &vertex3, &deliveryman, 10, 6);

    graph.addStreet(edge1);
    graph.addStreet(edge2);
    graph.addStreet(edge3);
    graph.addStreet(edge4);
    graph.addStreet(edge5);
    graph.addStreet(edge6);

    // for (const auto& vertex : graph.vertexes) {
    //     cout << vertex.type << endl;
    // }

    // cout << edge1.distance << "|" << edge1.starting_number << "|" << edge1.ending_number << endl;
    // cout << edge2.distance << "|" << edge2.starting_number << "|" << edge2.ending_number << endl;

    graph.displayInfo();

    return 0;
}