//
// Created by HQCamachoPC on 08/05/2026.
//

#ifndef PROJETOVIAGENS_ATIVIDADE_H
#define PROJETOVIAGENS_ATIVIDADE_H

#include "Localidade.h"
#include <string>
#include <iostream>

class Atividade : public Localidade {
protected:
    int id_cidade;
    double preco_ticket;

public:
    // Construtores
    Atividade() : Localidade(), id_cidade(0), preco_ticket(0.0) {}
    Atividade(int _id, std::string _nome, int _idCidade, double _preco)
        : Localidade(_id, _nome), id_cidade(_idCidade), preco_ticket(_preco) {}

    virtual ~Atividade() {}

    // Getters
    int obterIdCidade() const;
    double obterPreco() const override;

    // Métodos obrigatórios
    void carregarDeLinha(std::string linha) override;
    void mostrarDados() override;
};

#endif // ATIVIDADE_H