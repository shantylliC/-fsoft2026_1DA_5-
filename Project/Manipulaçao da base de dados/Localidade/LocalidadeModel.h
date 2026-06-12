//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_LOCALIDADEMODEL_H
#define PROJETOVIAGENS_LOCALIDADEMODEL_H

#include <string>
// REPARASTE? O <iostream> desapareceu daqui! O modelo não imprime nada.

class LocalidadeModel {
protected:
    int id;
    std::string nome;
    double preco;

    std::vector<std::string> atividadesDaCidade;

public:
    LocalidadeModel() : id(0), nome("") {}
    LocalidadeModel(int _id, std::string _nome) : id(_id), nome(_nome) {}

    virtual ~LocalidadeModel() {}

    // Getters puros (Retornam dados, não imprimem)
    int obterID() const;
    std::string obterNome() const;
    virtual double obterPreco() const;

    // Lógica pura de tratamento de strings (Não envolve o utilizador)
    virtual void carregarDeLinha(std::string linha) = 0;


    void adicionarAtividade(const std::string& atividade);
    const std::vector<std::string>& obterAtividades() const;



};

#endif //PROJETOVIAGENS_LOCALIDADEMODEL_H