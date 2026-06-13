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

        pagamento.h
        pagamento.cpp

        numero_de_reserva/Controlador/n_reserva_controlador.h
        numero_de_reserva/Modelo/n_reserva_modelo.h
        numero_de_reserva/View/n_reserva_view.h

        numero_de_reserva/Controlador/n_reserva_controlador.cpp
        numero_de_reserva/Modelo/n_reserva_modelo.cpp
        numero_de_reserva/View/n_reserva_view.cpp

        titulo_notas/Controlador/titulo_notas_controlador.h
        titulo_notas/Modelo/titulo_notas_modelo.h
        titulo_notas/View/titulo_notas_view.h

        titulo_notas/Controlador/titulo_notas_controlador.cpp
        titulo_notas/Modelo/titulo_notas_modelo.cpp
        titulo_notas/View/titulo_notas_view.cpp

        alt_estados/Controlador/alt_estados_controller.h
        alt_estados/Modelo/alt_estados_modelo.h
        alt_estados/View/alt_estados_view.h

        alt_estados/Controlador/alt_estados_controller.cpp
        alt_estados/Modelo/alt_estados_modelo.cpp
        alt_estados/View/alt_estados_view.cpp

)
