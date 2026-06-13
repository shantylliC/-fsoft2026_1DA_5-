//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_REPOSITORIOCATALOGO_H
#define PROJETOVIAGENS_REPOSITORIOCATALOGO_H


#include <vector>
#include <string>
#include <fstream>

#include "PaisModel.h"
#include "CidadeModel.h"
#include "AtividadeModel.h"

class RepositorioCatalogo {
private:
    std::vector<PaisModel*> listaPaisesAlocados;
    std::vector<CidadeModel*> listaCidadesAlocados;
    std::vector<AtividadeModel*> listaAtividadesAlocados;

    void lerFicheiro(std::string nomeFicheiro, int tipoDados);

public:
    RepositorioCatalogo();
    ~RepositorioCatalogo();

    void carregarTudo();


    const std::vector<PaisModel*>& obterPaises() const { return listaPaisesAlocados; }

    const std::vector<CidadeModel*>& obterCidades() const { return listaCidadesAlocados; }

    const std::vector<AtividadeModel*>& obterAtividades() const { return listaAtividadesAlocados; }
};


#endif //PROJETOVIAGENS_REPOSITORIOCATALOGO_H