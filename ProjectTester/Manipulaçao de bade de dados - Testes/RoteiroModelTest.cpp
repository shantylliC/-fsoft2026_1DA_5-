
#include <gtest/gtest.h>
#include "RoteiroModel.h"
#include "LocalidadeModel.h"

// Classe de suporte para conseguirmos testar o roteiro sem depender de ficheiros externos
class TesteLocalidade : public LocalidadeModel {
private:
    double precoMocado;
public:
    TesteLocalidade(int identificador, std::string nome, double precoDefinido) 
        : LocalidadeModel(identificador, nome), precoMocado(precoDefinido) {}
    
    double obterPreco() const override { return precoMocado; }
    void carregarDeLinha(std::string linha) override {}
};

// ==================================================
// TESTES UNITÁRIOS PARA O MODELO DO ROTEIRO
// ==================================================

TEST(TesteRoteiroModelo, construtorPadrao) {
    // Arrange & Act: Criação da instância principal do roteiro
    RoteiroModel roteiroInstanciado;

    // Assert: Confirmação de que a lista de escolhas nasce completamente vazia
    EXPECT_TRUE(roteiroInstanciado.obterEscolhas().empty());
}

TEST(TesteRoteiroModelo, adicionarEscolhaValida) {
    // Arrange: Preparação do roteiro e de uma localidade simulada
    RoteiroModel roteiroInstanciado;
    TesteLocalidade localidadeTeste(10, "Coimbra", 25.50);

    // Act: Inserção da localidade dentro da lista de escolhas
    roteiroInstanciado.adicionarEscolha(&localidadeTeste);

    // Assert: Verificação de que a lista aumentou e contém o item correto
    EXPECT_EQ(roteiroInstanciado.obterEscolhas().size(), 1);
    EXPECT_EQ(roteiroInstanciado.obterEscolhas()[0]->obterNome(), "Coimbra");
}

TEST(TesteRoteiroModelo, adicionarEscolhaNula) {
    // Arrange: Preparação do roteiro e de um ponteiro vazio (para simular um erro)
    RoteiroModel roteiroInstanciado;
    LocalidadeModel* ponteiroNulo = nullptr;

    // Act: Tentativa de adicionar o ponteiro vazio à lista
    roteiroInstanciado.adicionarEscolha(ponteiroNulo);

    // Assert: Garantia de que a função deteta o nulo e não adiciona nada à lista
    EXPECT_TRUE(roteiroInstanciado.obterEscolhas().empty());
}

TEST(TesteRoteiroModelo, esvaziarRoteiro) {
    // Arrange: Criação de um roteiro preenchido com um item
    RoteiroModel roteiroInstanciado;
    TesteLocalidade localidadeTeste(5, "Braga", 15.00);
    roteiroInstanciado.adicionarEscolha(&localidadeTeste);

    // Act: Acionamento do mecanismo de limpeza da lista
    roteiroInstanciado.esvaziar();

    // Assert: Confirmação de que o roteiro voltou ao estado vazio
    EXPECT_TRUE(roteiroInstanciado.obterEscolhas().empty());
}

TEST(TesteRoteiroModelo, gravarFicheiroVazio) {
    RoteiroModel roteiroInstanciado;

    // Act: Passar os 9 parâmetros exigidos pela nova assinatura do Modelo
    bool resultadoGravacao = roteiroInstanciado.gravarFicheiroReserva(
        1, "Pendente", "Viagem de Teste", "Sem notas", "12/06/2026", "15/06/2026", 3, 0.0, 0.0
    );

    // Assert: Como o roteiro está vazio, deve retornar falso
    EXPECT_FALSE(resultadoGravacao);
}

TEST(TesteRoteiroModelo, gravarFicheiroPreenchido) {
    RoteiroModel roteiroInstanciado;
    TesteLocalidade localidadeTeste(1, "Faro", 100.0);
    roteiroInstanciado.adicionarEscolha(&localidadeTeste);

    // Act: Passar os 9 parâmetros exigidos
    bool resultadoGravacao = roteiroInstanciado.gravarFicheiroReserva(
        1, "Confirmada", "Ferias de Verao", "Levar protetor", "12/06/2026", "19/06/2026", 7, 100.0, 123.0
    );

    EXPECT_TRUE(resultadoGravacao);
  
}
