#include "Data.h"
#include <iostream>

bool Data::validarData(int d, int m, int a) const {
    if (a < 2024) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > 31) return false;
    
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    
    if (m == 2) {
        bool bissexto = (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
        if (bissexto && d > 29) return false;
        if (!bissexto && d > 28) return false;
    }
    return true;
}

int Data::dataParaDias(int d, int m, int a) const {
    if (m < 3) {
        m += 12;
        a--;
    }
    return 365 * a + a / 4 - a / 100 + a / 400 + (153 * m + 2) / 5 + d;
}

void Data::atualizarNumeroDias() {
    int diasC = dataParaDias(chegada.dia, chegada.mes, chegada.ano);
    int diasS = dataParaDias(saida.dia, saida.mes, saida.ano);
    numeroDias = diasS - diasC;
}

Data::Data(int diaC, int mesC, int anoC, int diaS, int mesS, int anoS) {
    if (!validarData(diaC, mesC, anoC)) throw DataInvalidaException("Erro: Data de chegada invalida!");
    if (!validarData(diaS, mesS, anoS)) throw DataInvalidaException("Erro: Data de saida invalida!");

    chegada = {diaC, mesC, anoC};
    saida = {diaS, mesS, anoS};
    
    atualizarNumeroDias();
    
    if (numeroDias < 0) throw DataInvalidaException("Erro: A data de saida nao pode ser anterior a data de chegada!");
}

Calendario Data::getChegada() const { return chegada; }
Calendario Data::getSaida() const { return saida; }
int Data::getNumeroDias() const { return numeroDias; }
std::vector<std::string> Data::getHorarios() const { return horarios; }

void Data::setChegada(int d, int m, int a) {
    if (!validarData(d, m, a)) throw DataInvalidaException("Erro: Nova data de chegada invalida!");
    chegada = {d, m, a};
    atualizarNumeroDias();
    if (numeroDias < 0) throw DataInvalidaException("Erro: A data de saida nao pode ser anterior a data de chegada!");
}

void Data::setSaida(int d, int m, int a) {
    if (!validarData(d, m, a)) throw DataInvalidaException("Erro: Nova data de saida invalida!");
    saida = {d, m, a};
    atualizarNumeroDias();
    if (numeroDias < 0) throw DataInvalidaException("Erro: A data de saida nao pode ser anterior a data de chegada!");
}

void Data::addHorario(std::string horario) { 
    horarios.push_back(horario); 
}

void Data::mudarData() {
    int diaC, mesC, anoC, diaS, mesS, anoS;

    std::cout << "Introduza a data de chegada (dia mes ano):\n";
    if (!(std::cin >> diaC >> mesC >> anoC)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Valor inválido\n";
        return;
    }
    std::cout << "Introduza a data de saida (dia mes ano):\n";
    if (!(std::cin >> diaS >> mesS >> anoS)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Valor inválido\n";
        return;
    }
    std::cin.ignore();

    try {
        if (!validarData(diaC, mesC, anoC)) throw DataInvalidaException("Erro: Data de chegada invalida!");
        if (!validarData(diaS, mesS, anoS)) throw DataInvalidaException("Erro: Data de saida invalida!");

        chegada = {diaC, mesC, anoC};
        saida = {diaS, mesS, anoS};

        atualizarNumeroDias();

        if (numeroDias <0) {
            throw DataInvalidaException("Erro: A data de saida antes da de chegada!\n");
        }
        std::cout << "Data alterada com sucesso!\n";
    } catch (const DataInvalidaException& e) {
        std::cerr << e.what() << "\n";
    }

}

Data::Data() {
    chegada = {1, 1, 2026};
    saida   = {2, 1, 2026};
    numeroDias = 1;
}