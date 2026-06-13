//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_FINANCEIRO_H
#define PROJETOVIAGENS_FINANCEIRO_H


#include <vector>
#include <string>
#include "LocalidadeModel.h"

// Enumeração para evitar "números mágicos" no código
enum class MetodoPagamento {
    DINHEIRO = 0,
    CARTAO = 1,
    TRANSFERENCIA = 2,
    NAO_DEFINIDO = -1
};

class Financeiro {
private:
    // Estado estático: guarda o metodo escolhido na memoria antes da reserva final
    static MetodoPagamento metodoSelecionado;

public:
    // Métodos de cálculo originais
    static double calcularTotalBase(const std::vector<LocalidadeModel*>& listaParaContas);
    static double calcularValorIVA(double valorBase);
    static double calcularTotalComIVA(double valorBase);

    // Novos métodos puros de Modelo (Sem cin/cout)
    static void definirMetodo(MetodoPagamento metodo);
    static std::string obterMetodoPagamentoComoString();
    static MetodoPagamento obterMetodoSelecionado();
};



#endif //PROJETOVIAGENS_FINANCEIRO_H