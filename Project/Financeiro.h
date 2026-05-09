//
// Created by HQCamachoPC on 08/05/2026.
//

#ifndef PROJETOVIAGENS_FINANCEIRO_H
#define PROJETOVIAGENS_FINANCEIRO_H

#include <vector>
#include "Localidade.h"

class Financeiro {
public:
    // Calcula o valor total (sem impostos)
    static double calcularTotalBase(const std::vector<Localidade*>& listaParaCalcular);

    // Calcula o valor apenas do IVA (23%)
    static double calcularValorIVA(double valorBase);

    // Calcula o valor final (Base + IVA)
    static double calcularTotalComIVA(double valorBase);
};

#endif // FINANCEIRO_H