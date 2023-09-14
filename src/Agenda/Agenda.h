#ifndef ALGO2_DOBLE_PUNTEROS_AGENDA_H
#define ALGO2_DOBLE_PUNTEROS_AGENDA_H

#include "Contacto.h"

class Agenda {
private:
    Contacto** contactos;
    size_t cantContactos;
    size_t cantActual;

    bool contactoExistente(Contacto* contacto);

public:
    Agenda(size_t cantContactos);

    Agenda(size_t cantContactos, std::string rutaArchivo);

    void agregarContacto(Contacto* contacto);

    void mostrarContactos();

    void mostrarDirecciones();

    void guardarContactos(std::string rutaArchivo);

    ~Agenda();
};

#endif