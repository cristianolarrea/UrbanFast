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

class Corner;

class Edge {
public:
    std::string name;
    double distance;
    Corner* vertex1;
    Corner* vertex2;
    bool active;

    Edge(const std::string& n, double w, Corner* v1, Corner* v2, bool a = true);
};

class Corner {
public:
    int32_t id;
    vector<Edge> streets_connected;

    Corner() noexcept;
};

class TempVertex {
public:
    string name;
    string street;
    int32_t number;

    virtual void displayInfo() const = 0;
};


class DistributionCenter : public TempVertex {
public:
    vector<tuple<Product, int>> inventory;

    DistributionCenter(const string& n, const string& street, const int32_t& number);

    void addProduct(const Product& product, const int& quantity);
    void removeProduct(const Product& product);
    void updateProductQuantity(const Product& product, const int& new_quantity);
    void displayInfo() const override;
};

class Seller : public TempVertex {
public:
    vector<Product> catalog;

    Seller(const string& n, const string& street, const int32_t& number);

    void addProduct(const Product& product);
    void removeProduct(const Product& product);
    void displayInfo() const override;
};

class Client : public TempVertex {
public:
    Client(const string& n, const string& street, const int32_t& number);

    void displayInfo() const override;
};

class Deliveryman : public TempVertex {
public:
    Vehicle vehicle;
    double currentCapacity = vehicle.maxCapacity;

    Deliveryman(const string& n, const string& street, const int32_t& number, const string& v, double mw);

    void displayInfo() const override;
};

#endif