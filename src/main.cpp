#include "agenda.h"
#include "libs/parser.h"
#include "libs/excepciones.h"
#include "libs/validaciones.h"
#include <iostream>
#include <fstream>

using namespace std;

void mostrar_menu() {
    cout << "1. Dar de alta un contacto" << endl;
    cout << "2. Mostrar todos los contactos" << endl;
    cout << "3. Mostrar direcciones de memoria de los contactos" << endl;
    cout << "4. Salir" << endl;
}

int main() {
    Agenda* agenda = new Agenda;
    try {
        procesarArchivo(agenda, RUTA_ARCHIVO);
    } catch (ArchivoNoExistenteException& e) {
        cout << "El archivo no existe. Se creara uno.";
        ofstream archivo(RUTA_ARCHIVO);
        return 0;
    }

    // ACLARACION: El switch y las distintas opciones deberian estar separadas. Mantengo en el main() para que se vea lo
    // que complete.
    int opcion;
    do {
        mostrar_menu();
        cin >> opcion;
        switch (opcion) {
            case 1: {
                string numero, nombre, apellido;
                do {
                    cout << "Ingrese un numero, luego un nombre, luego un apellido." << endl;
                    cin >> numero;
                    cin >> nombre;
                    cin >> apellido;
                } while (!esNumeroValido(numero));
                Contacto* contacto = generarContacto((unsigned int) stoi(numero), nombre, apellido);
                try {
                    agregarContacto(agenda, contacto);
                    cout << "El contacto se dio de alta correctamente." << endl;
                } catch (ContactoRepetidoException& e) {
                    cout << "Error: ya existe un contacto con el numero ingresado" << endl;
                }
                break;
            }
            case 2: {
                for (int i = 0; i < agenda->cantidad_contactos; i++) {
                    cout << agenda->contactos[i]->numero << " - " << agenda->contactos[i]->apellido << ", "
                         << agenda->contactos[i]->nombre << endl;
                }
                break;
            }
            case 3:
                for (int i = 0; i < agenda->cantidad_contactos; i++) {
                    cout << &(agenda->contactos[i]) << " - " << agenda->contactos[i] << " - "
                         << &(agenda->contactos[i]->numero) << " - " << agenda->contactos[i]->numero << endl;
                }
                break;
            case 4:
                cout << "Terminando programa." << endl;
                break;
            default:
                cout << "Error." << endl;
        }
    } while (opcion != 4);

    for (int i = 0; i < agenda->cantidad_contactos; i++) {
        delete agenda->contactos[i];
    }
    liberarMemoria(agenda);
    delete agenda;
}