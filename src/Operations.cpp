#include "../include/Operations.hpp"
#include "../include/Elements.hpp"
#include "../include/Grafo.hpp"

#include <limits>
#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

// Função para trocar dois vértices
void swap(vector<Edge>& heap, int i, int j) {
    Edge temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Função para realizar o heapify
void heapify(vector<Edge>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].distance < heap[smallest].distance) {
        smallest = left;
    }

    if (right < n && heap[right].distance < heap[smallest].distance) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap, i, smallest);
        heapify(heap, n, smallest);
    }
}

// Função para inserir um novo elemento no heap
void insertIntoHeap(vector<Edge>& heap, Edge v) {
    heap.push_back(v);
    int i = heap.size() - 1;

    while (i > 0 && heap[(i - 1) / 2].distance > heap[i].distance) {
        swap(heap, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

// Função para remover o elemento de menor distância do heap
Edge removeMin(vector<Edge>& heap) {
    // if (heap.empty()) {
    //     cout << "Heap vazio!" << endl;
    //     return; // Retorna um Vertex inválido caso o heap esteja vazio
    // }

    Edge min = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(heap, heap.size(), 0);

    return min;
}

// Função para realizar o algoritmo de Dijkstra
void dijkstra(Vertex* start, Graph graph) {
    vector<Edge> pq;
    vector<Edge> path;

    // Inicialização das distâncias
    for (Edge e : graph.streets) {
        if (e.vertex1 == start || e.vertex2 == start) {
            e.distance = 0;
        } else {
            e.distance = INT_MAX;
        }
        insertIntoHeap(pq, e);
    }

    while (!pq.empty()) {
        Edge e1 = removeMin(pq);
        Vertex* u = e1.vertex1;

        for (Edge edge : u->streets_connected) {
            Edge e2 = edge;
            double distance_through_u = e1.distance + e2.distance;

            if (distance_through_u < e2.distance) {
                e2.distance = distance_through_u;
                insertIntoHeap(pq, e2);
            }
        }
    }

    // Impressão das distâncias mínimas a partir do vértice inicial
    for (Edge e : graph.streets) {
        cout << "Distância de " << start->name << " para " << e.name << " é: " << e.distance << endl;
    }
}

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

    dijkstra(&vertex1, graph);

    return 0;

}