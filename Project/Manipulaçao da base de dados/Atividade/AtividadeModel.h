//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_ATIVIDADEMODEL_H
#define PROJETOVIAGENS_ATIVIDADEMODEL_H


#include "../Localidade/LocalidadeModel.h"
#include <string>

class AtividadeModel : public LocalidadeModel {
protected:
    int cidadeAssociada;
    double precoTicket;

public:
    AtividadeModel();
    AtividadeModel(int _id, std::string _nome, int _cidadeAssociada, double _precoTicket);

    virtual ~AtividadeModel() {}

    // Getters
    int obterIdCidade() const;
    double obterPreco() const override; // Polimorfismo ativado!

    // Lógica pura de leitura
    void carregarDeLinha(std::string linha) override;
};


#endif //PROJETOVIAGENS_ATIVIDADEMODEL_H