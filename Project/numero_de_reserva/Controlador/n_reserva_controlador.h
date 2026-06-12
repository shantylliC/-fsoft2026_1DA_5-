//
// Created by Utilizador on 12-Jun-26.
//

#ifndef FSOFT2026_1DA_5_NUMERO_RESERVA_H
#define FSOFT2026_1DA_5_NUMERO_RESERVA_H

#include "numero_reserva.h"
#include "numero_reserva_view.h"

class Numero_reserva_controller {
private:
    Numero_reserva modelo;
    Numero_reserva_view view;
public:
    void mostrar();
    void gerarNovaReserva();
    int getNumeroAtual() const;
};

#endif //FSOFT2026_1DA_5_NUMERO_RESERVA_H