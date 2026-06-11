//
// Created by Utilizador on 01-Jun-26.
//

#ifndef FSOFT2026_1DA_5_VIAGEM_H
#define FSOFT2026_1DA_5_VIAGEM_H
#include "alt_estados.h"
#include "numero_reserva.h"
#include "pagamento.h"
#include "titulo_esub.h"
#include "data.h"


class Viagem : public Data, public alt_estados, public Numero_reserva, public Pagamento, public Titulo_esub{
private:
    Data data;

public:
    Viagem();
    void print() const;
    bool gravarFicheiro() const;
};
#endif //FSOFT2026_1DA_5_VIAGEM_H