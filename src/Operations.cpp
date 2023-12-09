#include "Algorithms.cpp"
#include "Request.cpp"
#include <algorithm>

using namespace std;

vector<Vertex*> operation1(Graph& graph, int n_entregadores, Request& request) {

    int counter = 0;
    vector<Vertex*> deliverymen(n_entregadores);
    vector<int> distances(graph.nVertices);
    vector<Vertex*> parents(graph.nVertices);

    dijkstra(request.seller, graph, distances, parents);

    // find the n_entregadores closest deliverymen to the seller
    while (counter < n_entregadores) {
        int MIN = INT_MAX;
        int min_index;
        Vertex* deliveryman = nullptr;
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

    // for (int i = 0; i < deliverymen.size(); i++) {
    //     cout << deliverymen[i]->name << endl;
    // }

    return deliverymen;
}

vector<Vertex*> operation2(Graph& graph, Vertex& deliveryman, Request& request) {
    vector<int> distances(graph.nVertices);
    vector<int> distances2(graph.nVertices);
    vector<Vertex*> parents(graph.nVertices);
    vector<Vertex*> parents2(graph.nVertices);
    vector<Vertex*> path_to_seller; // vector of (street name, street number)
    vector<Vertex*> path_to_client; // vector of (street name, street number)

    // lista de distancias do entregador até todos os vertices
    dijkstra(deliveryman, graph, distances, parents);

    path_to_seller = getPath(deliveryman, request.seller, parents);

    // for (int i = 0; i < path_to_seller.size(); i++) {
    //     cout << path_to_seller[i]->name << ", " << path_to_seller[i]->starting_number << "-" << path_to_seller[i]->ending_number << endl;
    // }

    // lista de distancias do entregador (agora na loja) até todos os vertices
    //dijkstra(request.seller, graph, distances2, parents2);

    //path_to_client = getPath(request.seller, request.client, parents2);

    // cout << path_to_client.size() << endl;
    // cout << path_to_seller.size() << endl;

    // // compose the two paths
    // path_to_seller.insert(path_to_seller.end(), path_to_client.begin(), path_to_client.end());

    // for  (int i = 0; i < path_to_seller.size(); i++) {
    //     cout << path_to_seller[i]->name << ", " << path_to_seller[i]->starting_number << "-" << path_to_seller[i]->ending_number << endl;
    // }

    return path_to_client;

}