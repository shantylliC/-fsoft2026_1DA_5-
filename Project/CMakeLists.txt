cmake_minimum_required(VERSION 4.1)
project(_fsoft2026_1DA_5_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(_fsoft2026_1DA_5_
        data.cpp
        data.h
        main.cpp
        reserva.cpp
        reserva.h
        alt_estados.h
        alt_estados.cpp
        titulo_esub/titulo_esub.cpp
        titulo_esub/titulo_esub.h
        pagamento.h
        pagamento.cpp
        numero_de_reserva/Modelo/n_reserva_modelo.h
        numero_de_reserva/View/n_reserva_view.h
        numero_de_reserva/Controlador/n_reserva_controlador.h
        titulo_esub/Controlador/titulo_notas_controlador.h
        titulo_esub/Modelo/titulo_notas_modelo.h
        titulo_esub/View/titulo_notas_view.h
)
