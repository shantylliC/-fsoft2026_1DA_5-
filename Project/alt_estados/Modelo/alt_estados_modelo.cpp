//
// Created by Utilizador on 12-Jun-26.
//

#include <string>
#include "alt_estados_modelo.h"

AltEstadosModel::AltEstadosModel() {
    estado = 0;
}

unsigned char AltEstadosModel::getEstado() const {
    return estado;
}

std::string AltEstadosModel::getEstadoStr() const {
    switch (estado) {
        case 0: return "Pendente";
        case 1: return "Confirmada";
        case 2: return "Cancelada";
        default: return "Erro";
    }
}

void AltEstadosModel::confirmar() {
    estado = 1;
}

void AltEstadosModel::cancelar() {
    estado = 2;
}