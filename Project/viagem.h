//
// Created by Utilizador on 01-Jun-26.
//

#ifndef FSOFT2026_1DA_5_VIAGEM_H
#define FSOFT2026_1DA_5_VIAGEM_H
#include <string>
#include <fstream>
#include "alt_estados.h"
#include "numero_reserva.h"
class DataViagem {
private:

public:
    DataViagem();
    bool mudarData();
    void printData() const;
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};

class Viagem : public alt_estados, public Numero_reserva {
private:
    std::string titulo;
    int custoTotal;
    std::string notasViagem;
    DataViagem dataReserva;
    unsigned char metodoPagamento;  // ex: 0=dinheiro, 1=cartão, 2=transferência

public:
    Viagem();
    void print() const;
    bool mudarTitulo();
    bool mudarCustoTotal();
    bool mudarNotasViagem();
    bool mudarMetodoPagamento();
    bool mudarDataReserva();
    bool gravarFicheiro() const;
};
#endif //FSOFT2026_1DA_5_VIAGEM_H