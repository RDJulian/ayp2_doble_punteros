#include <iostream>
#include "Agenda.h"
#include <random>

// Ignorar esto: solamente es para generar un numero al azar.
std::random_device rd;
std::mt19937 gen(rd());

unsigned int random(int low, int high) {
    std::uniform_int_distribution<> dist(low, high);
    return unsigned(dist(gen));
}

using namespace std;

const string RUTA_ARCHIVO = "Agenda.csv";

int main() {
    Agenda agenda(50, RUTA_ARCHIVO);
    string opcion;
    // Esto podria (y deberia) ser una clase Menu pero por simplicidad lo dejo asi.
    do {
        cout << "Ingrese una opcion\n1 - Alta\n2 - Contactos\n3 - Direcciones\nsalir - Salir del programa" << endl;
        getline(cin >> ws, opcion);
        if (opcion == "1") {
            unsigned int r = random(10000000, 99999999);
            Contacto* contacto = new Contacto(r, "Test", "Test");
            agenda.agregarContacto(contacto);
        } else if (opcion == "2") {
            agenda.mostrarContactos();
        } else if (opcion == "3") {
            agenda.mostrarDirecciones();
        } else if (opcion != "salir") {
            cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != "salir");
    agenda.guardarContactos(RUTA_ARCHIVO);
    return 0;
}