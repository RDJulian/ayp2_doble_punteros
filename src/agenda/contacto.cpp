#include "contacto.h"

using namespace std;

Contacto* generarContacto(const size_t& numero, const string& nombre, const string& apellido) {
    Contacto* contacto = new Contacto;
    contacto->numero = numero;
    contacto->nombre = nombre;
    contacto->apellido = apellido;
    return contacto;
}