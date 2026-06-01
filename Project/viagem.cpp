//
// Created by Utilizador on 01-Jun-26.
//

#include <iostream>
#include <string>
#include "viagem.h"
DataViagem::DataViagem() {
    this->ano = 2026;
    this->mes = 1;
    this->dia = 1;
    this->hora = 00;
    this->minuto = 00;
}

bool DataViagem::mudarData() {
    int d,m,y,h,min;
    std::cout << "qual é o ano? \n";
    std::cin >> y;
    if (y < 2026 || y > 9999) {
        std::cout << "numero não valido\n";
        return false;
    }
    this->ano = y;

    std::cout << "qual é o mês\n";
    std::cin >> m;
    if (m < 1 || m >12) {
        std::cout << "numero não valido\n";
        return false;
    }
    this->mes = m;

    std::cout << "qual é o dia?\n";
    std::cin >> d;
    if (d < 1) {
        std::cout << "numero não valido\n";
        return false;
    }
    this->dia = d;

    std::cout << "qual é a hora? \n";
    std::cin >> h;
    if (h < 0 || h > 24) {
        std::cout << "numero não valido\n";
        return false;
    }
    this->hora = h;

    std::cout << "qual é os minutos? \n";
    std::cin >> min;
    if (min < 0 || min > 60) {
        std::cout << "numero não valido\n";
        return false;
    }
    this->minuto = min;

    return true;
}

void DataViagem::printData() const {
    std::cout   << this->dia << "/" << this->mes << "/" << this->ano;
    std::cout   << " ás: " ;
    std::cout   << this->hora << ":" << this->minuto << "\n";
}



Viagem::Viagem() {
    this->titulo              = "Sem título";
    this->custoTotal         = 0;
    this->estado              = 0;      // 0 = pendente
    this->notasViagem     = "";
    this->metodoPagamento = 0;      // 0 = dinheiro
    this->numeroReserva   = 0;
}

void Viagem::print() const {
    std::cout << "-----< Viagem >-----\n";
    std::cout << "Título:           " << this->titulo << "\n";
    std::cout << "Custo total:      " << this->custoTotal << "EUR\n";
    std::cout << "Estado:           " << (int)this->estado << "\n";
    std::cout << "Notas:            " << this->notasViagem << "\n";
    std::cout << "Método pagamento: " << (int)this->metodoPagamento << "\n";
    std::cout << "Nº reserva:       " << this->numeroReserva << "\n";
    std::cout << "Data de reserva:  ";
    this-> dataReserva.printData();
}

bool Viagem::mudarTitulo() {
    std::string novo_titulo;
    std::cout << "Qual é o novo título?\n";
    std::cin.ignore();
    std::getline(std::cin, novo_titulo);
    if (novo_titulo.length() <= 2){
        std::cout << "título muito pequeno\n";
        return false;
    }else if (novo_titulo.length() >= 20) {
        std::cout << "título muito grande\n";
        return false;
    };

    this->titulo = novo_titulo;
    return true;
}

bool Viagem::mudarCustoTotal() {
    int novo_custo_total;
    std::cout << "Qual é o novo custo total? (apenas digitos)\n";
    std::cin >> novo_custo_total;
    std::cin.ignore();
    if (novo_custo_total <= 0) {
        std::cout << "O custo não pode ser negativo\n";
        return false;
    } else{
        this->custoTotal = novo_custo_total;
        return true;
    }
}

bool Viagem::mudarNotasViagem() {
    std::string novas_notas;
    std::cout << "Quais são as novas notas?\n";
    std::getline(std::cin, novas_notas);
    if (novas_notas.length() <= 2){
        std::cout << "Notas muito pequenas\n";
        return false;
    }else if (novas_notas.length() >= 500) {
        std::cout << "Notas muito grandes\n";
        return false;
    };

    this->notasViagem = novas_notas;
    return true;
}

bool Viagem::mudarMetodoPagamento() {
    int novo_metodo_de_pagamento;
    std::cout << "Qual é o novo metodo de pagamento? (apenas digitos)\n";
    std::cout << "0 = dinheiro \n";
    std::cout << "1 = cartão \n";
    std::cout << "2 = transferência \n";
    std::cin >> novo_metodo_de_pagamento;
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

bool Viagem::mudarDataReserva() {
    return this->dataReserva.mudarData();
}

void Viagem::mostrarNumeroReserva(){
    std::cout << "Numero de reserva: " << this->numeroReserva << "\n";
}
void Viagem::novoNumeroReserva() {
    this-> numeroReserva = this->numeroReserva +1;
}

void Viagem::estadoConfirmar() {
    this->estado = 1;
}

void Viagem::estadoCancelar() {
    this->estado = 2;
}

bool Viagem::gravarFicheiro() const {
    std::ofstream ficheiro("viagens.txt", std::ios::app);
    if (!ficheiro.is_open()) {
        std::cout << "Erro ao abrir o ficheiro!\n";
        return false;
    }

    std::string estado_da_via;
    if      (this->estado == 0) estado_da_via = "pendente";
    else if (this->estado == 1) estado_da_via = "confirmada";
    else if (this->estado == 2) estado_da_via = "cancelada";
    else return false;

    std::string metodo_da_via;
    if      (this->metodoPagamento == 0) metodo_da_via = "dinheiro";
    else if (this->metodoPagamento == 1) metodo_da_via = "cartao";
    else if (this->metodoPagamento == 2) metodo_da_via = "transferencia";
    else return false;

    ficheiro << "RESERVA Nº        " << this->numeroReserva << "\n \n";
    ficheiro << "Titulo:           " << this->titulo << "\n";
    ficheiro << "Custo total:      " << this->custoTotal << "EUR\n";
    ficheiro << "Estado:           " << estado_da_via << "\n";
    ficheiro << "Notas:            " << this->notasViagem << "\n";
    ficheiro << "Metodo pagamento: " << metodo_da_via << "\n";
    ficheiro << "Data de reserva:  "
        << this->dataReserva.dia << "/"
        << this->dataReserva.mes << "/"
        << this->dataReserva.ano << " as: "
        << this->dataReserva.hora << ":"
        << this->dataReserva.minuto << "\n";
    ficheiro << "\n\n";

    ficheiro.close();
    std::cout << "Viagem gravada em 'viagens.txt' com sucesso!\n";
    return true;
}