//
// Created by Utilizador on 12-Jun-26.
//
#include "titulo_esub_controller.h"

void Titulo_esub_controller::mostrar() {
    view.mostrarTitulo(modelo.getTitulo(), modelo.getNotasViagem());
}

void Titulo_esub_controller::mudarTitulo() {
    std::string novo = view.pedirTitulo();
    if (!modelo.setTitulo(novo))
        view.mostrarErroTitulo(novo.length() <= 2);
    else
        view.mostrarSucesso("Título atualizado.");
}

void Titulo_esub_controller::mudarNotasViagem() {
    std::string novas = view.pedirNotas();
    if (!modelo.setNotasViagem(novas))
        view.mostrarErroNotas(novas.length() <= 2);
    else
        view.mostrarSucesso("Notas atualizadas.");
}
