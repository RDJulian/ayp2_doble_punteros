#include <fstream>
#include <iostream>
#include "Agenda.h"
#include "Lector.h"

using namespace std;

Agenda::Agenda(size_t cantContactos) {
    this->contactos = new Contacto* [cantContactos];
    this->cantContactos = cantContactos;
    this->cantActual = 0;
}

Agenda::Agenda(size_t cantContactos, std::string rutaArchivo) : Agenda(cantContactos) {
    Lector::procesarArchivo(this, rutaArchivo);
}

bool Agenda::contactoExistente(Contacto* contacto) {
    bool existente = false;
    size_t i = 0;
    while (!existente and i < cantActual) {
        // Claro caso de Tell, don't ask, que con sobrecarga de operadores se mejora.
        // if (contactos[i] == contacto)
        if (contactos[i]->getNumero() == contacto->getNumero())
            existente = true;
        i++;
    }
    return existente;
}

void Agenda::agregarContacto(Contacto* contacto) {
    if (cantActual >= cantContactos || contactoExistente(contacto)) {
        delete contacto;
    } else {
        contactos[cantActual] = contacto;
        cantActual++;
    }
}

// Itero con logica de punteros.
// Mas directo es acceder con [], pero funciona.
void Agenda::mostrarContactos() {
    Contacto** pContacto = contactos;
    for (size_t _ = 0; _ < cantActual; _++) {
        (*pContacto)->mostrarInformacion();
        pContacto++;
    }
    cout << endl;
}

void Agenda::mostrarDirecciones() {
    for (size_t i = 0; i < cantActual; i++) {
        cout << "Direccion del puntero: " << &contactos[i] << endl;
        cout << "Direccion del contacto: " << contactos[i] << endl;
        contactos[i]->mostrarDirecciones();
        cout << endl;
    }
    cout << endl;
}

void Agenda::guardarContactos(std::string rutaArchivo) {
    ofstream archivo(rutaArchivo);
    for (size_t i = 0; i < cantActual; i++) {
        contactos[i]->guardarContacto(archivo);
    }
}

// NOTA IMPORTANTE: Si lo que estamos programando es una estructura de datos,
// no es correcto que libere la memoria que guarda.
// En este caso, como la Agenda es la encargada de los contactos, y un contacto
// fuera de una Agenda no tiene mucho sentido, es apropiado que los libere.
Agenda::~Agenda() {
    for (size_t i = 0; i < cantActual; i++) {
        delete contactos[i];
    }
    delete[] contactos;
}