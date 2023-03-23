#include "agenda.h"
#include "excepciones.h"

using namespace std;

// FUNCIONES PRIVADAS

//pre: El tamaño inicial debe ser mayor que 0.
//post: Genera un vector en la heladera con el tamaño indicado.
void generarVector(Agenda* agenda, const size_t& tamanio);

//pre: -
//post: Genera un nuevo vector en la heladera con el doble del tamaño anterior, manteniendo las frutas.
void ampliarVector(Agenda* agenda);

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
    for (int i = 0; i < agenda->cantidad_contactos; i++) {
        nuevo_vector[i] = agenda->contactos[i];
    }
    delete[] agenda->contactos;
    agenda->contactos = nuevo_vector;
}

// FUNCIONES PUBLICAS

bool lleno(Agenda* agenda) {
    return ((int) agenda->tamanio == agenda->cantidad_contactos);
}

void agregarContacto(Agenda* agenda, Contacto* contacto) {
    if (agenda->contactos == nullptr) {
        generarVector(agenda, TAMANIO_INICIAL);
    }
    if (lleno(agenda)) {
        ampliarVector(agenda);
    }

    //COMPLETAR//
    
}

void liberar_memoria(Agenda& agenda) {
    if (agenda.contactos != nullptr) {
        delete[] agenda.contactos;
    }
}
