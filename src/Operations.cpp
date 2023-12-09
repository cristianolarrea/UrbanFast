#include "Algorithms.cpp"
#include "Request.cpp"
#include <algorithm>

using namespace std;

vector<Vertex*> operation1(Graph& graph, int n_entregadores, Request& request) {

    int counter = 0;
    vector<Vertex*> deliverymen(n_entregadores);
    vector<int> distances(graph.nVertices);

    dijkstra(request.seller, graph, distances);

    //sort(distances.begin(), distances.end());

    // for (int n : distances) {
    //     cout << n << endl;
    // }

    // find the n_entregadores closest deliverymen to the seller
    while (counter < n_entregadores) {
        int MIN = INT_MAX;
        int min_index;
        Vertex* deliveryman = nullptr;
        cout << &deliveryman << endl;
        // iterates the distances vector to find the minimum distance

        for (int i = 0; i < distances.size(); i++) {
            if (distances[i] <= MIN && graph.vertices[i]->type == "Deliveryman") {
                // if the distance is smaller than the current minimum, update the minimum
                MIN = distances[i];
                min_index = i;
                deliveryman = graph.vertices[min_index];
            }
        }
        // add the deliveryman to the vector
        deliverymen[counter] = deliveryman;
        counter++;
        distances.erase(distances.begin() + min_index);
    }

    // cout << deliverymen.size() << endl;

    // for (int i = 0; i < deliverymen.size(); i++) {
    //     //cout << deliverymen[i]->name << endl;
    //     cout << deliverymen[i]->name << endl;
    //     cout << deliverymen[i]->type << endl;
    //     cout << deliverymen[i]->id << endl;
    // }

    return deliverymen;
}