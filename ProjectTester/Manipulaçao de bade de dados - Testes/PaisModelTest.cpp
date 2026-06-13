#include <gtest/gtest.h>
#include "PaisModel.h"

// ==================================================
// TESTES UNITÁRIOS PARA O MODELO DO PAÍS
// ==================================================

TEST(TestePaisModelo, construtorPadrao) {
    // Arrange & Act: Criação do objeto utilizando o construtor sem parâmetros
    PaisModel paisInstanciado;

    // Assert: Verificação se os atributos iniciam com os valores de fábrica
    EXPECT_EQ(paisInstanciado.obterID(), 0);
    EXPECT_EQ(paisInstanciado.obterNome(), "");
    EXPECT_DOUBLE_EQ(paisInstanciado.obterPreco(), 0.0);
}

TEST(TestePaisModelo, construtorParametrizado) {
    // Arrange: Configuração dos elementos que serão injetados no construtor
    int identificadorEsperado = 351;
    std::string nomeEsperado = "Portugal";

    // Act: Criação do objeto com os parâmetros completamente por extenso
    PaisModel paisInstanciado(identificadorEsperado, nomeEsperado);

    // Assert: Validação se os métodos de leitura retornam os dados corretos
    EXPECT_EQ(paisInstanciado.obterID(), identificadorEsperado);
    EXPECT_EQ(paisInstanciado.obterNome(), nomeEsperado);
}

TEST(TestePaisModelo, carregarDeLinhaValida) {
    // Arrange: Preparação de uma linha de texto com o formato correto de leitura
    PaisModel paisInstanciado;
    std::string linhaEntrada = "1;Portugal";


    paisInstanciado.carregarDeLinha(linhaEntrada);

    // Assert: Verificação se o identificador e o nome foram extraídos com sucesso
    EXPECT_EQ(paisInstanciado.obterID(), 1);
    EXPECT_EQ(paisInstanciado.obterNome(), "Portugal");
}

TEST(TestePaisModelo, carregarDeLinhaInvalida) {
    // Arrange: Configuração de um cenário onde a linha não possui o separador correto
    int identificadorOriginal = 5;
    std::string nomeOriginal = "Franca";
    PaisModel paisInstanciado(identificadorOriginal, nomeOriginal);
    
    std::string linhaIncorreta = "TextoSemPontoEVirgula";

    // Act: Tentativa de processar a linha corrompida
    paisInstanciado.carregarDeLinha(linhaIncorreta);

    // Assert: Garantia de que o objeto rejeitou a leitura e manteve os dados antigos intactos
    EXPECT_EQ(paisInstanciado.obterID(), identificadorOriginal);
    EXPECT_EQ(paisInstanciado.obterNome(), nomeOriginal);
}
