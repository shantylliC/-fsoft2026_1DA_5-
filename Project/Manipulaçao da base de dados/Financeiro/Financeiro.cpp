//
// Created by HQCamachoPC on 12/06/2026.
//

#include "Financeiro.h"
#include "Financeiro.h"
#include "Excecoes.h"
#include <iostream>
#include <limits>



MetodoPagamento Financeiro::metodoSelecionado = MetodoPagamento::NAODEFINIDO;

double Financeiro::calcularTotalBase(const std::vector<LocalidadeModel*>& listaParaContas) {

    double somaTotal = 0.0;
    for (LocalidadeModel* ponteiroLocalidade : listaParaContas) {
        if (ponteiroLocalidade != nullptr) {
            somaTotal += ponteiroLocalidade->obterPreco();
        }
    }
    return somaTotal;
}

double Financeiro::calcularValorIVA(double valorBase) {
    return valorBase * 0.23;
}

double Financeiro::calcularTotalComIVA(double valorBase) {
    return valorBase * 1.23;
}

void Financeiro::definirMetodo(MetodoPagamento metodo) {
    metodoSelecionado = metodo;
}

std::string Financeiro::obterMetodoPagamentoComoString() {
    switch (metodoSelecionado) {

        case MetodoPagamento::DINHEIRO:
            return "Dinheiro";

        case MetodoPagamento::CARTAO:
            return "Cartao";

        case MetodoPagamento::TRANSFERENCIA:
            return "Transferencia";

        default:
            return "Nao Definido";
    }
}

MetodoPagamento Financeiro::obterMetodoSelecionado() {
    return metodoSelecionado;
}
