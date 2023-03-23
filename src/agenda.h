#ifndef HELADERA_H
#define HELADERA_H

#include "constantes.h"
#include "contacto.h"

struct Agenda {
    Contacto** contactos = nullptr;
    size_t tamanio = 0;
    int cantidad_contactos = 0;
};

//pre: -
//post: Devuelve true si el vector esta lleno. Devuelve false de lo contrario.
bool lleno(Agenda* agenda);

//pre: -
//post: Agrega la fruta a la heladera.
void agregarContacto(Agenda* agenda, Contacto* contacto);

//pre: -
//post: Libera la memoria reservada por el vector.
void liberar_memoria(Agenda* agenda);

#endif