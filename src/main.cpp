#include "agenda.h"
#include "libs/parser.h"
#include "libs/excepciones.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    Agenda* agenda = nullptr; //VER SI ESTA LINEA ES CORRECTA//
    try {
        procesarArchivo(agenda, RUTA_ARCHIVO);
    } catch (ArchivoNoExistenteException& e) {
        cout << "El archivo no existe. Se creara uno.";
        ofstream archivo(RUTA_ARCHIVO);
        return 0;
    }

    // COMPLETAR //

    // NOTA: Manejar apropiadamente la memoria dinamica.
}