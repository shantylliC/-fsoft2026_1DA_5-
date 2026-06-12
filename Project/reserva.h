//
// Created by Utilizador on 01-Jun-26.
//

#ifndef FSOFT2026_1DA_5_VIAGEM_H
#define FSOFT2026_1DA_5_VIAGEM_H
#include "alt_estados/Modelo/alt_estados_modelo.h"
#include "alt_estados/Modelo/alt_estados_controler.h"
#include "numero_de_reserva/Modelo/n_reserva_modelo.h"
#include "pagamento.h"
#include "titulo_notas/titulo_esub.h"
#include "data.h"


class Viagem : public Data, public alt_estados, public Numero_reserva_modelo, public Pagamento, public Titulo_notas_modelos{
private:
    Data data;

public:
    Viagem();
    void print() const;
    bool gravarFicheiro() const;
};
#endif //FSOFT2026_1DA_5_VIAGEM_H