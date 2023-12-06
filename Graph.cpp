#include <string>
#include <vector>
#include <map>

class Produto {
public:
    double peso;
    double preco;
    Produto(double p, double pr) : peso(p), preco(pr) {}
};

class Catalogo {
public:
    std::vector<Produto> produtos;
    void adicionarProduto(const Produto& produto) {
        produtos.push_back(produto);
    }
};

class Vendedor {
public:
    Catalogo catalogo;
    Produto produto;
};

class Endereco {
public:
    std::string rua;
    std::string cidade;
    std::string estado;
    std::string cep;
};

class Cliente {
public:
    Endereco enderecoEntrega;
};

class Veiculo {
public:
    double pesoMaximo;
    Veiculo(double pesoMax) : pesoMaximo(pesoMax) {}
};

class Entregador {
public:
    Veiculo veiculo;
    Entregador(const Veiculo& v) : veiculo(v) {}
    
};

class CentroDistribuicao {
public:
    std::map<Produto, int> inventario; 
    
};

int main() {
    Produto produto1(2.5, 100.0); 
    Vendedor vendedor;
    vendedor.catalogo.adicionarProduto(produto1);

    Veiculo veiculo(500.0); 
    Entregador entregador(veiculo);

}
