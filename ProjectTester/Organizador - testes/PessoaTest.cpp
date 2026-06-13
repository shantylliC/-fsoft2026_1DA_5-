#include <gtest/gtest.h>
#include "../Pessoa/Pessoa.h" // Ajusta o caminho conforme a tua estrutura de pastas

// Teste ao Construtor por Omissão (Default)
TEST(PessoaTest, ConstrutorPorOmissao_InicializaIdadeAZero) {
    // Arrange & Act
    Pessoa p;

    // Assert
    EXPECT_EQ(p.obterIdade(), 0);
    EXPECT_TRUE(p.obterNome().empty());
}

// Teste ao Construtor Parametrizado
TEST(PessoaTest, ConstrutorParametrizado_AtribuiDadosCorretamente) {
    // Arrange
    std::string nomeEsperado = "Joao Silva";
    int idadeEsperada = 30;
    std::string emailEsperado = "joao@email.com";
    std::string biEsperado = "12345678";
    std::string validadeEsperada = "12/2028";

    // Act
    Pessoa p(nomeEsperado, idadeEsperada, emailEsperado, biEsperado, validadeEsperada);

    // Assert
    EXPECT_EQ(p.obterNome(), nomeEsperado);
    EXPECT_EQ(p.obterIdade(), idadeEsperada);
    EXPECT_EQ(p.obterEmail(), emailEsperado);
    EXPECT_EQ(p.obterBI(), biEsperado);
    EXPECT_EQ(p.obterValidade(), validadeEsperada);
}

// Teste individual ao Setter e Getter do Nome
TEST(PessoaTest, ColocarEObterNome_Sucesso) {
    // Arrange
    Pessoa p;
    std::string nomeEsperado = "Ana";

    // Act
    p.colocarNome(nomeEsperado);

    // Assert
    EXPECT_EQ(p.obterNome(), nomeEsperado);
}

// Teste individual ao Setter e Getter do Email
TEST(PessoaTest, ColocarEObterEmail_Sucesso) {
    // Arrange
    Pessoa p;
    std::string emailEsperado = "ana@mail.com";

    // Act
    p.colocarEmail(emailEsperado);

    // Assert
    EXPECT_EQ(p.obterEmail(), emailEsperado);
}

// Teste individual ao Setter e Getter do BI
TEST(PessoaTest, ColocarEObterBI_Sucesso) {
    // Arrange
    Pessoa p;
    std::string biEsperado = "98765432";

    // Act
    p.colocarBI(biEsperado);

    // Assert
    EXPECT_EQ(p.obterBI(), biEsperado);
}

// Teste individual ao Setter e Getter da Validade
TEST(PessoaTest, ColocarEObterValidade_Sucesso) {
    // Arrange
    Pessoa p;
    std::string validadeEsperada = "10/2025";

    // Act
    p.colocarValidade(validadeEsperada);

    // Assert
    EXPECT_EQ(p.obterValidade(), validadeEsperada);
}

// Teste individual ao Setter e Getter da Idade
TEST(PessoaTest, ColocarEObterIdade_Sucesso) {
    // Arrange
    Pessoa p;
    int idadeEsperada = 40;

    // Act
    p.colocarIdade(idadeEsperada);

    // Assert
    EXPECT_EQ(p.obterIdade(), idadeEsperada);
}

// Teste ao Construtor da Classe Derivada Viajante (Mecânica de Herança)
TEST(ViajanteTest, ConstrutorDefault_InstanciaCorretamente) {
    // Arrange & Act
    Viajante v;

    // Assert
    EXPECT_EQ(v.obterIdade(), 0);
}