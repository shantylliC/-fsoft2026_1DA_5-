#ifndef PESSOA_H
#define PESSOA_H

#include <cstddef>
#include <string>
#include <vector>

class Pessoa {
private:
    std::string nome;
    std::string email;
    std::string bi;
    std::string validade;
    int idade;

public:
    Pessoa();
    Pessoa(const std::string& nome, int idade, const std::string& email,
           const std::string& bi, const std::string& validade);
    virtual ~Pessoa();

    std::string obterNome() const;
    std::string obterEmail() const;
    std::string obterBI() const;
    std::string obterValidade() const;
    int obterIdade() const;

    void colocarNome(const std::string& nome);
    void colocarEmail(const std::string& email);
    void colocarBI(const std::string& bi);
    void colocarValidade(const std::string& validade);
    void colocarIdade(int idade);
};

class Viajante : public Pessoa {
public:
    Viajante();
};

class Organizador : public Pessoa {
private:
    std::vector<Viajante> listaViajantes;

public:
    Organizador();

    void adicionarViajante(const Viajante& viajante);
    const std::vector<Viajante>& obterViajantes() const;
    std::size_t obterNumeroViajantes() const;
    bool substituirViajante(std::size_t indice, const Viajante& viajante);
    void limparViajantes();
};

#endif
