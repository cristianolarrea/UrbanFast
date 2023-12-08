#include "../include/Operations.hpp"

#include <limits>
#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

// calcular a distancia entre dois vertices
int calculateDistance(Vertex* v1, Vertex* v2) {
    for (auto& edge : v1->streets_connected) {
        for (auto& edge2 : v2->streets_connected) {
            // if street names are the same
            if (get<0>(edge).name == get<0>(edge2).name) {
                // get the difference
                int v1_number = get<1>(edge);
                int v2_number = get<1>(edge2);
                return abs(v1_number - v2_number);
            }
        }
    }
}