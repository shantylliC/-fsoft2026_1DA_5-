#include <gtest/gtest.h>
#include "CidadeModel.h"

// ==================================================
// TESTES UNITÁRIOS PARA O MODELO DA CIDADE
// ==================================================

TEST(TesteCidadeModelo, construtorPadrao) {
    // Arrange & Act: Criação do objeto utilizando o construtor sem parâmetros
    CidadeModel cidadeInstanciada;

    // Assert: Verificação se os atributos de fábrica iniciam zerados ou vazios
    EXPECT_EQ(cidadeInstanciada.obterID(), 0);
    EXPECT_EQ(cidadeInstanciada.obterNome(), "");
    EXPECT_EQ(cidadeInstanciada.obterIdPais(), 0);
    EXPECT_DOUBLE_EQ(cidadeInstanciada.obterPreco(), 0.0);
}

TEST(TesteCidadeModelo, construtorParametrizado) {
    // Arrange: Definição dos parâmetros por extenso para alimentar o construtor
    int identificadorEsperado = 25;
    std::string nomeEsperado = "Porto";
    int identificadorPaisEsperado = 351;
    double precoEsperado = 85.50;

    // Act: Criação do objeto passando todas as variáveis configuradas
    CidadeModel cidadeInstanciada(identificadorEsperado, nomeEsperado, identificadorPaisEsperado, precoEsperado);

    // Assert: Validação se os métodos de leitura devolvem a informação correta
    EXPECT_EQ(cidadeInstanciada.obterID(), identificadorEsperado);
    EXPECT_EQ(cidadeInstanciada.obterNome(), nomeEsperado);
    EXPECT_EQ(cidadeInstanciada.obterIdPais(), identificadorPaisEsperado);
    EXPECT_DOUBLE_EQ(cidadeInstanciada.obterPreco(), precoEsperado);
}

TEST(TesteCidadeModelo, carregarDeLinhaValida) {
    // Arrange: Configuração do cenário com uma linha estruturada (pais;id;nome;preco)
    CidadeModel cidadeInstanciada;
    std::string linhaEntrada = "351;25;Porto;85.50";

    cidadeInstanciada.carregarDeLinha(linhaEntrada);

    // Assert: Garantia de que cada segmento do texto foi guardado no atributo correto
    EXPECT_EQ(cidadeInstanciada.obterIdPais(), 351);
    EXPECT_EQ(cidadeInstanciada.obterID(), 25);
    EXPECT_EQ(cidadeInstanciada.obterNome(), "Porto");
    EXPECT_DOUBLE_EQ(cidadeInstanciada.obterPreco(), 85.50);
}


TEST(TesteCidadeModelo, carregarComIDInvalidoLancaExcecao) {
    CidadeModel cidadeInstanciada;
    std::string linhaComIdNegativo = "1;-5;Coimbra;30.0";

    EXPECT_THROW({
        cidadeInstanciada.carregarDeLinha(linhaComIdNegativo);
    }, IDInvalidoException);
}

TEST(TesteCidadeModelo, carregarComNomeVazioLancaExcecao) {
    CidadeModel cidadeInstanciada;
    std::string linhaComNomeVazio = "1;12;;30.0";

    EXPECT_THROW({
        cidadeInstanciada.carregarDeLinha(linhaComNomeVazio);
    }, ErroFormatacaoFicheiroException);
}

TEST(TesteCidadeModelo, carregarComPrecoNegativoLancaExcecao) {
    CidadeModel cidadeInstanciada;
    std::string linhaComPrecoNegativo = "1;15;Faro;-15.0";

    EXPECT_THROW({
        cidadeInstanciada.carregarDeLinha(linhaComPrecoNegativo);
    }, PrecoInvalidoException);
}
