#include "LoginRepository.h"

#include <fstream>
#include <sstream>

LoginRepository::LoginRepository(const std::string& caminhoFicheiro)
    : caminhoFicheiro(caminhoFicheiro) {
}

std::vector<std::string> LoginRepository::separarCampos(const std::string& linha) {
    std::vector<std::string> campos;
    std::stringstream stream(linha);
    std::string campo;

    while (std::getline(stream, campo, ';')) {
        campos.push_back(campo);
    }

    return campos;
}

bool LoginRepository::converterInteiro(const std::string& texto, int& valor) {
    try {
        std::size_t processados = 0;
        valor = std::stoi(texto, &processados);
        return processados == texto.size();
    } catch (...) {
        return false;
    }
}

bool LoginRepository::desserializarLinha(const std::string& linha, Login& login) {
    const auto campos = separarCampos(linha);
    if (campos.size() < 8) {
        return false;
    }

    int idadeOrganizador = 0;
    int numeroViajantes = 0;
    if (!converterInteiro(campos[3], idadeOrganizador) ||
        !converterInteiro(campos[7], numeroViajantes) ||
        numeroViajantes < 0) {
        return false;
    }

    const std::size_t camposPorViajante = 5;
    const std::size_t totalEsperado = 8 + static_cast<std::size_t>(numeroViajantes) * camposPorViajante;
    if (campos.size() < totalEsperado) {
        return false;
    }

    Organizador organizador;
    organizador.colocarNome(campos[2]);
    organizador.colocarIdade(idadeOrganizador);
    organizador.colocarEmail(campos[4]);
    organizador.colocarBI(campos[5]);
    organizador.colocarValidade(campos[6]);

    std::size_t posicao = 8;
    for (int i = 0; i < numeroViajantes; ++i) {
        int idadeViajante = 0;
        if (!converterInteiro(campos[posicao + 1], idadeViajante)) {
            return false;
        }

        Viajante viajante;
        viajante.colocarNome(campos[posicao]);
        viajante.colocarIdade(idadeViajante);
        viajante.colocarEmail(campos[posicao + 2]);
        viajante.colocarBI(campos[posicao + 3]);
        viajante.colocarValidade(campos[posicao + 4]);
        organizador.adicionarViajante(viajante);

        posicao += camposPorViajante;
    }

    login.colocarEmail(campos[0]);
    login.colocarPassword(campos[1]);
    login.colocarOrganizador(organizador);
    return true;
}

std::string LoginRepository::serializarLogin(const Login& login) {
    std::ostringstream linha;
    const Organizador& organizador = login.obterOrganizador();
    const auto& viajantes = organizador.obterViajantes();

    linha << login.obterEmail() << ';' << login.obterPassword() << ';'
          << organizador.obterNome() << ';' << organizador.obterIdade() << ';'
          << organizador.obterEmail() << ';' << organizador.obterBI() << ';'
          << organizador.obterValidade() << ';' << viajantes.size();

    for (const auto& viajante : viajantes) {
        linha << ';' << viajante.obterNome() << ';' << viajante.obterIdade() << ';'
              << viajante.obterEmail() << ';' << viajante.obterBI() << ';'
              << viajante.obterValidade();
    }

    return linha.str();
}

bool LoginRepository::carregarPorCredenciais(const std::string& email, const std::string& password, Login& login) const {
    std::ifstream ficheiro(caminhoFicheiro);
    if (!ficheiro.is_open()) {
        return false;
    }

    std::string linha;
    while (std::getline(ficheiro, linha)) {
        Login candidato;
        if (!desserializarLinha(linha, candidato)) {
            continue;
        }

        if (candidato.obterEmail() == email && candidato.obterPassword() == password) {
            login = candidato;
            return true;
        }
    }

    return false;
}

bool LoginRepository::emailExiste(const std::string& email) const {
    std::ifstream ficheiro(caminhoFicheiro);
    if (!ficheiro.is_open()) {
        return false;
    }

    std::string linha;
    while (std::getline(ficheiro, linha)) {
        const auto campos = separarCampos(linha);
        if (!campos.empty() && campos[0] == email) {
            return true;
        }
    }

    return false;
}

bool LoginRepository::guardar(const Login& login) const {
    std::ifstream entrada(caminhoFicheiro);
    std::vector<std::string> linhas;
    bool substituido = false;

    std::string linha;
    while (std::getline(entrada, linha)) {
        const auto campos = separarCampos(linha);
        if (!campos.empty() && campos[0] == login.obterEmail()) {
            if (!substituido) {
                linhas.push_back(serializarLogin(login));
                substituido = true;
            }
        } else {
            linhas.push_back(linha);
        }
    }

    if (!substituido) {
        linhas.push_back(serializarLogin(login));
    }

    std::ofstream saida(caminhoFicheiro, std::ios::trunc);
    if (!saida.is_open()) {
        return false;
    }

    for (const auto& linhaGuardada : linhas) {
        saida << linhaGuardada << '\n';
    }

    return true;
}
