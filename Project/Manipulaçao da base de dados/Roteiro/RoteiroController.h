//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_ROTEIROCONTROLLER_H
#define PROJETOVIAGENS_ROTEIROCONTROLLER_H



#include "RoteiroModel.h"
#include "RoteiroView.h"
#include "Financeiro.h"
#include "data.h"

class RoteiroController {
private:
    RoteiroModel model;
    RoteiroView view;
    Data datasDoRoteiro;

public:
    RoteiroController();

    void registarEscolha(LocalidadeModel* localidadeSelecionada);
    void esvaziarRoteiro();
    void mostrarResumo();
    void finalizarEGravar();
    void definirDatas(Data novasDatas);

    void alterarMetodoPagamento();
};


#endif //PROJETOVIAGENS_ROTEIROCONTROLLER_H