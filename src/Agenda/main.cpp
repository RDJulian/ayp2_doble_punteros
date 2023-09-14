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
    string opcion;
    do {
        cout << "Ingrese una opcion\n1 - Alta\n2 - Contactos\n3 - Direcciones\nsalir - Salir del programa" << endl;
        getline(cin >> ws, opcion);
        if (opcion == "1") {
        } else if (opcion == "2") {
        } else if (opcion == "3") {
        } else if (opcion != "salir") {
            cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != "salir");
    return 0;
}