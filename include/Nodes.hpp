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

class Vertex {
public:
    string name;
    string street;
    int32_t number;

    virtual void displayInfo() const = 0;
};

class DistributionCenter : public Vertex {
public:
    vector<tuple<Product, int>> inventory;

    DistributionCenter(const string& n, const string& street, const int32_t& number);

    void addProduct(const Product& product, const int& quantity);
    void removeProduct(const Product& product);
    void updateProductQuantity(const Product& product, const int& new_quantity);
    void displayInfo() const override;
};

class Seller : public Vertex {
public:
    vector<Product> catalog;

    Seller(const string& n, const string& street, const int32_t& number);

    void addProduct(const Product& product);
    void removeProduct(const Product& product);
    void displayInfo() const override;
};

class Client : public Vertex {
public:
    Client(const string& n, const string& street, const int32_t& number);

    void displayInfo() const override;
};

class Deliveryman : public Vertex {
public:
    Vehicle vehicle;
    double currentCapacity = vehicle.maxCapacity;

    Deliveryman(const string& n, const string& street, const int32_t& number, const string& v, double mw);

    void displayInfo() const override;
};

#endif