#include <gtest/gtest.h>
#include "../AutenticacaoService/AutenticacaoService.h"

// Teste de Idade Mínima: Caso Válido
TEST(AutenticacaoServiceTest, OrganizadorTemIdadeMinima_Idade20_RetornaTrue) {
    // Arrange
    AutenticacaoService service;
    Organizador org;
    org.colocarIdade(20);

    // Act
    bool podeSerOrganizador = service.organizadorTemIdadeMinima(org);

    // Assert
    EXPECT_TRUE(podeSerOrganizador);
}

// Teste de Idade Mínima: Caso Inválido
TEST(AutenticacaoServiceTest, OrganizadorTemIdadeMinima_Idade17_RetornaFalse) {
    // Arrange
    AutenticacaoService service;
    Organizador org;
    org.colocarIdade(17);

    // Act
    bool podeSerOrganizador = service.organizadorTemIdadeMinima(org);

    // Assert
    EXPECT_FALSE(podeSerOrganizador);
}

// Teste de Idade Mínima: Caso Limite (Exatamente 18 anos)
TEST(AutenticacaoServiceTest, OrganizadorTemIdadeMinima_Idade18_RetornaTrue) {
    // Arrange
    AutenticacaoService service;
    Organizador org;
    org.colocarIdade(18);

    // Act
    bool podeSerOrganizador = service.organizadorTemIdadeMinima(org);

    // Assert
    EXPECT_TRUE(podeSerOrganizador);
}