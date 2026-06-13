//
// Created by Utilizador on 12-Jun-26.
//
#include "numero_de_reserva/Controlador/n_reserva_controlador.h"
void Numero_reserva_controller::mostrar() {
    view.mostrarNumeroReserva(modelo.getNumeroReserva());
}

void Numero_reserva_controller::gerarNovaReserva() {
    modelo.incrementar();
    view.mostrarMensagem("Nova reserva gerada.");
    mostrar();
}

int Numero_reserva_controller::getNumeroAtual() const {
    return modelo.getNumeroReserva();
}