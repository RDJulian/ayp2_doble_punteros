#include "agenda.h"
#include "parser.h"
#include "excepciones.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    Agenda* agenda = new Agenda;
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