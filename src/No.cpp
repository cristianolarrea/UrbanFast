#include "No.hpp"

No::No(Tipo tipo) : tipo(tipo) {}

No::Tipo No::getTipo() const {
    return tipo;
}
