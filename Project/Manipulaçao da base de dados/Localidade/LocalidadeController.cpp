#include "LocalidadeController.h"

void LocalidadeController::gerirApresentacao(LocalidadeModel* localidade) {
    if (localidade == nullptr) {
        view.mostrarErroFicheiro();
    } else {
        // Polimorfismo puro em ação
        view.mostrarDetalhes(localidade);
    }
}
