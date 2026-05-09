//
// Created by HQCamachoPC on 08/05/2026.
//

#ifndef PROJETOVIAGENS_PAIS_H
#define PROJETOVIAGENS_PAIS_H

#include "Localidade.h"
#include <string>
#include <iostream>

class Pais : public Localidade {
public:
    // Construtores
    Pais() : Localidade() {}
    Pais(int _id, std::string _nome) : Localidade(_id, _nome) {}

    // Destrutor
    virtual ~Pais() {}

    // Implementação das funções obrigatórias (virtuais puras da Localidade)
    void carregarDeLinha(std::string linha) override;
    void mostrarDados() override;
};

#endif // PAIS_H