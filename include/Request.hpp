#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "Nodes.hpp"

class Request {
public:
    Client client;
    Seller seller;
    Product product;
    int quantity;

    Request(const Client& cn, const Seller& sn, const Product& pn, int q);

    void decreaseDeliverymanCapacity(Deliveryman& deliveryman);
    void increaseDeliverymanCapacity(Deliveryman& deliveryman);
    void updateDistributionCenterInventory(DistributionCenter& dc);
    void displayInfo() const;
};

#endif 
