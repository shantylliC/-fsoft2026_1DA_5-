//
// Created by Utilizador on 12-Jun-26.
//

#ifndef FSOFT2026_1DA_5_N_RESERVA_CONTROLADOR_H
#define FSOFT2026_1DA_5_N_RESERVA_CONTROLADOR_H

#include "numero_de_reserva/Modelo/n_reserva_modelo.h"
#include "numero_de_reserva/View/n_reserva_view.h"

class Numero_reserva_controller {
private:
    Numero_reserva_modelo modelo;
    Numero_reserva_view view;
public:
    void mostrar();
    void gerarNovaReserva();
    int getNumeroAtual() const;
};

#endif //FSOFT2026_1DA_5_N_RESERVA_CONTROLADOR_H