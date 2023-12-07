#include "../src/Nodes.cpp"

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
    seller.addProduct(Product("Cervejinha", 2.0, 10.0));
    seller.addProduct(Product("Suco de uva", 1.5, 15.0));
    seller.addProduct(Product("Carne", 3.0, 20.0));
    seller.displayInfo();

    Client client("Luisa Sonza", "Praia do Flamengo", 3);
    client.displayInfo();

    Deliveryman deliveryman("Whindersson Nunes", "Praia de Botafogo", 1, "Car", 100.0);
    deliveryman.displayInfo();

    Request request(client, seller, p1, 5);
    request.displayInfo();
    
    cout << "Entregador busca o produto no centro de distribuição:" << endl;
    request.decreaseDeliverymanCapacity(deliveryman);
    request.updateDistributionCenterInventory(dc);
    deliveryman.displayInfo();
    dc.displayInfo();

    cout << "Entregador leva o produto até o cliente:" << endl;
    request.increaseDeliverymanCapacity(deliveryman);
    deliveryman.displayInfo();

    return 0;
}