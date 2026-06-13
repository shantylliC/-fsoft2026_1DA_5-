//
// Created by Utilizador on 12-Jun-26.
//

#ifndef FSOFT2026_1DA_5_TITULO_NOTAS_H
#define FSOFT2026_1DA_5_TITULO_NOTAS_H

#include <string>

class Titulo_notas_modelo {
protected:
    std::string titulo;
    std::string notasViagem;
public:
    Titulo_notas_modelo();
    bool setTitulo(const std::string& novo);
    bool setNotasViagem(const std::string& novas);
    std::string getTitulo() const;
    std::string getNotasViagem() const;
};
#endif //FSOFT2026_1DA_5_TITULO_NOTAS_H