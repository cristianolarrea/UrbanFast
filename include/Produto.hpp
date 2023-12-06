#ifndef PRODUTO_HPP
#define PRODUTO_HPP

class Produto {
public:
    Produto(double peso, double preco);
    double getPeso() const;
    double getPreco() const;

private:
    double peso;
    double preco;
};

#endif 