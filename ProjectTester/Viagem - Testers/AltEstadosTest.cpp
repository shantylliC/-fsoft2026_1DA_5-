//
// Created by Utilizador on 13-Jun-26.
//

#include <gtest/gtest.h>
#include "alt_estados/Modelo/alt_estados_modelo.h"

// --- Construtor ---

TEST(AltEstadosTest, EstadoInicialEhPendente) {
    // Arrange
    AltEstadosModel model;

    // Act
    unsigned char estado = model.getEstado();

    // Assert
    EXPECT_EQ(estado, 0);
}

TEST(AltEstadosTest, EstadoInicialStrEhPendente) {
    // Arrange
    AltEstadosModel model;

    // Act
    std::string estadoStr = model.getEstadoStr();

    // Assert
    EXPECT_EQ(estadoStr, "Pendente");
}

// --- confirmar() ---

TEST(AltEstadosTest, ConfirmarAlteraEstadoParaConfirmada) {
    // Arrange
    AltEstadosModel model;

    // Act
    model.confirmar();

    // Assert
    EXPECT_EQ(model.getEstado(), 1);
    EXPECT_EQ(model.getEstadoStr(), "Confirmada");
}

// --- cancelar() ---

TEST(AltEstadosTest, CancelarAlteraEstadoParaCancelada) {
    // Arrange
    AltEstadosModel model;

    // Act
    model.cancelar();

    // Assert
    EXPECT_EQ(model.getEstado(), 2);
    EXPECT_EQ(model.getEstadoStr(), "Cancelada");
}

// --- Sequência confirmar -> cancelar ---

TEST(AltEstadosTest, ConfirmarDepoisCancelar) {
    // Arrange
    AltEstadosModel model;

    // Act
    model.confirmar();
    model.cancelar();

    // Assert
    EXPECT_EQ(model.getEstado(), 2);
    EXPECT_EQ(model.getEstadoStr(), "Cancelada");
}

// --- getEstadoStr para valor "Erro" ---
// Nota: só testável se houver forma de forçar um valor inválido.
// Se "estado" for protected sem setter direto, este caso não é testável
// a não ser que crieis uma subclasse de teste (friend class ou setter para testes).