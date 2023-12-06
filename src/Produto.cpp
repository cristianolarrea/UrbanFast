#include "Produto.hpp"

Produto::Produto(double peso, double preco) : peso(peso), preco(preco) {}

double Produto::getPeso() const {
    return peso;
}

double Produto::getPreco() const {
    return preco;
}
