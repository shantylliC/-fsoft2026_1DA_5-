//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_ROTEIROVIEW_H
#define PROJETOVIAGENS_ROTEIROVIEW_H


#include <iostream>
#include <vector>
#include "LocalidadeModel.h"
#include "Financeiro.h"

class RoteiroView {
public:
    void mostrarMensagem(std::string mensagem) const;
    void mostrarErro(std::string erro) const;
    void mostrarTalao(const std::vector<LocalidadeModel*>& escolhas, double base, double iva, double total) const;

    int pedirMetodoPagamento() const;

};


#endif //PROJETOVIAGENS_ROTEIROVIEW_H