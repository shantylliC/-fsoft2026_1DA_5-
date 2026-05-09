//
// Created by HQCamachoPC on 08/05/2026.
//

#ifndef PROJETOVIAGENS_REPOSITORIO_H
#define PROJETOVIAGENS_REPOSITORIO_H

#include <vector>
#include <string>
#include <fstream>
#include "Pais.h"
#include "Cidade.h"
#include "Atividade.h"

class Repositorio {
private:
    std::vector<Pais*> listaPaisesAlocados;
    std::vector<Cidade*> listaCidadesAlocados;
    std::vector<Atividade*> listaAtividadesAlocados;

    // Função interna auxiliar para ler os ficheiros
    void lerFicheiro(std::string nomeFicheiro, int tipoDados);

public:
    Repositorio();
    ~Repositorio(); // Destrutor para limpar a memória RAM

    void carregarTudo();

    // Getters para poderes aceder aos dados no main.cpp // tem todas as listas de cada uma (todos os elementos) porque na localidade os dados sao privados
    const std::vector<Pais*>& getPaises() const { return listaPaisesAlocados; }
    const std::vector<Cidade*>& getCidades() const { return listaCidadesAlocados; }
    const std::vector<Atividade*>& getAtividades() const { return listaAtividadesAlocados; }
};

#endif // REPOSITORIO_H