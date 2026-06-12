//
// Created by Utilizador on 10-Jun-26.
//

#ifndef _FSOFT2026_1DA_5__ALT_ESTADOS_H
#define _FSOFT2026_1DA_5__ALT_ESTADOS_H
class alt_estados {
protected:
    unsigned char estado;                 // ex: 0=pendente, 1=confirmada, 2=cancelada
public:
    alt_estados();
    void estadoConfirmar();
    void estadoCancelar();
};
#endif //_FSOFT2026_1DA_5__ALT_ESTADOS_H