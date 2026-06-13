//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_ROTEIROMODEL_H
#define PROJETOVIAGENS_ROTEIROMODEL_H


#include <vector>
#include <string>
#include "LocalidadeModel.h"

class RoteiroModel {
private:
    std::vector<LocalidadeModel*> listaEscolhas;

public:
    RoteiroModel();
    virtual ~RoteiroModel();

    void adicionarEscolha(LocalidadeModel* localidade);
    void esvaziar();

    // Devolve a lista para o Controller poder ler
    const std::vector<LocalidadeModel*>& obterEscolhas() const;


    bool gravarFicheiroReserva(int numeroReserva,
                               const std::string& estado,
                               const std::string& titulo,
                               const std::string& notas,
                               const std::string& dataChegada,
                               const std::string& dataSaida,
                               int duracao,
                               double subtotal,
                               double totalFinal);
};


#endif //PROJETOVIAGENS_ROTEIROMODEL_H