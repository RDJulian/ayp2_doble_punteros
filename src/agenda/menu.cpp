#include <iostream>
#include "libs/parser.h"
#include "agenda.h"
#include "menu.h"
#include "opciones.h"

using namespace std;

void mostrar_menu() {
    cout << "1. Dar de alta un contacto" << endl;
    cout << "2. Mostrar todos los contactos" << endl;
    cout << "3. Mostrar direcciones de memoria de los contactos" << endl;
    cout << "4. Salir" << endl;
}

void procesarOpcion(Agenda* agenda, int opcion) {
    switch (opcion) {
        case ALTA_CONTACTO: {
            altaContacto(agenda);
            break;
        }
        case MOSTRAR_CONTACTOS: {
            mostrarContactos(agenda);
            break;
        }
        case MOSTRAR_DIRECCIONES:
            mostrarDirecciones(agenda);
            break;
        case SALIR:
            cout << "Terminando programa." << endl;
            break;
        default:
            cout << "Error." << endl;
    }
}