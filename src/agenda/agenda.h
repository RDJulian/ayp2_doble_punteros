#ifndef HELADERA_H
#define HELADERA_H

#include "libs/constantes.h"
#include "contacto.h"

struct Agenda {
    Contacto** contactos = nullptr;
    size_t tamanio = 0;
    size_t cantidad_contactos = 0;
};

//pre: -
//post: Devuelve true si hay un contacto en la agenda con el numero ingresado, false de lo contrario.
bool contactoExistente(Agenda* agenda, const size_t& numero);

//pre: -
//post: Agrega el contacto a la agenda.
void agregarContacto(Agenda* agenda, Contacto* contacto);

//pre: -
//post: Libera la memoria reservada por el vector.
void liberarMemoria(Agenda* agenda);

#endif