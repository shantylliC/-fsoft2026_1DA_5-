//
// Created by Utilizador on 12-Jun-26.
//

#ifndef FSOFT2026_1DA_5_N_RESERVA_MODELO_H
#define FSOFT2026_1DA_5_N_RESERVA_MODELO_H

class Numero_reserva_modelo {
protected:
    int numeroReserva;
public:
    Numero_reserva_modelo();
    int getNumeroReserva() const;
    void incrementar();
};

#endif //FSOFT2026_1DA_5_N_RESERVA_MODELO_H