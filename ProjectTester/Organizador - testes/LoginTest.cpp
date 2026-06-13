#include <gtest/gtest.h>
#include "../Login/Login.h"

// Teste ao Construtor por Omissão
TEST(LoginTest, ConstrutorDefault_IniciaStringsVazias) {
    // Arrange & Act
    Login login;

    // Assert
    EXPECT_TRUE(login.obterEmail().empty());
    EXPECT_TRUE(login.obterPassword().empty());
}

// Teste ao Construtor Parametrizado
TEST(LoginTest, ConstrutorParametrizado_InicializaCorretamente) {
    // Arrange
    Organizador org;
    org.colocarNome("Admin");
    std::string email = "admin@empresa.pt";
    std::string pass = "pass123";

    // Act
    Login login(email, pass, org);

    // Assert
    EXPECT_EQ(login.obterEmail(), email);
    EXPECT_EQ(login.obterPassword(), pass);
    EXPECT_EQ(login.obterOrganizador().obterNome(), "Admin");
}

// Teste individual aos Setters e Getters de Credenciais
TEST(LoginTest, ColocarEObterEmailEPassword_Sucesso) {
    // Arrange
    Login login;

    // Act
    login.colocarEmail("teste@mail.com");
    login.colocarPassword("123");

    // Assert
    EXPECT_EQ(login.obterEmail(), "teste@mail.com");
    EXPECT_EQ(login.obterPassword(), "123");
}

// Teste individual ao Setter e Getter do Organizador associado
TEST(LoginTest, ColocarEObterOrganizador_Sucesso) {
    // Arrange
    Login login;
    Organizador org;
    org.colocarNome("Chefe de Viagem");

    // Act
    login.colocarOrganizador(org);

    // Assert
    EXPECT_EQ(login.obterOrganizador().obterNome(), "Chefe de Viagem");
}