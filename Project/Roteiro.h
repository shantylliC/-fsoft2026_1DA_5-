//
// Created by HQCamachoPC on 08/05/2026.
//

#ifndef PROJETOVIAGENS_ROTEIRO_H
#define PROJETOVIAGENS_ROTEIRO_H

#include <vector>
#include <string>
#include <iostream>
#include "Localidade.h"
#include "Financeiro.h"

class Roteiro {
private:
    // Guarda exclusivamente os endereços das escolhas do utilizador
    std::vector<Localidade*> listaPonteirosEscolhidos;

public:
    Roteiro();
    virtual ~Roteiro();

    void registarEscolha(Localidade* ponteiroParaAdicionar);
    void esvaziarRoteiro();
    void mostrarResumo();
    void gravarFicheiro();
};

#endif // ROTEIRO_H