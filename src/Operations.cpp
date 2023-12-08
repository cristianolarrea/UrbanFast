#include "../include/Operations.hpp"

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
void dijkstra(Vertex* start, Graph& graph) {
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

        for (tuple<Edge, int> edge : u->streets_connected) {
            tuple<Edge, int> e2 = edge;
            double distance_through_u = e1.distance + get<0>(e2).distance;

            if (distance_through_u < get<0>(e2).distance) {
                get<0>(e2).distance = distance_through_u;
                get<0>(e2).previous = u;
                insertIntoHeap(pq, get<0>(e2));
            }
        }
    }

    // Impressão das distâncias mínimas a partir do vértice inicial
    // for (Edge e : graph.streets) {
    //     // if (e.vertex1->type == "Deliveryman" || e.vertex2->type == "Deliveryman") {
    //     cout << "Distância de " << start->id << ", " << start-> << " para " << e.vertex2->name << "," << e.vertex2->number << " é: " << e.distance << endl;
    //     // }
    // }
}