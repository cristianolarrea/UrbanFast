#include "Grafo.cpp"
#include "Elements.cpp"
#include "Request.cpp"

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
            for (tuple<Edge*, int>& tupla_v : v->streets_connected) {
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
}


/*
GETS THE PATH FROM A POINT TO ANOTHER
*/
vector<Edge*> getPath(Vertex& start, Vertex& destination, const vector<Vertex*>& parents) {
    vector<Vertex*> path;
    vector<Edge*> path_as_streets;

    Vertex* current = &destination;
    path.push_back(current);
    
    while (current->id != start.id) {
        Vertex* parent = parents[current->id];
        current = parent;
        path.push_back(parent);
    }

    for (int i = 0; i < path.size(); i++) {
        vector<tuple<Edge*, int>> streets_connected_to_vertex_i = path[i]->streets_connected;
        
        for (int j=0; j < streets_connected_to_vertex_i.size(); j++) {
            Edge* street_j_connected_to_vertex_i = get<0>(streets_connected_to_vertex_i[j]);
            
            if (street_j_connected_to_vertex_i->vertex1->id == path[i]->id) {
                path_as_streets.push_back(street_j_connected_to_vertex_i);
            }
        }
    }

    reverse(path_as_streets.begin(), path_as_streets.end());

    return path_as_streets;
}


/*
CHECKS IF THERE IS THE PRODUCT IN THE DESIRED QUANTITY AT THE DISTRIBUTION CENTER
*/
bool isThereProduct(Vertex* distribution_center, Request& request) {
    // para cada produto no inventario do centro de distribuicao
    for (tuple<Product, int> product : distribution_center->inventory) {
        // se forem o mesmo produto
        if ((&get<0>(product))->name == request.product.name) {
            // se a quantidade do produto no centro de distribuicao for maior que a quantidade solicitada
            if ((get<1>(product)) > request.quantity) {
                // retorna true
                return true;
            }
        }
    }
    return false;
}