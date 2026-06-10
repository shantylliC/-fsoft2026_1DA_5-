//
// Created by Utilizador on 10-Jun-26.
//
#include <iostream>
#include "alt_estados.h"

alt_estados::alt_estados() {
   estado = 0;
}

void alt_estados::estadoConfirmar() {
    this->estado = 1;
}

void alt_estados::estadoCancelar() {
    this->estado = 2;
}