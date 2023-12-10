#include "../src/Elements.cpp"
#include "../src/Request.cpp"

int main() {
    DistributionCenter dc("DC 1", "123 Main St", 1);
    Product p1("Cervejinha", 5.0, 10.0);
    Product p2("Suco de uva", 1.5, 15.0);
    Product p3("Carne", 3.0, 20.0);
    dc.addProduct(p1, 30);
    dc.addProduct(p2, 60);
    dc.addProduct(p3, 40);
    dc.displayInfo();

    Seller seller("Chico Moedas", "Galeto Sat's", 20);
    seller.addProduct(p1);
    seller.addProduct(p2);
    seller.addProduct(p3);
    seller.displayInfo();

    Client client("Luisa Sonza", "Praia do Flamengo", 3);
    client.displayInfo();

    Deliveryman deliveryman("Whindersson Nunes", "Praia de Botafogo", 1, "Car", 100.0);
    deliveryman.displayInfo();

    Request request(client, seller, p1, 5);
    request.displayInfo();
    
    cout << "Entregador busca o produto no centro de distribuição, então diminuimos a capacidade do transporte e a quantidade no estoque" << endl;
    request.decreaseDeliverymanCapacity(deliveryman);
    request.updateDistributionCenterInventory(dc);
    deliveryman.displayInfo();
    dc.displayInfo();

    cout << "Entregador leva o produto até o cliente, então recupera a capacidade do carro:" << endl;
    request.increaseDeliverymanCapacity(deliveryman);
    deliveryman.displayInfo();

    return 0;
}