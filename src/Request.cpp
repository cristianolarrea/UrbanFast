#include "../include/Request.hpp"

/* ---------------------------------------------- */
/* ------------ REQUEST ------------*/

Request::Request(const Client& cn, const Seller& sn, const Product& pn, int q, bool o) : client(cn), seller(sn), product(pn), quantity(q), is_optimized(o) {}

// Decreases the deliveryman's current capacity
void Request::decreaseDeliverymanCapacity(Deliveryman& deliveryman) {
    deliveryman.currentCapacity -= product.weight * quantity;
}

// Increases the deliveryman's current capacity
void Request::increaseDeliverymanCapacity(Deliveryman& deliveryman) {
    deliveryman.currentCapacity += product.weight * quantity;
}

// Updates the distribution center's inventory
void Request::updateDistributionCenterInventory(DistributionCenter& dc) {
    for (auto& [prod, quant] : dc.inventory) {
        if (prod.name == product.name) {
            quant -= quantity;
            return;
        }
    }
}

// Displays the information of the request
void Request::displayInfo() const {
    cout << "Request:" << endl;
    cout << "Client: " << client.name << endl;
    cout << "Seller: " << seller.name << endl;
    cout << "Product: " << product.name << " | Quantity: " << quantity << endl;
    cout << endl;
}
