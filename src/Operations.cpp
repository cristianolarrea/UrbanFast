#include "Algorithms.cpp"

using namespace std;


// ---------------------------------------------------------------------
// ---------------------------- OPERATION 1 ----------------------------
// ---------------------------------------------------------------------
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


// ---------------------------------------------------------------------
// ---------------------------- OPERATION 2 ----------------------------
// ---------------------------------------------------------------------
vector<Edge*> operation2(Graph& graph, Vertex& deliveryman, Request& request) {
    vector<int> distances(graph.nVertices);
    vector<int> distances2(graph.nVertices);
    vector<Vertex*> parents(graph.nVertices);
    vector<Vertex*> parents2(graph.nVertices);
    vector<Edge*> path_to_seller; // vector of (street name, street number)
    vector<Edge*> path_to_client; // vector of (street name, street number)

    // lista de distancias do entregador até todos os vertices
    dijkstra(deliveryman, graph, distances, parents);

    path_to_seller = getPath(deliveryman, request.seller, parents);

    // lista de distancias do entregador (agora na loja) até todos os vertices
    dijkstra(request.seller, graph, distances2, parents2);

    path_to_client = getPath(request.seller, request.client, parents2);

    for (int i=0; i<path_to_client.size(); i++) {
        path_to_seller.push_back(path_to_client[i]);
    }

    return path_to_seller;
}


