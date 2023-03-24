#ifndef ALGO2_DOBLE_PUNTEROS_OPCIONES_H
#define ALGO2_DOBLE_PUNTEROS_OPCIONES_H

//pre: -
//post: Da de alta en la agenda el contacto ingresado. Si el numero ya estaba en la agenda, muestra un mensaje de error.
void altaContacto(Agenda* agenda);

//pre: -
//post: Muestra por pantalla todos los contactos de la agenda.
void mostrarContactos(const Agenda* agenda);

//pre: -
//post: Muestra por pantalla las distintas direcciones de memoria de los contactos de la agenda.
void mostrarDirecciones(const Agenda* agenda);

#endif
