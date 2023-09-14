#include <iostream>
#include "Contacto.h"

using namespace std;

Contacto::Contacto(unsigned numero, std::string nombre, std::string apellido) {
    this->numero = numero;
    this->nombre = nombre;
    this->apellido = apellido;
}

// Este getter se puede sacar una vez implementado operator==()
unsigned int Contacto::getNumero() {
    return numero;
}

void Contacto::mostrarInformacion() {
    cout << numero << " - " << apellido << ", " << nombre << endl;
}

void Contacto::mostrarDirecciones() {
    cout << "Direccion del numero: " << &numero << endl;
}

void Contacto::guardarContacto(ofstream& archivo) {
    archivo << numero << ',' << nombre << ',' << apellido << endl;
}