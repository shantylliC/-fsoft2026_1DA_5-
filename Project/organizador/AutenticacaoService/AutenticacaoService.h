#ifndef AUTENTICACAOSERVICE_H
#define AUTENTICACAOSERVICE_H

#include "../Login/Login.h"
#include "../LoginRepository/LoginRepository.h"
#include <string>

class AutenticacaoService {
private:
    LoginRepository repositorio;

public:
    AutenticacaoService();
    explicit AutenticacaoService(const LoginRepository& repositorio);

    bool autenticar(const std::string& email, const std::string& password, Login& login) const;
    bool emailExiste(const std::string& email) const;
    bool guardar(const Login& login) const;
    bool organizadorTemIdadeMinima(const Organizador& organizador) const;
};

#endif
