#include "Pedido.hpp"

Pedido::Pedido(std::vector<std::tuple<Produto, No, No>> produtos, No::Tipo tipoPedido)
    : produtos(produtos), tipoPedido(tipoPedido) {}
