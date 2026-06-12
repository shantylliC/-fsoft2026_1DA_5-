//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_ROTEIROCONTROLLER_H
#define PROJETOVIAGENS_ROTEIROCONTROLLER_H



#include "RoteiroModel.h"
#include "RoteiroView.h"
#include "Financeiro.h"

class RoteiroController {
private:
    RoteiroModel model;
    RoteiroView view;

public:
    RoteiroController();

    void registarEscolha(LocalidadeModel* localidadeSelecionada);
    void esvaziarRoteiro();
    void mostrarResumo();
    void finalizarEGravar();

    void alterarMetodoPagamento();
};


#endif //PROJETOVIAGENS_ROTEIROCONTROLLER_H