#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

// 1. Módulo de Autenticação (Organizador + Viajantes)
#include "organizador/AutenticacaoController/AutenticacaoController.h"
#include "organizador/Pessoa/Pessoa.h"

// 2. Módulo de Validação de Datas
#include "Controller.h"
#include "data.h"

// 3. Módulo de Catálogo e Roteiro (Países, Cidades, Atividades)
#include "Manipulaçao da base de dados/Repositorio Catalogo/RepositorioCatalogo.h"
#include "Manipulaçao da base de dados/Roteiro/RoteiroController.h"
#include "Manipulaçao da base de dados/Exceçoes/Excecoes.h"

// 4. Módulo de Reserva e Pagamento Final
#include "reserva.h"

int main() {
    // Configurar a consola do Windows para ler acentos portugueses corretamente
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    // ====================================================
    // PASSO 1: LOGIN / REGISTO DO ORGANIZADOR + VIAJANTES
    // ====================================================
    AutenticacaoController fluxoLogin;
    Organizador* utilizadorLogado = fluxoLogin.executar();

    if (utilizadorLogado == nullptr) {
        std::cout << "\nA encerrar o programa com segurança...\n";
        return 0;
    }

    std::cout << "\n>>> Autenticação Efetuada com Sucesso! <<<\n";
    std::cout << "Operador Conectado: " << utilizadorLogado->obterNome() << "\n\n";

    // ====================================================
    // PASSO 2: SELECIONAR E VALIDAR DATAS DA VIAGEM
    // ====================================================

    Controller controladorDatas;
    Data datasValidadas = controladorDatas.obterDataValidada();

    // ====================================================
    // PASSO 3: SELECIONAR PAÍSES, CIDADES E ATIVIDADES
    // ====================================================
    std::cout << "\n====================================================\n";
    std::cout << "          PASSO 3: EXPLORAR DESTINOS E ROTEIRO      \n";
    std::cout << "====================================================\n";

    RepositorioCatalogo catalogo;
    try {
        catalogo.carregarTudo();
    }
    catch (const std::exception& e) {
        std::cout << "\n[ERRO DE CARREGAMENTO]: " << e.what() << std::endl;
        std::cout << "Certifique-se de que os ficheiros BaseDados-*.txt estão na pasta certa.\n";
        return 1;
    }

    RoteiroController meuRoteiro;
    meuRoteiro.definirDatas(datasValidadas);

    std::string comandoRoteiro = "";
    std::cout << "Comandos: 'V' (Ver Roteiro), 'L' (Limpar), 'G' (Gravar Roteiro e Avançar)\n";

    while (comandoRoteiro != "G" && comandoRoteiro != "g") {
        try {
            std::cout << "\n[Menu Catálogo]: ";
            std::getline(std::cin, comandoRoteiro);

            if (comandoRoteiro == "G" || comandoRoteiro == "g") {
                meuRoteiro.finalizarEGravar();
            }
            else if (comandoRoteiro == "V" || comandoRoteiro == "v") {
                meuRoteiro.mostrarResumo();
            }
            else if (comandoRoteiro == "L" || comandoRoteiro == "l") {
                meuRoteiro.esvaziarRoteiro();
            }
            else if (!comandoRoteiro.empty()) {
                std::cout << "Comando inválido no catálogo.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "\n[Aviso Roteiro]: " << e.what() << std::endl;
        }
    }

    // ====================================================
    // PASSO 4: PARTE DE PAGAR E ENGENHARIA DA RESERVA
    // ====================================================
    std::cout << "\n====================================================\n";
    std::cout << "          PASSO 4: GESTÃO FINANCEIRA E PAGAMENTO    \n";
    std::cout << "====================================================\n";

    Viagem viagemFinal;
    // Sincroniza as datas validadas no Passo 2 para a Ficha de Reserva Final
    viagemFinal.setChegada(datasValidadas.getChegada().dia, datasValidadas.getChegada().mes, datasValidadas.getChegada().ano);
    viagemFinal.setSaida(datasValidadas.getSaida().dia, datasValidadas.getSaida().mes, datasValidadas.getSaida().ano);

    bool terminarPrograma = false;
    while (!terminarPrograma) {
        int opcaoReserva;
        std::cout << "\n--- MENU FINAL DE RESERVA & PAGAMENTO ---\n";
        std::cout << "1. Visualizar Ficha Completa da Viagem\n";
        std::cout << "2. Modificar Título da Viagem\n";
        std::cout << "3. Modificar Notas Auxiliares\n";
        std::cout << "4. Ajustar Custo Total Manualmente\n";
        std::cout << "5. Configurar Método de Pagamento / Pagar\n";
        std::cout << "6. Reajustar Datas de Reserva\n";
        std::cout << "7. Exibir Identificador Único da Reserva\n";
        std::cout << "0. Confirmar, Gravar e Sair do Sistema\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "Opção: ";

        if (!(std::cin >> opcaoReserva)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opção Inválida!\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcaoReserva) {
            case 1: viagemFinal.print();                break;
            case 2: {
                std::cout << ">> Novo Título:\n";
                while (!viagemFinal.mudarTitulo());
                break;
            }
            case 3: {
                std::cout << ">> Novas Notas:\n";
                while (!viagemFinal.mudarNotasViagem());
                break;
            }
            case 4: viagemFinal.mudarCustoTotal();       break;
            case 5: viagemFinal.mudarMetodoPagamento();  break;
            case 6: viagemFinal.mudarData();             break;
            case 7: viagemFinal.mostrarNumeroReserva();  break;
            case 0:
                viagemFinal.estadoConfirmar(); // Atualiza o estado para "Confirmada" antes de fechar
                viagemFinal.gravarFicheiro();  // Grava a persistência final no txt
                terminarPrograma = true;
                std::cout << "\nReserva processada com sucesso. Ficheiros atualizados! Boa viagem!\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    }

    return 0;
}