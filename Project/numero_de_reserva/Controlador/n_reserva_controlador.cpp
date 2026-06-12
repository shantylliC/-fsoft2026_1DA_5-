//
// Created by Utilizador on 12-Jun-26.
//
void Numero_reserva_controller::mostrar() {
    view.mostrarNumeroReserva(modelo.getNumeroReserva());
}

void Numero_reserva_controller::gerarNovaReserva() {
    modelo.incrementar();
    view.mostrarMensagem("Nova reserva gerada.");
    mostrar();
}

int Numero_reserva_controller::getNumeroAtual() const {
    return modelo.getNumeroReserva();
}