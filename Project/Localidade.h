//
// Created by HQCamachoPC on 08/05/2026.
//

#ifndef PROJETOVIAGENS_LOCALIDADE_H
#define PROJETOVIAGENS_LOCALIDADE_H

#include <string>
#include <iostream>

class Localidade {
protected:
    int id;
    std::string nome;

public:
    // Construtores (geralmente ficam no .h se forem simples como estes)
    Localidade() : id(0), nome("") {}
    Localidade(int _id, std::string _nome) : id(_id), nome(_nome) {}

    // Destrutor virtual (importante em herança)
    virtual ~Localidade() {}

    // Getters
    int obterID() const;
    std::string obterNome() const;

    // Funções virtuais puras (obrigam as classes filhas a implementar)
    virtual void mostrarDados() = 0;
    virtual void carregarDeLinha(std::string linha) = 0;

    // Função virtual com implementação base
    virtual double obterPreco() const;
};

#endif // LOCALIDADE_H