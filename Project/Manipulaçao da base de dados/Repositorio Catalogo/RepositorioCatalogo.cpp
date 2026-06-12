//
// Created by HQCamachoPC on 12/06/2026.
//

#include "RepositorioCatalogo.h"
#include "Excecoes.h"

RepositorioCatalogo::RepositorioCatalogo() {}

RepositorioCatalogo::~RepositorioCatalogo() {
    // 1. Limpar Paises
    for (PaisModel* p : listaPaisesAlocados) delete p;

    // 2. Limpar Cidades
    for (CidadeModel* c : listaCidadesAlocados) delete c;

    // 3. Limpar Atividades
    for (AtividadeModel* a : listaAtividadesAlocados) delete a;

    // Esvaziar os vectores com segurança
    listaPaisesAlocados.clear();
    listaCidadesAlocados.clear();
    listaAtividadesAlocados.clear();
}

void RepositorioCatalogo::carregarTudo() {
    lerFicheiro("BaseDados-paises.txt", 1);
    lerFicheiro("BaseDados-cidades.txt", 2);
    lerFicheiro("BaseDados-atividades.txt", 3); // Corrigido o pequeno espaço no nome
}

void RepositorioCatalogo::lerFicheiro(std::string nomeFicheiro, int tipo) {

    std::ifstream ficheiro(nomeFicheiro);
    std::string linha;


    // LANÇAR EXCEÇÃO AQUI
    if (!ficheiro.is_open()) {
        throw ErroFormatacaoFicheiroException("Nao foi possivel encontrar ou abrir o ficheiro: " + nomeFicheiro);
    }

    while (std::obterLinha(ficheiro, linha)) {
        if (linha.empty()) continue;

        // Instanciação polimórfica controlada por tipo
        if (tipo == 1) {
            PaisModel* novo = new PaisModel();
            novo->carregarDeLinha(linha); // Executa a lógica de corte do País
            listaPaisesAlocados.push_back(novo);
        }
        else if (tipo == 2) {
            CidadeModel* novo = new CidadeModel();
            novo->carregarDeLinha(linha); // Executa a lógica de corte da Cidade
            listaCidadesAlocados.push_back(novo);
        }
        else if (tipo == 3) {
            AtividadeModel* novo = new AtividadeModel();
            novo->carregarDeLinha(linha); // Executa a lógica de corte da Atividade
            listaAtividadesAlocados.push_back(novo);
        }
    }

    ficheiro.close();
}
