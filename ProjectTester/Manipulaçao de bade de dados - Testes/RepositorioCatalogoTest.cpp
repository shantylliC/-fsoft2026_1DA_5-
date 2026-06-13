#include <gtest/gtest.h>
#include "RepositorioCatalogo.h"

// ==================================================
// TESTES UNITÁRIOS PARA O REPOSITÓRIO DO CATÁLOGO
// ==================================================

TEST(TesteRepositorioCatalogo, construtorPadrao) {
    // Arrange & Act: Criação da instância do repositório
    RepositorioCatalogo repositorioInstanciado;

    // Assert: Confirmação de que as listas começam completamente vazias e seguras
    EXPECT_TRUE(repositorioInstanciado.obterPaises().empty());
    EXPECT_TRUE(repositorioInstanciado.obterCidades().empty());
    EXPECT_TRUE(repositorioInstanciado.obterAtividades().empty());
}



TEST(TesteRepositorioCatalogo, carregarFicheirosInexistentesLancaExcecao) {
    // Arrange: Preparação do repositório
    RepositorioCatalogo repositorioInstanciado;

    // Act & Assert: Garantir que o sistema lança a exceção correta se os ficheiros sumirem
    EXPECT_THROW({
        repositorioInstanciado.carregarTudo();
    }, ErroFormatacaoFicheiroException);
}
