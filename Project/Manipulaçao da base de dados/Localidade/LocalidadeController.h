//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_LOCALIDADECONTROLLER_H
#define PROJETOVIAGENS_LOCALIDADECONTROLLER_H


#include "LocalidadeModel.h"
#include "LocalidadeView.h"

class LocalidadeController {
private:
    LocalidadeView view;

public:
    LocalidadeController() {}

    // ESTA FUNÇÃO AGORA SERVE PARA TUDO!
    void gerirApresentacao(LocalidadeModel* localidade);
};


#endif //PROJETOVIAGENS_LOCALIDADECONTROLLER_H