#include "vectorAgenda.h"
#include "excepciones.h"

bool lleno(Agenda* agenda) {
    return ((int) agenda->tamanio == agenda->cantidad_contactos);
}

void generarVector(Agenda* agenda, const std::size_t& tamanio) {
    if (tamanio < 1) {
        throw TamanioInicialNoValidoException();
    } else {
        agenda->contactos = new Contacto* [tamanio];
        agenda->tamanio = tamanio;
    }
}

void ampliarVector(Agenda* agenda) {
    agenda->tamanio *= 2;
    Contacto** nuevo_vector = new Contacto* [agenda->tamanio];
    for (int i = 0; i < agenda->cantidad_contactos; i++) {
        nuevo_vector[i] = agenda->contactos[i];
    }
    delete[] agenda->contactos;
    agenda->contactos = nuevo_vector;
}

void verificarTamanio(Agenda* agenda) {
    if (agenda->contactos == nullptr) {
        generarVector(agenda, TAMANIO_INICIAL);
    }
    if (lleno(agenda)) {
        ampliarVector(agenda);
    }
}