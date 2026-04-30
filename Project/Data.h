#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

class Data {
private:
    std::string dataChegada;
    std::string dataSaida;
    int numeroDias;
    std::vector<std::string> horarios;

public:

    Data(std::string chegada, std::string saida, int dias);

    std::string getDataChegada() const;
    std::string getDataSaida() const;
    int getNumeroDias() const;
    std::vector<std::string> getHorarios() const;

    void setDataChegada(std::string chegada);
    void setDataSaida(std::string saida);
    void setNumeroDias(int dias);
    void addHorario(std::string horario);
};

#endif