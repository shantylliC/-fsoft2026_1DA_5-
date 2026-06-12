//
// Created by Utilizador on 12-Jun-26.
//

#include "numero_de_reserva/Modelo/n_reserva_modelo.h"

Numero_reserva_modelo::Numero_reserva_modelo() {
    numeroReserva = 1;
}

int Numero_reserva_modelo::getNumeroReserva() const {
    return numeroReserva;
}

void Numero_reserva_modelo::incrementar() {
    numeroReserva++;
}
