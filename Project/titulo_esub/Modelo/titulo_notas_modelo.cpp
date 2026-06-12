//
// Created by Utilizador on 12-Jun-26.
//

#include "titulo_notas_modelo.h"

Titulo_notas::Titulo_notas() {
    titulo      = "Sem título";
    notasViagem = "";
}

bool Titulo_notas::setTitulo(const std::string& novo) {
    if (novo.length() <= 2 || novo.length() >= 20) return false;
    titulo = novo;
    return true;
}

bool Titulo_notas::setNotasViagem(const std::string& novas) {
    if (novas.length() <= 2 || novas.length() >= 500) return false;
    notasViagem = novas;
    return true;
}

std::string Titulo_notas::getTitulo() const { return titulo; }
std::string Titulo_notas::getNotasViagem() const { return notasViagem; }