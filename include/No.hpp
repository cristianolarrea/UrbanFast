#ifndef NO_HPP
#define NO_HPP

class No {
public:
    enum Tipo { VENDEDOR, CLIENTE, ENTREGADOR, CENTRO_DISTRIBUICAO };
    No(Tipo tipo);

    Tipo getTipo() const;

private:
    Tipo tipo;
};

#endif
