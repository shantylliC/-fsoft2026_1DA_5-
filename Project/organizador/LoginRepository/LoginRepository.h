#ifndef LOGINREPOSITORY_H
#define LOGINREPOSITORY_H

#include "../Login/Login.h"
#include <string>
#include <vector>

class LoginRepository {
private:
    std::string caminhoFicheiro;

    static std::vector<std::string> separarCampos(const std::string& linha);
    static bool converterInteiro(const std::string& texto, int& valor);
    static bool desserializarLinha(const std::string& linha, Login& login);
    static std::string serializarLogin(const Login& login);

public:
    explicit LoginRepository(const std::string& caminhoFicheiro = "dados_login.txt");

    bool carregarPorCredenciais(const std::string& email, const std::string& password, Login& login) const;
    bool emailExiste(const std::string& email) const;
    bool guardar(const Login& login) const;
};

#endif
