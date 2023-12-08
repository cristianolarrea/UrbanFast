#include "../src/Operations2.cpp"
#include "../src/Elements.cpp"
#include "../src/Grafo.cpp"

using namespace std;

int main() {

    Graph graph;

    Vertex vertex1;
    Vertex vertex2;
    Vertex vertex3;
    Vertex vertex4;
    Vertex vertex5;
    Vertex vertex6;
    Vertex vertex7;
    Vertex vertex8;
    Vertex vertex9;
    Vertex vertex10;
    Vertex vertex11;
    Seller seller1("Chico Moedas", "Galeto Sat's", 20);
    Deliveryman deliveryman1("João", "Rua 1", 10, "Car", 1000);

    Edge edge1("Rua Visconde de Ouro Preto", &vertex1, &vertex2, 0, 120);
    Edge edge2("Rua Bambina", &vertex1, &vertex4, 3100, 3400);
    Edge edge3("Rua Vicente de S.", &vertex4, &vertex5, 0, 150);
    Edge edge4("Rua Muniz Barreto", &vertex2, &vertex5, 800, 100);
    Edge edge5("Rua Bambina", &vertex4, &vertex6, 3000, 3100);
    Edge edge6("Rua Bambina", &vertex6, &vertex9, 2000, 3000);
    Edge edge7("Rua São Clemente", &vertex9, &vertex10, 10, 2050);
    Edge edge8("Rua São Clemente", &vertex10, &vertex11, 2050, 4000);
    Edge edge9("Rua Muniz Barreto", &vertex10, &vertex7, 1250, 1700);
    Edge edge10("Rua Prof. Alfrego G.", &vertex7, &vertex8, 190, 450);
    Edge edge11("Rua Prof. Alfrego G.", &vertex6, &vertex7, 20, 190);
    Edge edge12("Rua São Clemente", &vertex8, &vertex11, 450, 4000);
    Edge edge13("Rua Praia de Botafogo", &vertex3, &seller1, 50, 250);
    Edge edge14("Rua Praia de Botafogo", &seller1, &vertex8, 250, 300);
    Edge edge15("Rua Praia de Botafogo", &vertex8, &vertex11, 300, 600);
    Edge edge16("Rua Praia de Botafogo", &vertex11, &vertex10, 600, 800);
    Edge edge17("Rua Praia de Botafogo", &vertex10, &deliveryman1, 800, 1000);

    graph.addVertex(vertex1);
    graph.addVertex(vertex2);
    graph.addVertex(vertex3);
    graph.addVertex(vertex4);
    graph.addVertex(vertex5);
    graph.addVertex(vertex6);
    graph.addVertex(vertex7);
    graph.addVertex(vertex8);
    graph.addVertex(vertex9);
    graph.addVertex(vertex10);
    graph.addVertex(vertex11);
    graph.addVertex(seller1);
    graph.addVertex(deliveryman1);
    
    graph.addStreet(edge1);
    graph.addStreet(edge2);
    graph.addStreet(edge3);
    graph.addStreet(edge4);
    graph.addStreet(edge5);
    graph.addStreet(edge6);
    graph.addStreet(edge7);
    graph.addStreet(edge8);
    graph.addStreet(edge9);
    graph.addStreet(edge10);
    graph.addStreet(edge11);
    graph.addStreet(edge12);
    graph.addStreet(edge13);
    graph.addStreet(edge14);
    graph.addStreet(edge15);
    graph.addStreet(edge16);
    graph.addStreet(edge17);

    dijkstra(&seller1, graph);

    return 0;

}