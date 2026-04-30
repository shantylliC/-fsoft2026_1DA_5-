#include "Data.h"

Data::Data(std::string chegada, std::string saida, int dias) {
    dataChegada = chegada;
    dataSaida = saida;
    numeroDias = dias;
}

std::string Data::getDataChegada() const { return dataChegada; }
std::string Data::getDataSaida() const { return dataSaida; }
int Data::getNumeroDias() const { return numeroDias; }
std::vector<std::string> Data::getHorarios() const { return horarios; }

void Data::setDataChegada(std::string chegada) { dataChegada = chegada; }
void Data::setDataSaida(std::string saida) { dataSaida = saida; }
void Data::setNumeroDias(int dias) { numeroDias = dias; }
void Data::addHorario(std::string horario) { horarios.push_back(horario); }