#include <iostream>
#include "matriz.h"

using namespace std;

int main() {
    Matriz matriz;
    int fila, columna;

    cout << "Cantidad de filas: ";
    cin >> fila;
    cout << "Cantidad de columnas: ";
    cin >> columna;
    cout << endl;

    try {
        matriz = generarMatriz(fila, columna);
    } catch (DimensionesNoValidasException& e) {
        cout << "Se intento crear una matriz no valida, terminando el programa." << endl;
        return 1;
    }

    imprimirMatriz(matriz);
    cout << endl;
    elemento(matriz, fila / 2, columna / 2) = 5;
    imprimirMatriz(matriz);
    cout << endl;
    cout << elemento(matriz, fila / 2, columna / 2) << endl;
    liberarMemoria(matriz);

    return 0;
}
