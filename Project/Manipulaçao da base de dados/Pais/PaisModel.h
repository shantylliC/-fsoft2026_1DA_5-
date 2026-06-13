//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_PAISMODEL_H
#define PROJETOVIAGENS_PAISMODEL_H


#include "../Localidade/LocalidadeModel.h"// Herda do novo Modelo!
#include <string>

class PaisModel : public LocalidadeModel {
public:
    // Construtores
    PaisModel() : LocalidadeModel() {}
    PaisModel(int _id, std::string _nome) : LocalidadeModel(_id, _nome) {}

    // Destrutor
    virtual ~PaisModel() {}

    // Mantemos APENAS a função de lógica (processamento de dados)
    void carregarDeLinha(std::string linha) override;
};



#endif //PROJETOVIAGENS_PAISMODEL_H