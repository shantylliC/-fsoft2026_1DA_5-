//
// Created by Utilizador on 01-Jun-26.
//

#ifndef FSOFT2026_1DA_5_VIAGEM_H
#define FSOFT2026_1DA_5_VIAGEM_H
#include "alt_estados.h"
#include "numero_reserva.h"
#include "pagamento.h"
#include "titulo_esub.h"
/*
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
*/

class Viagem : public alt_estados, public Numero_reserva, public Pagamento, public Titulo_esub{
private:
    //DataViagem dataReserva;

public:
    Viagem();
    void print() const;
    //bool mudarDataReserva();
    bool gravarFicheiro() const;
};
#endif //FSOFT2026_1DA_5_VIAGEM_H