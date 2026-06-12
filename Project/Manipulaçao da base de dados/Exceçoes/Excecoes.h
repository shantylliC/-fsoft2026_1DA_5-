//
// Created by HQCamachoPC on 12/06/2026.
//

#ifndef PROJETOVIAGENS_EXCECOES_H
#define PROJETOVIAGENS_EXCECOES_H

#include <stdexcept>
#include <string>

// 1. Exceção para IDs inexistentes ou negativos
class IDInvalidoException : public std::invalid_argument {
public:
    IDInvalidoException(const std::string& mensagem)
        : std::invalid_argument(mensagem) {}
};

// 2. Exceção para operações proibidas num roteiro sem itens
class RoteiroVazioException : public std::runtime_error {
public:
    RoteiroVazioException(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};

// 3. Exceção para inputs inválidos nos menus (ex: letras em vez de números)
class InputInvalidoException : public std::invalid_argument {
public:
    InputInvalidoException(const std::string& mensagem)
        : std::invalid_argument(mensagem) {}
};

// 4. Exceção para detetar valores financeiros impossíveis (ex: preços negativos)
class PrecoInvalidoException : public std::invalid_argument {
public:
    PrecoInvalidoException(const std::string& mensagem)
        : std::invalid_argument(mensagem) {}
};

// 5. Exceção para falhas na leitura ou formatação dos ficheiros .txt
class ErroFormatacaoFicheiroException : public std::runtime_error {
public:
    ErroFormatacaoFicheiroException(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};


#endif //PROJETOVIAGENS_EXCECOES_H