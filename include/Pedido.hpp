#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "Produto.hpp"
#include "No.hpp"
#include <vector>
#include <tuple>

class Pedido {
public:
    Pedido(std::vector<std::tuple<Produto, No, No>> produtos, No::Tipo tipoPedido);

private:
    std::vector<std::tuple<Produto, No, No>> produtos;
    No::Tipo tipoPedido;
};

#endif 
