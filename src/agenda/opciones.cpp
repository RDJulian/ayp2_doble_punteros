#include "agenda.h"
#include "libs/excepciones.h"
#include "libs/validaciones.h"
#include <iostream>
#include "opciones.h"

using namespace std;

void altaContacto(Agenda* agenda) {
    std::string numero, nombre, apellido;
    do {
        cout << "Ingrese un numero, luego un nombre, luego un apellido." << endl;
        cin >> numero;
        cin >> nombre;
        cin >> apellido;
    } while (!esNumeroValido(numero));
    Contacto* contacto = generarContacto((std::size_t) stoi(numero), nombre, apellido);
    try {
        agregarContacto(agenda, contacto);
        cout << "El contacto se dio de alta correctamente." << endl;
    } catch (ContactoRepetidoException& e) {
        cout << "Error: ya existe un contacto con el numero ingresado" << endl;
        delete contacto;
    }
}

void mostrarContactos(const Agenda* agenda) {
    for (size_t i = 0; i < agenda->cantidad_contactos; i++) {
        cout << agenda->contactos[i]->numero << " - " << agenda->contactos[i]->apellido << ", "
             << agenda->contactos[i]->nombre << endl;
    }
}

void mostrarDirecciones(const Agenda* agenda) {
    for (size_t i = 0; i < agenda->cantidad_contactos; i++) {
        cout << &(agenda->contactos[i]) << " - " << agenda->contactos[i] << " - "
             << &(agenda->contactos[i]->numero) << " - " << agenda->contactos[i]->numero << endl;
    }
}