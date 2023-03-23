#ifndef HELADERA_H
#define HELADERA_H

#include "libs/constantes.h"
#include "contacto.h"

struct Agenda {
    Contacto** contactos = nullptr;
    size_t tamanio = 0;
    int cantidad_contactos = 0;
};

//pre: -
//post: Agrega el contacto a la agenda.
void agregarContacto(Agenda* agenda, Contacto* contacto);

//pre: -
//post: Libera la memoria reservada por el vector.
void liberarMemoria(Agenda* agenda);

#endif