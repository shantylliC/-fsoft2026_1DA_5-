
#include "Financeiro.h"

double Financeiro::calcularTotalBase(const std::vector<Localidade*>& listaParaCalcular) {
    double somaTotal = 0.0;

    for (Localidade* localidade : listaParaCalcular) {
        if (localidade != nullptr) {
            // Graças ao polimorfismo, o C++ chama o obterPreco()
            // correto (da Cidade ou da Atividade)
            somaTotal += localidade->obterPreco();
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