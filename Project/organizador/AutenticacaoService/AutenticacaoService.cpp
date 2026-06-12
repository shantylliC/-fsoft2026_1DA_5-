#include "AutenticacaoService.h"

AutenticacaoService::AutenticacaoService() = default;

AutenticacaoService::AutenticacaoService(const LoginRepository& repositorio)
    : repositorio(repositorio) {
}

bool AutenticacaoService::autenticar(const std::string& email, const std::string& password, Login& login) const {
    return repositorio.carregarPorCredenciais(email, password, login);
}

bool AutenticacaoService::emailExiste(const std::string& email) const {
    return repositorio.emailExiste(email);
}

bool AutenticacaoService::guardar(const Login& login) const {
    return repositorio.guardar(login);
}

bool AutenticacaoService::organizadorTemIdadeMinima(const Organizador& organizador) const {
    return organizador.obterIdade() >= 18;
}
