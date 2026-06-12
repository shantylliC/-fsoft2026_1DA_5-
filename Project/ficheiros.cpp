//
// Created by Utilizador on 01-Jun-26.
//

#include <iostream>
#include <string>
#include <fstream>
#include "ficheiros.h"
#include "alt_estados.h"
#include "numero_reserva.h"
#include "titulo_esub.h"
#include "pagamento.h"
#include "data.h"


Viagem::Viagem() : data() {
}

void Viagem::print() const {
    std::cout << "-----< Viagem >-----\n";
    std::cout << "Título:           " << this->titulo << "\n";
    std::cout << "Custo total:      " << this->custoTotal << "EUR\n";
    std::cout << "Estado:           " << (int)this->estado << "\n";
    std::cout << "Notas:            " << this->notasViagem << "\n";
    std::cout << "Método pagamento: " << (int)this->metodoPagamento << "\n";
    std::cout << "Nº reserva:       " << this->numeroReserva << "\n";
    Calendario chegada = this->data.getChegada();
    Calendario saida = this->data.getSaida();
    std::cout << "Chegada:  " << chegada.dia << "/" << chegada.mes << "/" << chegada.ano << "\n";
    std::cout << "Saida:    " << saida.dia << "/" << saida.mes << "/" << saida.ano << "\n";
    std::cout << "Duracao:  " << this->data.getNumeroDias() << " dias\n";

    for (const std::string& h : this->data.getHorarios()) {
        std::cout << " -> " << h << "\n";
    }
}

bool Viagem::gravarFicheiro() const {
    Calendario chegada = this->data.getChegada();
    Calendario saida = this->data.getSaida();

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
    ficheiro << "Data de chegada:  "
        << chegada.dia << "/"
        << chegada.mes << "/"
        << chegada.ano << "\n";
    ficheiro << "Data de saida:    "
        << saida.dia << "/"
        << saida.mes << "/"
        << saida.ano << "\n";
    ficheiro << "Duracao:          " << this->data.getNumeroDias() << " dias\n";

    std::vector<std::string> horarios = this->data.getHorarios();
    if (!horarios.empty()) {
        ficheiro << "Atividades:\n";
        for (const std::string& h : horarios) {
            ficheiro << "  -> " << h << "\n";
        }
    }
    ficheiro << "\n";

    ficheiro.close();
    std::cout << "Viagem gravada em 'viagens.txt' com sucesso!\n";
    return true;
}