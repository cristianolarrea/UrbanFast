#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include "../include/Elements.hpp"

using namespace std;

/* ---------------------------------------------- */
/* ------------ PRODUCT ------------*/
Product::Product(const string& n, double w, double p) : name(n), weight(w), price(p) {}


/* ---------------------------------------------- */
/* ------------ VEHICLE ------------*/
Vehicle::Vehicle(const string& n, double mw) : name(n), maxCapacity(mw) {}


/* ---------------------------------------------- */
/* ------------ CORNER ------------ */
Vertex::Vertex() noexcept {
    static int32_t id=0;
    this->id = id++;
    name = "Corner" + to_string(id);
    streets_connected = vector<tuple<Edge*, int>>();
    distance = INT_MAX;
    predecessor = nullptr;
    type = "Corner";
}

/* ---------------------------------------------- */
/* ------------ EDGE ------------ */
Edge::Edge(const string n, Vertex* v1, Vertex* v2, int sn, int en) : name(n), vertex1(v1), vertex2(v2), starting_number(sn), ending_number(en) {
    active = true;
}


/* ---------------------------------------------- */
/* ------------ DISTRIBUTION CENTER ------------ */
DistributionCenter::DistributionCenter(const string& n, const string& street, const int32_t& number) : Vertex() {
    name = n;
    this->street = street;
    this->number = number;
    type = "Distribution Center";
}

// Adds a new product to the inventory [(Produto1, Quantidade)]
void DistributionCenter::addProduct(const Product& product, const int& quantity) {
    for (auto& [prod, quant] : inventory) {
        if (prod.name == product.name) {
            quant += quantity;
            return;
        }
    }
    inventory.push_back(make_tuple(product, quantity));
}

// Removes a product from the inventory
void DistributionCenter::removeProduct(const Product& product) {
    for (auto it = inventory.begin(); it != inventory.end(); it++) {
        if (get<0>(*it).name == product.name) {
            inventory.erase(it);
            return;
        }
    }
}

// Updates the quantity of a product in the inventory
void DistributionCenter::updateProductQuantity(const Product& product, const int& new_quantity) {
    for (auto& [prod, quant] : inventory) {
        if (prod.name == product.name) {
            quant = new_quantity;
            return;
        }
    }
}

// Displays the information of the distribution center
void DistributionCenter::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Address: " << street << ", " << number << endl;
    cout << "Inventory: " << endl;
    for (auto& [prod, quant] : inventory) {
        cout << "Product: " << prod.name << " | Quantity: " << quant << endl;
    }
    cout << endl;
}


/* ---------------------------------------------- */
/* ------------ SELLER ------------*/

Seller::Seller(const string& n, const string& street, const int32_t& number) : Vertex() {
    this->name = n;
    this->street = street;
    this->number = number;
    type = "Seller";
}

// Adds a new product to the seller's catalog
void Seller::addProduct(const Product& product) {
    catalog.push_back(product);
}

// Removes a product from the seller's catalog
void Seller::removeProduct(const Product& product) {
    for (auto it = catalog.begin(); it != catalog.end(); it++) {
        if (it->name == product.name) {
            catalog.erase(it);
            return;
        }
    }
}

// Displays the information of the seller
void Seller::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Address: " << street << ", " << number << endl;
    cout << "Catalog: " << endl;
    for (auto& prod : catalog) {
        cout << "Product: " << prod.name << " | Price: " << prod.price << endl;
    }
    cout << endl;
}


/* ---------------------------------------------- */
/* ------------ CLIENT ------------*/

Client::Client(const std::string& n, const std::string& street, const int32_t& number) : Vertex() {
    this->name = n;
    this->street = street;
    this->number = number;
    type = "Client";
}

// Displays the information of the client
void Client::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Address: " << street << ", " << number << endl;
    cout << endl;
}


/* ---------------------------------------------- */
/* ------------ DELIVERYMAN ------------*/

Deliveryman::Deliveryman(const string& n, const string& street, const int32_t& number, const string& v, double mw) : Vertex(), vehicle(v, mw) {
    this->name = n;
    this->street = street;
    this->number = number;
    type = "Deliveryman";
}

// Displays the information of the deliveryman
void Deliveryman::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Address: " << street << ", " << number << endl;
    cout << "Vehicle: " << vehicle.name << endl;
    cout << "Max Capacity: " << vehicle.maxCapacity << endl;
    cout << "Current Capacity: " << currentCapacity << endl;
    cout << endl;
}