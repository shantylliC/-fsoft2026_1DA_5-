//
// Controller: liga model e view, expõe operações ao main
//

#include "alt_estados_controller.h"

AltEstadosController::AltEstadosController() {}

void AltEstadosController::confirmar() {
    model.confirmar();
}

void AltEstadosController::cancelar() {
    model.cancelar();
}

void AltEstadosController::mostrarEstado() const {
    view.mostrarEstado(model.getEstadoStr());
}
