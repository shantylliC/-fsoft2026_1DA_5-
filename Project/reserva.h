//
// Created by Utilizador on 01-Jun-26.
//

#ifndef FSOFT2026_1DA_5_VIAGEM_H
#define FSOFT2026_1DA_5_VIAGEM_H
#include "alt_estados/Modelo/alt_estados_modelo.h"
#include "alt_estados/Controlador/alt_estados_controller.h"
#include "alt_estados/View/alt_estados_view.h"
#include "numero_de_reserva/Modelo/n_reserva_modelo.h"
#include "numero_de_reserva/Controlador/n_reserva_controlador.h"
#include "numero_de_reserva/View/n_reserva_view.h"
#include "titulo_notas/Modelo/titulo_notas_modelo.h"
#include "titulo_notas/Controlador/titulo_notas_controlador.h"
#include "titulo_notas/View/titulo_notas_view.h"
#include "pagamento.h"
#include "data.h"

class Viagem : public Data,public Numero_reserva_modelo, public Pagamento, public Titulo_notas_modelo {
private:
    Data data;

public:
    Viagem();
    void print() const;
    bool gravarFicheiro() const;
};
#endif //FSOFT2026_1DA_5_VIAGEM_H