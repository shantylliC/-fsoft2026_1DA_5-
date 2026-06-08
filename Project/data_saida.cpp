//
// Created by Utilizador on 08-Jun-26.
//
DataViagem::DataViagem() {
    this->ano = 2026;
    this->mes = 1;
    this->dia = 1;
    this->hora = 00;
    this->minuto = 00;
}

bool DataViagem::mudarData() {
    int d,m,y,h,min;
    std::cout << "qual é o ano? \n";
    std::cin >> y;
    if (y < 2026 || y > 9999) {
        std::cout << "numero não valido\n";
        return false;
    }
    this->ano = y;

    std::cout << "qual é o mês\n";
    std::cin >> m;
    if (m < 1 || m >12) {
        std::cout << "numero não valido\n";
        return false;
    }
    this->mes = m;

    std::cout << "qual é o dia?\n";
    std::cin >> d;
    if (d < 1) {
        std::cout << "numero não valido\n";
        return false;
    }
    this->dia = d;

    std::cout << "qual é a hora? \n";
    std::cin >> h;
    if (h < 0 || h > 24) {
        std::cout << "numero não valido\n";
        return false;
    }
    this->hora = h;

    std::cout << "qual é os minutos? \n";
    std::cin >> min;
    if (min < 0 || min > 60) {
        std::cout << "numero não valido\n";
        return false;
    }
    this->minuto = min;

    return true;
}

void DataViagem::printData() const {
    std::cout   << this->dia << "/" << this->mes << "/" << this->ano;
    std::cout   << " ás: " ;
    std::cout   << this->hora << ":" << this->minuto << "\n";
}
