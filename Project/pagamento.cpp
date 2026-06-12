//
// Created by Utilizador on 10-Jun-26.
//
#include <iostream>
#include "pagamento.h"

Pagamento::Pagamento() {
    this->custoTotal         = 0;
    this->metodoPagamento = 0;
}

bool Pagamento::mudarCustoTotal() {
    int novo_custo_total;
    std::cout << "Qual é o novo custo total? (apenas digitos)\n";
    if (!(std::cin >> novo_custo_total)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Valor inválido\n";
        return false;
    }
    std::cin.ignore();
    if (novo_custo_total <= 0) {
        std::cout << "O custo não pode ser negativo\n";
        return false;
    } else{
        this->custoTotal = novo_custo_total;
        return true;
    }
}


bool Pagamento::mudarMetodoPagamento() {
    int novo_metodo_de_pagamento;
    std::cout << "Qual é o novo metodo de pagamento? (apenas digitos)\n";
    std::cout << "0 = dinheiro \n";
    std::cout << "1 = cartão \n";
    std::cout << "2 = transferência \n";
    if (!(std::cin >> novo_metodo_de_pagamento)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Valor inválido\n";
        return false;
    }
    if (novo_metodo_de_pagamento == 0) {
        this->metodoPagamento = novo_metodo_de_pagamento;
        return true;
    } else if (novo_metodo_de_pagamento == 1) {
        this->metodoPagamento = novo_metodo_de_pagamento;
        return true;
    } else if (novo_metodo_de_pagamento == 2) {
        this->metodoPagamento = novo_metodo_de_pagamento;
        return true;
    } else {
        std::cout<<"Erro \n";
        return false;
    }
}

