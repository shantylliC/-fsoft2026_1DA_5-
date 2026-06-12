#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <string>
#include <vector>

struct DadosBrutos {
    int diaC, mesC, anoC;
    int diaS, mesS, anoS;
};

class View {
public:
    DadosBrutos pedirDatasViagem();
    void mostrarErro(const std::string& erro);
    void mostrarSucesso(const std::string& ch, const std::string& sa, int dias, const std::vector<std::string>& horarios);
    bool perguntarMaisHorarios();
    std::string pedirHorario();
};

#endif