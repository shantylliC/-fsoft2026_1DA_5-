//
// Created by Utilizador on 12-Jun-26.
//

#include <iostream>
#include "titulo_notas_view.h"

void Titulo_notas_view::mostrarTitulo(const std::string& titulo, const std::string& notas) {
    std::cout << "Título: " << titulo << "\n";
    std::cout << "Notas:  " << notas  << "\n";
}

void Titulo_notas_view::mostrarErroTitulo(bool muitoPequeno) {
    std::cout << (muitoPequeno ? "Título muito pequeno\n" : "Título muito grande\n");
}

void Titulo_notas_view::mostrarErroNotas(bool muitoPequeno) {
    std::cout << (muitoPequeno ? "Notas muito pequenas\n" : "Notas muito grandes\n");
}

void Titulo_notas_view::mostrarSucesso(const std::string& msg) {
    std::cout << msg << "\n";
}

std::string Titulo_notas_view::pedirTitulo() {
    std::string s;
    std::cout << "Qual é o novo título?\n";
    std::getline(std::cin, s);
    return s;
}

std::string Titulo_notas_view::pedirNotas() {
    std::string s;
    std::cout << "Quais são as novas notas?\n";
    std::getline(std::cin, s);
    return s;
}