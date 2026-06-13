//
// Created by Utilizador on 13-Jun-26.
//

#include <gtest/gtest.h>
#include "numero_de_reserva/Modelo/n_reserva_modelo.h"

// --- Construtor ---

TEST(NumeroReservaTest, ValorInicialEhUm) {
    // Arrange
    Numero_reserva_modelo modelo;

    // Act
    int numero = modelo.getNumeroReserva();

    // Assert
    EXPECT_EQ(numero, 1);
}

// --- incrementar() ---

TEST(NumeroReservaTest, IncrementarAumentaUmaUnidade) {
    // Arrange
    Numero_reserva_modelo modelo;

    // Act
    modelo.incrementar();

    // Assert
    EXPECT_EQ(modelo.getNumeroReserva(), 2);
}

TEST(NumeroReservaTest, IncrementarVariasVezes) {
    // Arrange
    Numero_reserva_modelo modelo;

    // Act
    modelo.incrementar();
    modelo.incrementar();
    modelo.incrementar();

    // Assert
    EXPECT_EQ(modelo.getNumeroReserva(), 4);
}

// --- Dois objetos independentes ---

TEST(NumeroReservaTest, InstanciasSaoIndependentes) {
    // Arrange
    Numero_reserva_modelo modelo1;
    Numero_reserva_modelo modelo2;

    // Act
    modelo1.incrementar();
    modelo1.incrementar();

    // Assert
    EXPECT_EQ(modelo1.getNumeroReserva(), 3);
    EXPECT_EQ(modelo2.getNumeroReserva(), 1); // não afetado
}