#include <gtest/gtest.h>
#include "AtividadeModel.h"

// ==================================================
// TESTES UNITÁRIOS PARA O MODELO DA ATIVIDADE
// ==================================================

TEST(TesteAtividadeModelo, construtorPadrao) {
    // Arrange & Act: Criação do objeto utilizando o construtor sem parâmetros
    AtividadeModel atividadeInstanciada;

    // Assert: Verificação se os atributos de fábrica iniciam zerados ou vazios
    EXPECT_EQ(atividadeInstanciada.obterID(), 0);
    EXPECT_EQ(atividadeInstanciada.obterNome(), "");
    EXPECT_EQ(atividadeInstanciada.obterIdCidade(), 0);
    EXPECT_DOUBLE_EQ(atividadeInstanciada.obterPreco(), 0.0);
}

TEST(TesteAtividadeModelo, construtorParametrizado) {
    // Arrange: Definição dos parâmetros por extenso para alimentar o construtor
    int identificadorEsperado = 105;
    std::string nomeEsperado = "Passeio de Barco";
    int identificadorCidadeEsperado = 25;
    double precoEsperado = 45.00;

    // Act: Criação do objeto passando todas as variáveis configuradas
    AtividadeModel atividadeInstanciada(identificadorEsperado, nomeEsperado, identificadorCidadeEsperado, precoEsperado);

    // Assert: Validação se os métodos de leitura devolvem a informação correta
    EXPECT_EQ(atividadeInstanciada.obterID(), identificadorEsperado);
    EXPECT_EQ(atividadeInstanciada.obterNome(), nomeEsperado);
    EXPECT_EQ(atividadeInstanciada.obterIdCidade(), identificadorCidadeEsperado);
    EXPECT_DOUBLE_EQ(atividadeInstanciada.obterPreco(), precoEsperado);
}

TEST(TesteAtividadeModelo, carregarDeLinhaValida) {
    // Arrange: Configuração de uma linha estruturada (pais;cidade;atividade;nome;preco)
    // Nota: O código da atividade deve ignorar o primeiro valor (351)
    AtividadeModel atividadeInstanciada;
    std::string linhaEntrada = "351;25;105;Passeio de Barco;45.00";


    atividadeInstanciada.carregarDeLinha(linhaEntrada);

    // Assert: Garantia de que o salto do país funcionou e os dados foram guardados
    EXPECT_EQ(atividadeInstanciada.obterIdCidade(), 25);
    EXPECT_EQ(atividadeInstanciada.obterID(), 105);
    EXPECT_EQ(atividadeInstanciada.obterNome(), "Passeio de Barco");
    EXPECT_DOUBLE_EQ(atividadeInstanciada.obterPreco(), 45.00);
}


TEST(TesteAtividadeModelo, carregarComPrecoNegativoLancaExcecao) {
    AtividadeModel atividadeInstanciada;
    std::string linhaInvalida = "1;5;101;Passeio de Metro;-5.0";

    EXPECT_THROW({
        atividadeInstanciada.carregarDeLinha(linhaInvalida);
    }, PrecoInvalidoException);
}
