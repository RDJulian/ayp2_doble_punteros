#include "vectorAgenda.h"
#include "excepciones.h"

// FUNCIONES PRIVADAS

//pre: -
//post: Devuelve true si el vector esta lleno. Devuelve false de lo contrario.
bool lleno(Agenda* agenda);

//pre: El tamaño inicial debe ser mayor que 0.
//post: Genera un vector en la agenda con el tamaño indicado.
void generarVector(Agenda* agenda, const size_t& tamanio);

//pre: -
//post: Genera un nuevo vector en la agenda con el doble del tamaño anterior, manteniendo los contactos.
void ampliarVector(Agenda* agenda);

bool lleno(Agenda* agenda) {
    return (agenda->tamanio == agenda->cantidad_contactos);
}

void generarVector(Agenda* agenda, const size_t& tamanio) {
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
    for (size_t i = 0; i < agenda->cantidad_contactos; i++) {
        nuevo_vector[i] = agenda->contactos[i];
    }
    delete[] agenda->contactos;
    agenda->contactos = nuevo_vector;
}

// FUNCIONES PUBLICAS

void verificarTamanio(Agenda* agenda) {
    if (agenda->contactos == nullptr) {
        generarVector(agenda, TAMANIO_INICIAL);
    }
    if (lleno(agenda)) {
        ampliarVector(agenda);
    }
}