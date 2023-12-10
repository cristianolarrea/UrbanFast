#ifndef NODE_TYPES_HPP
#define NODE_TYPES_HPP

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Product {
public:
    string name;
    double weight;
    double price;

    Product(const string& n, double w, double p);
};

class Vehicle {
public:
    string name;
    double maxCapacity;

    Vehicle(const string& n, double mw);
};

class Vertex;
class Edge {
public:
    std::string name;
    Vertex* vertex1;
    Vertex* vertex2;
    int starting_number;
    int ending_number;
    bool active;
    double distance;

    Edge(const string n, Vertex* v1, Vertex* v2, int sn, int en);
};

class Vertex {
public:
    string name;
    string street;
    string type;
    int distance;
    int number;
    int id;
    //Vertex* predecessor;
    vector<tuple<Edge*, int>> streets_connected;
    vector<tuple<Product, int>> inventory;

    Vertex() noexcept;
};


class DistributionCenter : public Vertex {
public:
    vector<tuple<Product, int>> inventory;

    DistributionCenter(const string& n, const string& street, const int& number);

    void addProduct(const Product& product, const int& quantity);
    void removeProduct(const Product& product);
    void updateProductQuantity(const Product& product, const int& new_quantity);
    void displayInfo() const;
};

class Seller : public Vertex {
public:
    vector<Product> catalog;


    Seller(const string& n, const string& street, const int& number);

    void addProduct(const Product& product);
    void removeProduct(const Product& product);
    void displayInfo() const;
};

class Client : public Vertex {
public:
    Client(const string& n, const string& street, const int& number);

    void displayInfo() const;
};

class Deliveryman : public Vertex {
public:
    Vehicle vehicle;
    double currentCapacity = vehicle.maxCapacity;

    Deliveryman(const string& n, const string& street, const int& number, const string& v, double mw);

    void displayInfo() const;
};

#endif