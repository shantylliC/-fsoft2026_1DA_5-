//
// Created by Utilizador on 10-Jun-26.
//
#include <iostream>
#include <string>
#include "titulo_esub.h"
Titulo_esub::Titulo_esub() {
    this->titulo              = "Sem título";
    this->notasViagem         = "";
}
bool Titulo_esub::mudarTitulo() {
    std::string novo_titulo;
    std::cout << "Qual é o novo título?\n";
    std::getline(std::cin, novo_titulo);
    if (novo_titulo.length() <= 2){
        std::cout << "título muito pequeno\n";
        return false;
    }else if (novo_titulo.length() >= 20) {
        std::cout << "título muito grande\n";
        return false;
    };

    titulo = novo_titulo;
    return true;
}

bool Titulo_esub::mudarNotasViagem() {
    std::string novas_notas;
    std::cout << "Quais são as novas notas?\n";
    std::getline(std::cin, novas_notas);
    if (novas_notas.length() <= 2){
        std::cout << "Notas muito pequenas\n";
        return false;
    }else if (novas_notas.length() >= 500) {
        std::cout << "Notas muito grandes\n";
        return false;
    };

    this->notasViagem = novas_notas;
    return true;
}