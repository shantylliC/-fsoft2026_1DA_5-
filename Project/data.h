#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <stdexcept>

class DataInvalidaException : public std::exception {
private:
    std::string mensagem;
public:
    DataInvalidaException(std::string msg) : mensagem(msg) {}
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

struct Calendario {
    int dia;
    int mes;
    int ano;
};

class Data {
private:
    Calendario chegada;
    Calendario saida;
    int numeroDias;
    std::vector<std::string> horarios;

    bool validarData(int d, int m, int a) const;
    int dataParaDias(int d, int m, int a) const;
    void atualizarNumeroDias();

public:
    Data(int diaC, int mesC, int anoC, int diaS, int mesS, int anoS);

    Calendario getChegada() const;
    Calendario getSaida() const;
    int getNumeroDias() const;
    std::vector<std::string> getHorarios() const;

    void setChegada(int d, int m, int a);
    void setSaida(int d, int m, int a);
    void addHorario(std::string horario);
};

#endif