#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include "Elements.hpp"
#include "Request.hpp"
#include "Grafo.hpp"

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

void dijkstra(Vertex* start, Graph graph);

void swap(vector<Edge>& heap, int i, int j);

void heapify(vector<Edge>& heap, int n, int i);

void insertIntoHeap(vector<Edge>& heap, Edge v);

Edge removeMin(vector<Edge>& heap);

void operation1(Request request, Graph& graph);

void operation2(Request request, Deliveryman deliveryman, Graph& graph);

void operation3(Request request, Seller seller, Graph& graph);


#endif 