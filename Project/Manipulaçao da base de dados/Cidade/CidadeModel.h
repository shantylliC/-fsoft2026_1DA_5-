//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_CIDADEMODEL_H
#define PROJETOVIAGENS_CIDADEMODEL_H

#include "LocalidadeModel.h" // Herda da classe base que já refatorámos
#include <string>

class CidadeModel : public LocalidadeModel {
protected:
    int paisAssociado;
    double precoCidade;

public:
    CidadeModel();
    CidadeModel(int _id, std::string _nome, int _paisAssociado, double _precoCidade);

    virtual ~CidadeModel() {}

    // Getters puros
    int obterIdPais() const;
    double obterPreco() const override; // O override vital para o Polimorfismo!

    // Lógica pura de tratamento de texto (mantém-se intacta, sem couts)
    void carregarDeLinha(std::string linha) override;
};


#endif //PROJETOVIAGENS_CIDADEMODEL_H