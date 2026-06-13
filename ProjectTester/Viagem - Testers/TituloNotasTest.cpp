//
// Created by Utilizador on 13-Jun-26.
//


#include <gtest/gtest.h>
#include "titulo_notas/Modelo/titulo_notas_modelo.h"

// --- Construtor ---

TEST(TituloNotasTest, ValoresIniciais) {
    // Arrange
    Titulo_notas_modelo modelo;

    // Act & Assert
    EXPECT_EQ(modelo.getTitulo(), "Sem título");
    EXPECT_EQ(modelo.getNotasViagem(), "");
}

// --- setTitulo() ---

TEST(TituloNotasTest, SetTituloValidoFuncionaERetornaTrue) {
    // Arrange
    Titulo_notas_modelo modelo;

    // Act
    bool resultado = modelo.setTitulo("Viagem a Paris");

    // Assert
    EXPECT_TRUE(resultado);
    EXPECT_EQ(modelo.getTitulo(), "Viagem a Paris");
}

TEST(TituloNotasTest, SetTituloMuitoCurtoFalha) {
    // Arrange
    Titulo_notas_modelo modelo;

    // Act
    bool resultado = modelo.setTitulo("ab"); // length == 2, <= 2 -> inválido

    // Assert
    EXPECT_FALSE(resultado);
    EXPECT_EQ(modelo.getTitulo(), "Sem título"); // não foi alterado
}

TEST(TituloNotasTest, SetTituloVazioFalha) {
    // Arrange
    Titulo_notas_modelo modelo;

    // Act
    bool resultado = modelo.setTitulo("");

    // Assert
    EXPECT_FALSE(resultado);
}

TEST(TituloNotasTest, SetTituloMuitoLongoFalha) {
    // Arrange
    Titulo_notas_modelo modelo;
    std::string tituloLongo(20, 'a'); // length == 20, >= 20 -> inválido

    // Act
    bool resultado = modelo.setTitulo(tituloLongo);

    // Assert
    EXPECT_FALSE(resultado);
    EXPECT_EQ(modelo.getTitulo(), "Sem título");
}

TEST(TituloNotasTest, SetTituloLimiteMinimoValido) {
    // Arrange
    Titulo_notas_modelo modelo;
    std::string titulo(3, 'a'); // length == 3, > 2 -> válido

    // Act
    bool resultado = modelo.setTitulo(titulo);

    // Assert
    EXPECT_TRUE(resultado);
    EXPECT_EQ(modelo.getTitulo(), titulo);
}

TEST(TituloNotasTest, SetTituloLimiteMaximoValido) {
    // Arrange
    Titulo_notas_modelo modelo;
    std::string titulo(19, 'a'); // length == 19, < 20 -> válido

    // Act
    bool resultado = modelo.setTitulo(titulo);

    // Assert
    EXPECT_TRUE(resultado);
    EXPECT_EQ(modelo.getTitulo(), titulo);
}

// --- setNotasViagem() ---

TEST(TituloNotasTest, SetNotasValidasFuncionaERetornaTrue) {
    // Arrange
    Titulo_notas_modelo modelo;

    // Act
    bool resultado = modelo.setNotasViagem("Levar protetor solar e passaporte.");

    // Assert
    EXPECT_TRUE(resultado);
    EXPECT_EQ(modelo.getNotasViagem(), "Levar protetor solar e passaporte.");
}

TEST(TituloNotasTest, SetNotasMuitoCurtasFalha) {
    // Arrange
    Titulo_notas_modelo modelo;

    // Act
    bool resultado = modelo.setNotasViagem("ok"); // length == 2, <= 2 -> inválido

    // Assert
    EXPECT_FALSE(resultado);
    EXPECT_EQ(modelo.getNotasViagem(), ""); // não foi alterado
}

TEST(TituloNotasTest, SetNotasMuitoLongasFalha) {
    // Arrange
    Titulo_notas_modelo modelo;
    std::string notasLongas(500, 'a'); // length == 500, >= 500 -> inválido

    // Act
    bool resultado = modelo.setNotasViagem(notasLongas);

    // Assert
    EXPECT_FALSE(resultado);
    EXPECT_EQ(modelo.getNotasViagem(), "");
}

TEST(TituloNotasTest, SetNotasLimiteMinimoValido) {
    // Arrange
    Titulo_notas_modelo modelo;
    std::string notas(3, 'a'); // length == 3, > 2 -> válido

    // Act
    bool resultado = modelo.setNotasViagem(notas);

    // Assert
    EXPECT_TRUE(resultado);
    EXPECT_EQ(modelo.getNotasViagem(), notas);
}

TEST(TituloNotasTest, SetNotasLimiteMaximoValido) {
    // Arrange
    Titulo_notas_modelo modelo;
    std::string notas(499, 'a'); // length == 499, < 500 -> válido

    // Act
    bool resultado = modelo.setNotasViagem(notas);

    // Assert
    EXPECT_TRUE(resultado);
    EXPECT_EQ(modelo.getNotasViagem(), notas);
}