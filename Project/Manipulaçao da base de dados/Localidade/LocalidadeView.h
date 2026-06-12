//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_LOCALIDADEVIEW_H
#define PROJETOVIAGENS_LOCALIDADEVIEW_H


#include <iostream>
#include "LocalidadeModel.h"

class LocalidadeView {
public:

    void mostrarDados(const LocalidadeModel* localidade) const;
    void mostrarErroFicheiro() const;
};


#endif //PROJETOVIAGENS_LOCALIDADEVIEW_H