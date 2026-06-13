//
// Created by Utilizador on 12-Jun-26.
//

#ifndef FSOFT2026_1DA_5_TITULO_NOTAS_VIEW_H
#define FSOFT2026_1DA_5_TITULO_NOTAS_VIEW_H

class Titulo_notas_view {
public:
    void mostrarTitulo(const std::string& titulo, const std::string& notas);
    void mostrarErroTitulo(bool muitoPequeno);
    void mostrarErroNotas(bool muitoPequeno);
    void mostrarSucesso(const std::string& msg);
    std::string pedirTitulo();
    std::string pedirNotas();
};

#endif //FSOFT2026_1DA_5_TITULO_NOTAS_VIEW_H