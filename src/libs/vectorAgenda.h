#ifndef VECTORAGENDA_H
#define VECTORAGENDA_H

#include "../contacto.h"
#include "constantes.h"
#include "../agenda.h"

//pre: -
//post: Devuelve true si el vector esta lleno. Devuelve false de lo contrario.
bool lleno(Agenda* agenda);

//pre: El tamaño inicial debe ser mayor que 0.
//post: Genera un vector en la agenda con el tamaño indicado.
void generarVector(Agenda* agenda, const unsigned long& tamanio);

//pre: -
//post: Genera un nuevo vector en la agenda con el doble del tamaño anterior, manteniendo los contactos.
void ampliarVector(Agenda* agenda);

// pre: -
// post: Verifica el tamaño del vector y expande de ser necesario.
void verificarTamanio(Agenda* agenda);

#endif
