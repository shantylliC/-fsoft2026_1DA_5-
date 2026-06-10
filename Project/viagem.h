//
// Created by Utilizador on 01-Jun-26.
//

#ifndef FSOFT2026_1DA_5_VIAGEM_H
#define FSOFT2026_1DA_5_VIAGEM_H
#include <string>
#include <fstream>

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
class Viagem {
private:
    std::string titulo;
    int custoTotal;
    unsigned char estado;                 // ex: 0=pendente, 1=confirmada, 2=cancelada
    std::string notasViagem;
    DataViagem dataReserva;
    unsigned char metodoPagamento;  // ex: 0=dinheiro, 1=cartão, 2=transferência
    int numeroReserva;

public:
    Viagem();
    void print() const;
    bool mudarTitulo();
    bool mudarCustoTotal();
    bool mudarNotasViagem();
    bool mudarMetodoPagamento();
    bool mudarDataReserva();
    /*
    void mostrarNumeroReserva();
    void novoNumeroReserva();
    */
    bool gravarFicheiro() const;
    void estadoConfirmar();
    void estadoCancelar();
};
#endif //FSOFT2026_1DA_5_VIAGEM_H