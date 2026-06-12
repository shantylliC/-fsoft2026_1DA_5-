//
// Created by Utilizador on 10-Jun-26.
//

#ifndef _FSOFT2026_1DA_5__TITULO_ESUB_H
#define _FSOFT2026_1DA_5__TITULO_ESUB_H
class Titulo_notas {
protected:
    std::string titulo;
    std::string notasViagem;
public:
    Titulo_notas();
    bool mudarTitulo();
    bool mudarNotasViagem();
};
#endif //_FSOFT2026_1DA_5__TITULO_ESUB_H