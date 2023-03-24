#ifndef ALGO2_PRACTICA1_INTRODUCCION_CONTACTO_H
#define ALGO2_PRACTICA1_INTRODUCCION_CONTACTO_H

#include <string>

struct Contacto {
    size_t numero;
    std::string nombre;
    std::string apellido;
};

//pre: Numero deberia tener 8 digitos.
//post: Devuelve el puntero a contacto generado.
Contacto* generarContacto(const size_t& numero, const std::string& nombre, const std::string& apellido);

#endif
