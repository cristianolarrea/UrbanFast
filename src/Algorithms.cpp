#include "Grafo.cpp"
#include "Elements.cpp"

#include <limits>
#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

// Função para trocar dois vértices
void swap(vector<tuple<Vertex*, int>>& heap, int i, int j) {
    tuple<Vertex*, int> obj = heap[i];
    heap[i] = heap[j];
    heap[j] = obj;
}

// Função para realizar o heapify
void heapify(vector<tuple<Vertex*, int>>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && get<1>(heap[left]) < get<1>(heap[smallest])) {
        smallest = left;
    }

    if (right < n && get<1>(heap[right]) < get<1>(heap[smallest])) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap, i, smallest);
        heapify(heap, n, smallest);
    }
}

// // Função para inserir um novo elemento no heap
// void insertIntoHeap(vector<tuple<Vertex, int>>& heap, Vertex& v, int distance) {
//     heap.push_back(tuple<Vertex, int>(v, distance));
//     int i = heap.size() - 1;

//     while (i > 0 && get<1>(heap[(i - 1) / 2]) > get<1>(heap[i])) {
//         swap(heap, i, (i - 1) / 2);
//         i = (i - 1) / 2;
//     }
// }

void insertIntoHeap(vector<tuple<Vertex*, int>>& heap, Vertex& v, int distance) {
    // Criar uma nova tupla com o vértice e a distância
    tuple<Vertex*, int> newNode(&v, distance);

    // Adicionar a nova tupla ao final do heap
    heap.push_back(newNode);
    
    // Obter o índice do elemento recém-inserido
    int currentIndex = heap.size() - 1;

    // Reorganizar o heap para manter a propriedade de min-heap
    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;

        // Verificar se a propriedade do min-heap é violada
        if (get<1>(heap[currentIndex]) < get<1>(heap[parentIndex])) {
            // Trocar os elementos se necessário
            swap(heap[currentIndex], heap[parentIndex]);
            // Atualizar o índice atual
            currentIndex = parentIndex;
        } else {
            // Se a propriedade do min-heap não for violada, parar o loop
            break;
        }
    }
}

// Função para remover o elemento de menor distância do heap
Vertex* removeMin(vector<tuple<Vertex*, int>>& heap) {
    if (heap.empty()) {
        cout << "Heap vazio!" << endl;
        return nullptr; // Retorna um Vertex inválido caso o heap esteja vazio
    }
    tuple<Vertex*, int>* obj = &(heap[0]);
    Vertex* min = get<0>(*obj);
    heap[0] = heap.back();
    heap.pop_back();
    heapify(heap, heap.size(), 0);

    return min;
}

// int calculateDistance(Vertex* v1, Vertex* v2) {
//     for (auto& edge : v1->streets_connected) {
//         for (auto& edge2 : v2->streets_connected) {
//             // if street names are the same
//             if (get<0>(edge).name == get<0>(edge2).name) {
//                 // get the difference
//                 int v1_number = get<1>(edge);
//                 int v2_number = get<1>(edge2);
//                 return abs(v1_number - v2_number);
//             }
//         }
//     }
// }

// Função para realizar o algoritmo de Dijkstra
void dijkstra(Vertex& start, Graph& graph, vector<int> &distances, vector<Vertex*> &parents) {
    vector<tuple<Vertex*, int>> pq;
    vector<bool> checked(graph.nVertices);

    for (Vertex* v : graph.vertices) {
        parents[v->id] = nullptr;
        checked[v->id] = false;
        distances[v->id] = INT_MAX;
    }

    parents[start.id] = &start;
    distances[start.id] = 0;
    insertIntoHeap(pq, start, distances[start.id]);

    while (!pq.empty()) {
        Vertex* u = removeMin(pq);

        for (tuple<Edge*, int>& tupla: u->streets_connected) {
            Edge* e = get<0>(tupla);
            Vertex* v;
            if (e->vertex1->id == u->id) {
                v = e->vertex2;
            } else if (e->vertex2->id==u->id) {
                v = e->vertex1;
            }
            for (tuple<Edge*, int> tupla_v : v->streets_connected) {
                Edge* j = get<0>(tupla_v);
                if (e->name==j->name) {
                    int cost = abs(get<1>(tupla) - get<1>(tupla_v));
                    if (distances[u->id] + cost < distances[v->id]) {
                        parents[v->id] = u;
                        distances[v->id] = distances[u->id] + cost;
                        insertIntoHeap(pq, *v, distances[v->id]);
                    }
                }
            }
        }
    }

    for (int i=0; i<graph.nVertices; i++) {
        if (parents[i]) {
            cout << "parent de " + graph.vertices[i]->name + " é: " + parents[i]->name << endl;
            cout << parents[i]->predecessor << endl; 
            //cout << "parent de " + to_string(i) + "é: " + parents[i]->name << endl;
        } else {
            cout << "ponteiro vazio para " << graph.vertices[i]->name << endl;
        }
    }
}

vector<Vertex*> getPath(Vertex& start, Vertex& destination, const vector<Vertex*>& parents) {
    vector<Vertex*> path;
    Vertex* current = &destination;
    cout << start.predecessor << endl;
    while (current != nullptr) {
        path.push_back(current);
        cout << current->street << endl;
        cout << current->predecessor << endl;
        current = current->predecessor;
    }

    reverse(path.begin(), path.end());

    return path;
}