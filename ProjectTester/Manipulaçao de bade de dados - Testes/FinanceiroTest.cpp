#include <gtest/gtest.h>
#include "Financeiro.h"
#include "LocalidadeModel.h"

// Classe de suporte para injetar preços controlados nos testes do motor financeiro
class TesteLocalidade : public LocalidadeModel {
private:
    double precoSimulado;
public:
    TesteLocalidade(int identificador, std::string nome, double precoDefinido) 
        : LocalidadeModel(identificador, nome), precoSimulado(precoDefinido) {}
    
    double obterPreco() const override { return precoSimulado; }
    void carregarDeLinha(std::string linha) override {}
};

// ==================================================
// TESTES UNITÁRIOS PARA O MOTOR FINANCEIRO
// ==================================================

TEST(TesteFinanceiroModelo, calcularTotalBaseListaVazia) {
    // Arrange: Preparação de uma lista completamente vazia
    std::vector<LocalidadeModel*> listaLocalidadesVazia;

    // Act: Execução do cálculo estático
    double resultadoCalculado = Financeiro::calcularTotalBase(listaLocalidadesVazia);

    // Assert: O total de uma lista vazia deve ser zero vírgula zero
    EXPECT_DOUBLE_EQ(resultadoCalculado, 0.0);
}

TEST(TesteFinanceiroModelo, calcularTotalBaseComElementos) {
    // Arrange: Criação de localidades com preços distintos e inserção na lista
    TesteLocalidade primeiraLocalidade(1, "Porto", 50.0);
    TesteLocalidade segundaLocalidade(2, "Lisboa", 150.0);
    
    std::vector<LocalidadeModel*> listaLocalidadesPreenchida;
    listaLocalidadesPreenchida.push_back(&primeiraLocalidade);
    listaLocalidadesPreenchida.push_back(&segundaLocalidade);

    // Act: Execução do cálculo da soma total acumulada
    double resultadoCalculado = Financeiro::calcularTotalBase(listaLocalidadesPreenchida);

    // Assert: Verificação se a soma corresponde exatamente ao esperado (50.0 + 150.0 = 200.0)
    EXPECT_DOUBLE_EQ(resultadoCalculado, 200.0);
}

TEST(TesteFinanceiroModelo, calcularTotalBaseComPonteiroNulo) {
    // Arrange: Configuração de uma lista que contém um ponteiro nulo para testar a segurança
    TesteLocalidade primeiraLocalidade(1, "Braga", 30.0);
    LocalidadeModel* ponteiroNulo = nullptr;

    std::vector<LocalidadeModel*> listaLocalidadesComNulo;
    listaLocalidadesComNulo.push_back(&primeiraLocalidade);
    listaLocalidadesComNulo.push_back(ponteiroNulo);


    double resultadoCalculado = Financeiro::calcularTotalBase(listaLocalidadesComNulo);

    // Assert: Garantia de que o código ignora o nulo com segurança e soma apenas o valor válido
    EXPECT_DOUBLE_EQ(resultadoCalculado, 30.0);
}

TEST(TesteFinanceiroModelo, calcularValorIva) {
    // Arrange: Definição de um valor base redondo para facilitar a conta matemática
    double valorBaseTeste = 100.0;
    double valorIvaEsperado = 23.0;

    // Act: Execução do cálculo isolado da taxa de imposto
    double resultadoCalculado = Financeiro::calcularValorIVA(valorBaseTeste);

    // Assert: Confirmação de que a taxa aplicada foi exatamente de vinte e três por cento
    EXPECT_DOUBLE_EQ(resultadoCalculado, valorIvaEsperado);
}

TEST(TesteFinanceiroModelo, calcularTotalComIva) {
    // Arrange: Configuração do cenário de teste para o montante final amealhado
    double valorBaseTeste = 100.0;
    double valorTotalEsperado = 123.0;

    // Act: Execução do cálculo do preço final acrescido do imposto
    double resultadoCalculado = Financeiro::calcularTotalComIVA(valorBaseTeste);

    // Assert: Validação matemática do resultado obtido
    EXPECT_DOUBLE_EQ(resultadoCalculado, valorTotalEsperado);
}

TEST(TesteFinanceiroModelo, gerirMetodosDePagamento) {
    // Act 1: Definir como Cartão
    Financeiro::definirMetodo(MetodoPagamento::CARTAO);
    // Assert 1: Validar armazenamento e conversão textual
    EXPECT_EQ(Financeiro::obterMetodoSelecionado(), MetodoPagamento::CARTAO);
    EXPECT_EQ(Financeiro::obterMetodoPagamentoComoString(), "Cartao");

    // Act 2: Alterar para Dinheiro
    Financeiro::definirMetodo(MetodoPagamento::DINHEIRO);
    // Assert 2: Validar a alteração do estado estático
    EXPECT_EQ(Financeiro::obterMetodoSelecionado(), MetodoPagamento::DINHEIRO);
    EXPECT_EQ(Financeiro::obterMetodoPagamentoComoString(), "Dinheiro");
}
