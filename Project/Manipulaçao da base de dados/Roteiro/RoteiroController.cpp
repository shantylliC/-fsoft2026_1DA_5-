#include "RoteiroController.h"
#include "Excecoes.h"
#include "data.h"
#include "AtividadeModel.h"
#include "Financeiro.h"
#include <limits>
#include <iostream>
#include <cmath>

RoteiroController::RoteiroController() : datasDoRoteiro(1, 1, 2026, 1, 1, 2026) {}


// 1. REGISTAR DESTINO SELECIONADO
void RoteiroController::registarEscolha(LocalidadeModel* localidadeSelecionada) {
    if (localidadeSelecionada != nullptr) {
        AtividadeModel* atividade = dynamic_cast<AtividadeModel*>(localidadeSelecionada);

        if (atividade != nullptr) {
            std::string horaDesejada;
            int diaDesejado = 0;
            bool agendamentoValido = false;

            while (!agendamentoValido) {

                // CORREÇÃO AQUI: Alterado de 'datasViagem' para 'datasDoRoteiro'
                // para condizer exatamente com a variável privada do teu .h
                int totalDiasViagem = datasDoRoteiro.getNumeroDias();

                std::cout << "\nEm que dia da viagem deseja realizar a atividade '" << atividade->obterNome()
                          << "'? (Opções: 1 a " << totalDiasViagem << "): ";

                if (!(std::cin >> diaDesejado)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    view.mostrarErro("Digite um número válido para o dia.");
                    continue;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Validação extra de segurança: impedir que escolham um dia fora dos limites da viagem
                if (diaDesejado < 1 || diaDesejado > totalDiasViagem) {
                    view.mostrarErro("Dia inválido! Escolha um dia entre 1 e " + std::to_string(totalDiasViagem) + ".");
                    continue;
                }

                std::cout << "Introduza o horário de início (ex: 14:30): ";
                std::getline(std::cin, horaDesejada);

                size_t pos = horaDesejada.find(':');
                if (pos == std::string::npos) {
                    view.mostrarErro("Formato de hora inválido! Use o formato HH:MM.");
                    continue;
                }

                // Converter a nova hora para minutos absolutos
                int h = std::stoi(horaDesejada.substr(0, pos));
                int m = std::stoi(horaDesejada.substr(pos + 1));
                int minutosNovo = (h * 60) + m;

                // --- VALIDAÇÃO DE CHOQUE (JANELA DE 2 HORAS / 120 MINUTOS) ---
                bool houveChoque = false;
                for (auto* item : model.obterEscolhas()) {
                    AtividadeModel* atExistente = dynamic_cast<AtividadeModel*>(item);

                    // Se for no mesmo dia, testamos a proximidade dos minutos
                    if (atExistente != nullptr && atExistente->obterDiaAgendado() == diaDesejado) {
                        int minutosExistente = atExistente->obterMinutosDoDia();

                        // A diferença absoluta entre os inícios tem de ser de pelo menos 120 minutos
                        if (std::abs(minutosExistente - minutosNovo) < 120) {
                            view.mostrarErro("❌ Choque de Horários! A atividade '" + atExistente->obterNome() +
                                             "' já ocupa este dia às " + atExistente->obterHoraAgendada() +
                                             " (As atividades duram cerca de 2 horas).");
                            houveChoque = true;
                            break;
                        }
                    }
                }

                if (!houveChoque) {
                    atividade->definirAgendamento(diaDesejado, horaDesejada);
                    agendamentoValido = true;
                    view.mostrarMensagem("Horário e dia agendados com sucesso!");
                }
            }
        }

        model.adicionarEscolha(localidadeSelecionada);
        view.mostrarMensagem("Adicionado: " + localidadeSelecionada->obterNome());
    } else {
        view.mostrarErro("Destino invalido!");
    }
}

// NOVA FUNÇÃO: Carrega os dados silenciosamente do ficheiro sem interrupções textuais
void RoteiroController::carregarEscolhaSessao(LocalidadeModel* localidadeSelecionada, int dia, const std::string& hora) {
    if (localidadeSelecionada != nullptr) {
        AtividadeModel* atividade = dynamic_cast<AtividadeModel*>(localidadeSelecionada);
        if (atividade != nullptr) {
            atividade->definirAgendamento(dia, hora);
        }
        model.adicionarEscolha(localidadeSelecionada);
    }
}

// 2. LIMPAR O ROTEIRO ATUAL
void RoteiroController::esvaziarRoteiro() {
    model.esvaziar();
    view.mostrarMensagem("Roteiro limpo com sucesso!");
}

// 3. EXIBIR RESUMO NO ECRÃ
void RoteiroController::mostrarResumo() {
    const auto& escolhas = model.obterEscolhas();

    if (escolhas.empty()) {
        view.mostrarMensagem("\nO seu roteiro esta vazio!");
        return;
    }

    // O Controller orquestra as regras de negócio delegando cálculos ao Financeiro
    double valorBase = Financeiro::calcularTotalBase(escolhas);
    double valorIVA  = Financeiro::calcularValorIVA(valorBase);
    double valorTotal = Financeiro::calcularTotalComIVA(valorBase);

    view.mostrarTalao(escolhas, valorBase, valorIVA, valorTotal);
}


void RoteiroController::alterarMetodoPagamento() {
    int opcao = view.pedirMetodoPagamento();

    if (opcao == 0) {
        Financeiro::definirMetodo(MetodoPagamento::DINHEIRO);
        view.mostrarMensagem("Metodo de pagamento alterado para Dinheiro.");
    }
    else if (opcao == 1) {
        Financeiro::definirMetodo(MetodoPagamento::CARTAO);
        view.mostrarMensagem("Metodo de pagamento alterado para Cartao.");
    }
    else if (opcao == 2) {
        Financeiro::definirMetodo(MetodoPagamento::TRANSFERENCIA);
        view.mostrarMensagem("Metodo de pagamento alterado para Transferencia.");
    }
    else {
        throw InputInvalidoException("Opcao invalida! Escolha um numero correspondente ao menu (0, 1 ou 2).");
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// 5. FINALIZAR COMPRA E PERSISTIR DADOS NO DISCO
void RoteiroController::finalizarEGravar() {

    const auto& escolhas = model.obterEscolhas();

    if (escolhas.empty()) {
        throw RoteiroVazioException("O roteiro esta vazio! Adicione destinos antes de gravar.");
    }

    if (Financeiro::obterMetodoSelecionado() == MetodoPagamento::NAO_DEFINIDO) {
        throw InputInvalidoException("Selecione um metodo de pagamento valido antes de finalizar a reserva.");
    }

    double subtotal = Financeiro::calcularTotalBase(escolhas);
    double totalFinal = Financeiro::calcularTotalComIVA(subtotal);

    // Datas calculadas dinamicamente a partir do objeto sincronizado
    std::string stringChegada = std::to_string(this->datasDoRoteiro.getChegada().dia) + "/" +
                                std::to_string(this->datasDoRoteiro.getChegada().mes) + "/" +
                                std::to_string(this->datasDoRoteiro.getChegada().ano);

    std::string stringSaida = std::to_string(this->datasDoRoteiro.getSaida().dia) + "/" +
                              std::to_string(this->datasDoRoteiro.getSaida().mes) + "/" +
                              std::to_string(this->datasDoRoteiro.getSaida().ano);

    int diasDeViagem = this->datasDoRoteiro.getNumeroDias();

    int idReservaDumb = rand() % 9000 + 1000;
    std::string estadoDumb = "CONFIRMADA";
    std::string tituloDumb = "Viagem Grupo FSOFT";
    std::string notasDumb = "Processado e Validado pelo Modulo de Datas.";

    if (model.gravarFicheiroReserva(idReservaDumb, estadoDumb, tituloDumb, notasDumb, stringChegada, stringSaida, diasDeViagem, subtotal, totalFinal)) {
        view.mostrarMensagem("Viagem gravada com sucesso!");
    } else {
        throw ErroFormatacaoFicheiroException("Falha ao abrir o ficheiro de reserva para escrita.");
    }
}

// CORREÇÃO AQUI: Agora a função recebe as datas do main e guarda-as
// de verdade na variável privada 'datasDoRoteiro'!
void RoteiroController::definirDatas(Data novasDatas) {
    this->datasDoRoteiro = novasDatas;
    std::cout << "\n[Sistema] Período de calendário associado ao Roteiro com sucesso.\n";
}

double RoteiroController::obterPrecoFinalComIVA() const {
    double valorBase = Financeiro::calcularTotalBase(model.obterEscolhas());
    return Financeiro::calcularTotalComIVA(valorBase);
}