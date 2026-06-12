//
// Created by HQCamachoPC on 08/05/2026.
//

#include "Repositorio.h"

#include "Repositorio.h"

Repositorio::Repositorio() {}

Repositorio::~Repositorio() {
    // IMPORTANTE: Como usaste 'new', temos de usar 'delete' para evitar Memory Leaks
    for (Pais* ponteiroPais : listaPaisesAlocados)
        delete ponteiroPais;

    for (Cidade* ponteiroCidade : listaCidadesAlocados)
        delete ponteiroCidade;

    for (Atividade* pnteiroAtividade : listaAtividadesAlocados)
        delete pnteiroAtividade;


    listaPaisesAlocados.clear();
    listaCidadesAlocados.clear();
    listaAtividadesAlocados.clear();
}

void Repositorio::carregarTudo() {
    // Garante que o nome dos ficheiros coincide exatamente com os .txt
    lerFicheiro("Base de dados - paises.txt", 1);
    lerFicheiro("Base de dados - cidades.txt", 2);
    lerFicheiro("Base de dados - atividades.txt", 3);
}

void Repositorio::lerFicheiro(std::string nomeFicheiro, int tipoDados) {
    std::ifstream ficheiro(nomeFicheiro);
    std::string linhaLida;

    if (!ficheiro.is_open()) {
        std::cerr << "Erro: Nao foi possivel aceder " << nomeFicheiro << std::endl;
        return;
    }

    while (std::getline(ficheiro, linhaLida)) {
        if (linhaLida.empty()) continue;

        if (tipoDados == 1) {
            Pais* ponteiroNovoPais = new Pais();
            ponteiroNovoPais->carregarDeLinha(linhaLida);
            listaPaisesAlocados.push_back(ponteiroNovoPais);
        }
        else if (tipoDados == 2) {
            Cidade* ponteiroNovoCidade = new Cidade();
            ponteiroNovoCidade->carregarDeLinha(linhaLida);
            listaCidadesAlocados.push_back(ponteiroNovoCidade);
        }
        else if (tipoDados == 3) {
            Atividade* ponteiroNovoAtividade = new Atividade();
            ponteiroNovoAtividade->carregarDeLinha(linhaLida);
            listaAtividadesAlocados.push_back(ponteiroNovoAtividade);
        }
    }
    ficheiro.close();
}