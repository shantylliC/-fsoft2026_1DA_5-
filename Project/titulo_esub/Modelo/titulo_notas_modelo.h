//
// Created by Utilizador on 12-Jun-26.
//

#ifndef FSOFT2026_1DA_5_TITULO_NOTAS_H
#define FSOFT2026_1DA_5_TITULO_NOTAS_H

class Titulo_notas {
protected:
    std::string titulo;
    std::string notasViagem;
public:
    Titulo_notas();
    bool setTitulo(const std::string& novo);
    bool setNotasViagem(const std::string& novas);
    std::string getTitulo() const;
    std::string getNotasViagem() const;
};
#endif //FSOFT2026_1DA_5_TITULO_NOTAS_H