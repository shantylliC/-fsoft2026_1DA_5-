#include <gtest/gtest.h>
#include "../Pessoa/Pessoa.h"

// Teste ao Construtor do Organizador
TEST(OrganizadorTest, ConstrutorDefault_IniciaSemViajantes) {
    // Arrange & Act
    Organizador org;

    // Assert
    EXPECT_EQ(org.obterNumeroViajantes(), 0);
    EXPECT_TRUE(org.obterViajantes().empty());
}

// Teste à função de adicionar viajante
TEST(OrganizadorTest, AdicionarViajante_AumentaO_NumeroDeViajantes) {
    // Arrange
    Organizador org;
    Viajante v;
    v.colocarNome("Carlos");

    // Act
    org.adicionarViajante(v);

    // Assert
    EXPECT_EQ(org.obterNumeroViajantes(), 1);
    EXPECT_EQ(org.obterViajantes()[0].obterNome(), "Carlos");
}

// Teste isolado para a função de contar viajantes
TEST(OrganizadorTest, ObterNumeroViajantes_RetornaContagemCorreta) {
    // Arrange
    Organizador org;
    Viajante v1, v2;
    org.adicionarViajante(v1);
    org.adicionarViajante(v2);

    // Act
    std::size_t total = org.obterNumeroViajantes();

    // Assert
    EXPECT_EQ(total, 2);
}

// Teste à função de limpar o vetor
TEST(OrganizadorTest, LimparViajantes_EsvaziaALista) {
    // Arrange
    Organizador org;
    Viajante v1;
    org.adicionarViajante(v1);

    // Act
    org.limparViajantes();

    // Assert
    EXPECT_EQ(org.obterNumeroViajantes(), 0);
    EXPECT_TRUE(org.obterViajantes().empty());
}

// Teste de Substituição: Índice Válido (Caminho de Sucesso)
TEST(OrganizadorTest, SubstituirViajante_IndiceValido_AlteraO_Viajante) {
    // Arrange
    Organizador org;
    Viajante vAntigo;
    vAntigo.colocarNome("Antigo");
    org.adicionarViajante(vAntigo);

    Viajante vNovo;
    vNovo.colocarNome("Novo");

    // Act
    bool resultado = org.substituirViajante(0, vNovo);

    // Assert
    EXPECT_TRUE(resultado);
    EXPECT_EQ(org.obterViajantes()[0].obterNome(), "Novo");
}

// Teste de Substituição: Índice Inválido (Caminho de Erro/Segurança)
TEST(OrganizadorTest, SubstituirViajante_IndiceInvalido_RetornaFalso) {
    // Arrange
    Organizador org; // Vetor vazio, logo o índice 0 não existe
    Viajante vNovo;

    // Act
    bool resultado = org.substituirViajante(0, vNovo);

    // Assert
    EXPECT_FALSE(resultado);
}