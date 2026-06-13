//
// Created by Utilizador on 12-Jun-26.
//

#include "titulo_notas_modelo.h"
#include <string>

Titulo_notas_modelo::Titulo_notas_modelo() {
    titulo      = "Sem título";
    notasViagem = "";
}

bool Titulo_notas_modelo::setTitulo(const std::string& novo) {
    if (novo.length() <= 2 || novo.length() >= 20) return false;
    titulo = novo;
    return true;
}

bool Titulo_notas_modelo::setNotasViagem(const std::string& novas) {
    if (novas.length() <= 2 || novas.length() >= 500) return false;
    notasViagem = novas;
    return true;
}

std::string Titulo_notas_modelo::getTitulo() const { return titulo; }
std::string Titulo_notas_modelo::getNotasViagem() const { return notasViagem; }