//
// Created by Utilizador on 10-Jun-26.
//

#ifndef _FSOFT2026_1DA_5__MUDAR_C_TOTAL_H
#define _FSOFT2026_1DA_5__MUDAR_C_TOTAL_H
class Pagamento {
protected:
    unsigned char metodoPagamento;
    int custoTotal;
public:
    Pagamento();
    bool mudarCustoTotal();
    bool mudarMetodoPagamento();
};
#endif //_FSOFT2026_1DA_5__MUDAR_C_TOTAL_H