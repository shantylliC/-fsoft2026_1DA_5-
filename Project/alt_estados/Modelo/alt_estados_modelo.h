//
// Created by Utilizador on 12-Jun-26.
//

#ifndef _FSOFT2026_1DA_5__ALT_ESTADOS_MODELO_H
#define _FSOFT2026_1DA_5__ALT_ESTADOS_MODELO_H

class AltEstadosModel {
protected:
    unsigned char estado; // 0=pendente, 1=confirmada, 2=cancelada
public:
    AltEstadosModel();

    unsigned char getEstado() const;
    std::string getEstadoStr() const;

    void confirmar();
    void cancelar();
};

#endif //_FSOFT2026_1DA_5__ALT_ESTADOS_MODELO_H