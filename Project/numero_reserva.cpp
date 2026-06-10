//
// Created by Utilizador on 10-Jun-26.
//
#include <iostream>
#include "numero_reserva.h"
Numero_reserva::Numero_reserva() {
    numeroReserva = 1;
}
void Numero_reserva::mostrarNumeroReserva(){
    std::cout << "Numero de reserva: " << this->numeroReserva << "\n";
}
void Numero_reserva::novoNumeroReserva() {
    this-> numeroReserva = this->numeroReserva +1;
}