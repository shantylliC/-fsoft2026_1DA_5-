//
// Created by HQCamachoPC on 12/06/2026.
//

#include "RoteiroController.h"
#include "Excecoes.h"

RoteiroController::RoteiroController() {}

// 1. REGISTAR DESTINO SELECIONADO
void RoteiroController::registarEscolha(LocalidadeModel* localidadeSelecionada) {
    if (localidadeSelecionada != nullptr) {
        model.adicionarEscolha(localidadeSelecionada);
        view.mostrarMensagem("Adicionado: " + localidadeSelecionada->obterNome());
    } else {
        view.mostrarErro("Destino invalido!");
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
    // Interage com a View para obter a intenção crua do utilizador
    int opcao = view.pedirMetodoPagamento();

    // Avalia o resultado e aplica as regras de negócio necessárias
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
        // Se o cin falhar ou o número estiver fora do intervalo (0-2), lança a exceção
        throw InputInvalidoException("Opcao invalida! Escolha um numero correspondente ao menu (0, 1 ou 2).");
    }
}

// 5. FINALIZAR COMPRA E PERSISTIR DADOS NO DISCO
void RoteiroController::finalizarEGravar() {


    const auto& escolhas = model.obterEscolhas();

    // Regra de segurança 1: Bloquear gravação se não houver itens
    if (escolhas.empty()) {
        throw RoteiroVazioException("O roteiro esta vazio! Adicione destinos antes de gravar.");
    }

    // Regra de segurança 2: Garantir que o utilizador escolheu como quer pagar
    if (Financeiro::obterMetodoSelecionado() == MetodoPagamento::NAO_DEFINIDO) {
        throw InputInvalidoException("Selecione um metodo de pagamento valido antes de finalizar a reserva.");
    }

    double subtotal = Financeiro::calcularTotalBase(escolhas);
    double totalFinal = Financeiro::calcularTotalComIVA(subtotal);

    // Manda o model gravar fisicamente no disco rígido
      if (model.gravarFicheiroReserva(numReserva, estadoVia, tituloVia, notasVia, chegada, saida, duracaoDias, subtotal, totalFinal)) {
        view.mostrarMensagem("Viagem gravada com sucesso!");
    } else {
        throw ErroFormatacaoFicheiroException("Falha ao abrir o ficheiro de reserva para escrita.");
    }
}
