#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "Elements.hpp"

class Request {
public:
    Client client;
    Seller seller;
    Product product;
    int quantity;
    bool is_optimized;

    Request(const Client& cn, const Seller& sn, const Product& pn, int q, bool o);

    void decreaseDeliverymanCapacity(Deliveryman& deliveryman);
    void increaseDeliverymanCapacity(Deliveryman& deliveryman);
    void updateDistributionCenterInventory(DistributionCenter& dc);
    void displayInfo() const;
};

#endif 
