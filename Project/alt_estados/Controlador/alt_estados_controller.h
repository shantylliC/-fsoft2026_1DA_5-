//
// Created by Utilizador on 12-Jun-26.
//

#ifndef _FSOFT2026_1DA_5__ALT_ESTADOS_CONTROLLER_H
#define _FSOFT2026_1DA_5__ALT_ESTADOS_CONTROLLER_H

#include "alt_estados/Modelo/alt_estados_modelo.h"
#include "alt_estados/View/alt_estados_view.h"

class AltEstadosController {
private:
    AltEstadosModel model;
    AltEstadosView  view;
public:
    AltEstadosController();

    void confirmar();
    void cancelar();
    void mostrarEstado() const;
};

#endif //_FSOFT2026_1DA_5__ALT_ESTADOS_CONTROLLER_H