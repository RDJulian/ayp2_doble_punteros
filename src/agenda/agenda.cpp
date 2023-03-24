#include "agenda.h"
#include "libs/vectorAgenda.h"
#include "libs/excepciones.h"

using namespace std;

bool contactoExistente(Agenda* agenda, const size_t& numero) {
    bool encontrado = false;
    size_t i = 0;
    while (i < agenda->cantidad_contactos && !encontrado) {
        if (agenda->contactos[i]->numero == numero) {
            encontrado = true;
        }
        i++;
    }
    return encontrado;
}

void agregarContacto(Agenda* agenda, Contacto* contacto) {
    if (contactoExistente(agenda, contacto->numero)) {
        throw ContactoRepetidoException();
    } else {
        verificarTamanio(agenda);
        agenda->contactos[agenda->cantidad_contactos] = contacto;
        agenda->cantidad_contactos++;
    }
}

void liberarMemoria(Agenda* agenda) {
    if (agenda->contactos != nullptr) {
        delete[] agenda->contactos;
    }
    delete agenda;
}