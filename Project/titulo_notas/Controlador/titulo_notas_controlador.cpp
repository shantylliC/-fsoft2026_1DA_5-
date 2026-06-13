//
// Created by Utilizador on 12-Jun-26.
//
#include "titulo_notas_controlador.h"
#include <string>

void Titulo_notas_controlador::mostrar() {
    view.mostrarTitulo(modelo.getTitulo(), modelo.getNotasViagem());
}

void Titulo_notas_controlador::mudarTitulo() {
    std::string novo = view.pedirTitulo();
    if (!modelo.setTitulo(novo))
        view.mostrarErroTitulo(novo.length() <= 2);
    else
        view.mostrarSucesso("Título atualizado.");
}

void Titulo_notas_controlador::mudarNotasViagem() {
    std::string novas = view.pedirNotas();
    if (!modelo.setNotasViagem(novas))
        view.mostrarErroNotas(novas.length() <= 2);
    else
        view.mostrarSucesso("Notas atualizadas.");
}
