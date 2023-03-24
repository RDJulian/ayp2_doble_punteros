#include "agenda.h"
#include "libs/parser.h"
#include "libs/excepciones.h"
#include "libs/validaciones.h"
#include "menu.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    Agenda* agenda = new Agenda;
    try {
        procesarArchivo(agenda, RUTA_ARCHIVO);
    } catch (ArchivoNoExistenteException& e) {
        cout << "El archivo no existe. Se creara uno. Ejecute nuevamente el programa." << endl;
        ofstream archivo(RUTA_ARCHIVO);
        return ERROR_ARCHIVO;
    }

    int opcion;
    do {
        mostrar_menu();
        cin >> opcion;
        procesarOpcion(agenda, opcion);
    } while (opcion != SALIR);

    // Es responsabilidad del usuario liberar la memoria dinamica de los elementos array y no del array.
    for (size_t i = 0; i < agenda->cantidad_contactos; i++) {
        delete agenda->contactos[i];
    }
    liberarMemoria(agenda);
    return 0;
}