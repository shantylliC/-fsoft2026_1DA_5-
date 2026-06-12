//
// Created by HQCamachoPC on 08/05/2026.
//

#ifndef PROJETOVIAGENS_CIDADE_H
#define PROJETOVIAGENS_CIDADE_H

#include "Localidade.h"
#include <string>
#include <iostream>

class Cidade : public Localidade {
protected:
    int id_pais;
    double preco_cidade;

public:
    // Construtores
    Cidade() : Localidade(), id_pais(0), preco_cidade(0.0) {}
    Cidade(int _id, std::string _nome, int _idPrais, double _preco)
        : Localidade(_id, _nome), id_pais(_idPrais), preco_cidade(_preco) {}

    virtual ~Cidade() {}

    // Getters específicos
    int obterIdPais() const;
    double obterPreco() const override;

    // Métodos obrigatórios
    void carregarDeLinha(std::string linhaLida) override;
    void mostrarDados() override;
};

#endif // CIDADE_H