#include "../src/Operations.cpp"
#include <fstream>

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int main() {
    ofstream outFile("testOperation1.txt");
    vector<int> ns = {10, 50, 100, 200, 500, 1000};

    for (int n : ns) {
        
        Graph graph;

        vector<Vertex*> esquinas;
        vector<Vertex*> entregadores;
        vector<Vertex*> vendedores;

        // gerar vários vértices esquina 
        for (int i = 0; i < n; i++) {
            Vertex esquina;
            graph.addVertex(&esquina);
            esquinas.push_back(&esquina);
        }

        vector<string> veiculos = {"Car", "Motorcycle", "Truck"};
        vector<int> capacities = {100, 20, 200};
        // gerar vários vértices entregadores 
        for (int i = 0; i < n; i++) {
            int randomIndex = rand() % 3;
            int randomStreet = rand() % n;
            int randomHouseNumber = rand() % 1000;
            Deliveryman entregador("Entregador " + to_string(i), "Rua " + to_string(randomStreet), randomHouseNumber, veiculos[randomIndex], capacities[randomIndex]);
            graph.addVertex(&entregador);
            entregadores.push_back(&entregador);
        }

        // gerar vários vértices sellers
        for (int i = 0; i < n; i++) {
            int randomStreet = rand() % n;
            int randomHouseNumber = rand() % 1000;
            Seller vendedor("Vendedor " + to_string(i), "Rua " + to_string(randomStreet), randomHouseNumber);
            graph.addVertex(&vendedor);
            vendedores.push_back(&vendedor);
        }

        // adicionar arestas aleatoriamente
        for (int i = 0; i < (n*100); i++) {
            int randomIndex = rand() % n;
            int randomIndex2 = rand() % n;
            int randomInitNumber = rand() % n;
            int randomFinalNumber = rand() % n;
            Edge edge("Rua " + to_string(randomIndex), graph.vertices[randomIndex], graph.vertices[randomIndex2], randomInitNumber, randomFinalNumber);
            graph.addStreet(&edge);
        }

        Product p1("p1", 10, 1);

        int randomIndex = rand() % n;
        
        // generate a random client
        int randomStreet = rand() % n;
        int randomHouseNumber = rand() % 1000;
        
        Client c1("c1", "Rua " + to_string(randomStreet), randomHouseNumber);

        // instantiate a random seller
        randomIndex = rand() % n;
        Seller s1("s1", "Rua " + to_string(randomStreet), randomHouseNumber);

        // add them to the graph
        graph.addVertex(&c1);
        graph.addVertex(&s1);

        // instantiate a request
        Request r1(c1, s1, p1, 1);

        // add them to random points in the graph
        randomIndex = rand() % n;
        Edge edge("Rua " + to_string(randomIndex), graph.vertices[randomIndex], &c1, 1, 10);
        graph.addStreet(&edge);

        randomIndex = rand() % n;
        edge = Edge("Rua " + to_string(randomIndex), graph.vertices[randomIndex], &s1, 1, 20);

        vector<Vertex*> distances(graph.nVertices);
        vector<Vertex*> parents(graph.nVertices);
        
        // apply operation1
        vector<int> results;
        for (int i = 0; i < 10; i++) {
            cout << "oi" << endl;
            auto start = chrono::high_resolution_clock::now();
            operation1(graph, i, r1);
            auto end = chrono::high_resolution_clock::now();
            
            auto diff = end - start;
            
            auto time_seconds = chrono::duration_cast<chrono::seconds>(diff);
            
            results.push_back(time_seconds.count());
            // write n, i, and the time it took to execute operation1
            outFile << n << " " << i << " " << time_seconds.count() << endl;
        }
    }

    return 0;
}