// ---------------------------------------------------------------------
// ---------------------------- OPERATION 3 ----------------------------
// ---------------------------------------------------------------------
tuple<Vertex*, Vertex*, vector<Edge*>> operation3(Graph& graph, Request& request) {
    // vector to store the (distances of one vertex to all others, parents of each)
    vector<tuple<vector<int>, vector<Vertex*>>> distances_and_parents_of_all_vertices(graph.nVertices);
    vector<Edge*> path_to_seller; // vector of (street name, street number)
    vector<Edge*> path_to_client; // vector of (street name, street number)

    // ACHAR A DISTÂNCIA DOS ENTREGADORES PARA TODOS OS NÓS CENTRO DE DISTRIBUIÇÃO
    for (Vertex* vertex : graph.vertices) {
        vector<int> distance_from_one_vertex_to_all_others(graph.nVertices);
        vector<Vertex*> parents_of_vertex(graph.nVertices);

        dijkstra(*vertex, graph, distance_from_one_vertex_to_all_others, parents_of_vertex);
        cout << &parents_of_vertex << endl;
        tuple distances_and_parents = make_tuple(distance_from_one_vertex_to_all_others, parents_of_vertex);
        cout << &(get<1>(distances_and_parents)) << endl;
        
        distances_and_parents_of_all_vertices.push_back(distances_and_parents);
    }

    // ENCONTRAR COISAS DO FORMATO (entregador, centro de distribuicao, distancia)
    vector<tuple<Vertex*, Vertex*, int>>distance_from_deliverymen_to_distribution_centers;

    for (int i=0; i < graph.vertices.size(); i++) {
        vector<int> distances_from_deliveryman;
        if (graph.vertices[i]->type == "Deliveryman") {
            // access index i of distances_and_parents_of_all_vertices[i]
            distances_from_deliveryman = get<0>(distances_and_parents_of_all_vertices[i]);
            // for each distance from the deliveryman
            for (int j=0; j < distances_from_deliveryman.size(); j++) {
                if (graph.vertices[j]->type == "Distribution Center" && isThereProduct(graph.vertices[i], request)) {
                    distance_from_deliverymen_to_distribution_centers.push_back(make_tuple(graph.vertices[i], graph.vertices[j], distances_from_deliveryman[j]));
                }
            }
        }
    }

    // E ENCONTRAR COISAS DO FORMATO (centro de distribuicao, cliente, distancia)
    vector<tuple<Vertex*, Vertex*, int>>distance_from_distribution_centers_to_client;

    for (int i=0; i < graph.vertices.size(); i++) {
        vector<int> distances_from_distribution_centers;
        if (graph.vertices[i]->type == "Distribution Center" && isThereProduct(graph.vertices[i], request)) {
            // access index i of distances_and_parents_of_all_vertices[i]
            distances_from_distribution_centers = get<0>(distances_and_parents_of_all_vertices[i]);
            // for each distance from the deliveryman
            for (int j=0; j < distances_from_distribution_centers.size(); j++) {
                if (graph.vertices[j]->id == request.client.id) {
                    distance_from_distribution_centers_to_client.push_back(make_tuple(graph.vertices[i], graph.vertices[j], distances_from_distribution_centers[j]));
                }
            }
        }
    }

    // ACHAR O PAR QUE MINIMIZA A SOMA DAS DISTANCIAS
    tuple<tuple<Vertex*, Vertex*, int>, tuple<Vertex*, Vertex*, int>, int> best_route;
    int min_distance = INT_MAX;
    for (int i = 0; i < distance_from_deliverymen_to_distribution_centers.size(); i++) {
        Vertex* distribution_center_i = get<0>(distance_from_deliverymen_to_distribution_centers[i]);
        int distance_from_deliveryman_to_distribution_center_i = get<2>(distance_from_deliverymen_to_distribution_centers[i]);
        
        for (int j = 0; j < distance_from_distribution_centers_to_client.size(); j++) {
            Vertex* distribution_center_j = get<1>(distance_from_distribution_centers_to_client[j]);
            int distance_from_distribution_center_j_to_client = get<2>(distance_from_distribution_centers_to_client[j]);
        
            if (distribution_center_i->id == distribution_center_j->id) {
                int sum_distance = distance_from_deliveryman_to_distribution_center_i + distance_from_distribution_center_j_to_client;
        
                if (sum_distance < min_distance) {
                    min_distance = sum_distance;
                    best_route = make_tuple(distance_from_deliverymen_to_distribution_centers[i], distance_from_distribution_centers_to_client[j], sum_distance);
                }
            }
        }
    }

    Vertex* chosen_deliveryman = get<0>(get<0>(best_route));
    vector<Vertex*> parents_of_chosen_deliveryman;

    Vertex* chosen_distribution_center = get<1>(get<0>(best_route));
    vector<Vertex*> parents_of_chosen_distribution_center;

    for (int i=0; i < distances_and_parents_of_all_vertices.size(); i++) {
        if (graph.vertices[i]->id == chosen_deliveryman->id) {
            parents_of_chosen_deliveryman = get<1>(distances_and_parents_of_all_vertices[i]);
        }
        
        if (graph.vertices[i]->id == chosen_distribution_center->id) {
            parents_of_chosen_distribution_center = get<1>(distances_and_parents_of_all_vertices[i]);
        }
    }

    vector<Edge*> path_from_deliveryman_to_distribution_center;
    path_from_deliveryman_to_distribution_center = getPath(*chosen_deliveryman, *chosen_distribution_center, parents_of_chosen_deliveryman);

    vector<Edge*> path_from_distribution_center_to_client;
    path_from_distribution_center_to_client = getPath(*chosen_distribution_center, request.client, parents_of_chosen_distribution_center);

    for (int i = 0; i < path_from_deliveryman_to_distribution_center.size(); i++) {
        cout << path_from_deliveryman_to_distribution_center[i]->name << ", " << path_from_deliveryman_to_distribution_center[i]->starting_number << "-" << path_from_deliveryman_to_distribution_center[i]->ending_number << endl;
    }

    for (int i = 0; i < path_from_distribution_center_to_client.size(); i++) {
        cout << path_from_distribution_center_to_client[i]->name << ", " << path_from_distribution_center_to_client[i]->starting_number << "-" << path_from_distribution_center_to_client[i]->ending_number << endl;
    }

    tuple<Vertex*, Vertex*, vector<Edge*>> answer;
    answer = make_tuple(chosen_deliveryman, chosen_distribution_center, path_from_distribution_center_to_client);

    return answer;

}