#include "matriz.h"
#include <iostream>

using namespace std;

// FUNCIONES PRIVADAS.

//pre: -
//post: Devuelve true si el indice es valido (0 <= i < filas, 0 <= j < columnas).
bool indiceValido(const Matriz& matriz, const int& i, const int& j);

//pre: -
//post: Reserva en memoria dinamica la matriz.
void inicializarMatriz(Matriz& matriz);

//pre: -
//post: Inicializa la matriz como matriz nula.
void matrizNula(const Matriz& matriz);

bool indiceValido(const Matriz& matriz, const int& i, const int& j) {
    return (0 <= i && 0 <= j && (size_t) i < matriz.fila && (size_t) j < matriz.columna);
}

void inicializarMatriz(Matriz& matriz) {
    matriz.matriz = new int* [matriz.fila];
    for (size_t i = 0; i < matriz.fila; i++) {
        matriz.matriz[i] = new int[(size_t) matriz.columna];
    }
}

void matrizNula(const Matriz& matriz) {
    for (size_t i = 0; i < matriz.fila; i++) {
        for (size_t j = 0; j < matriz.columna; j++) {
            matriz.matriz[i][j] = 0;
        }
    }
}

// FUNCIONES PUBLICAS.

Matriz generarMatriz(const int& fila, const int& columna) {
    if (fila < 1 || columna < 1) {
        throw DimensionesNoValidasException();
    } else {
        Matriz matriz;
        matriz.fila = (size_t) fila;
        matriz.columna = (size_t) columna;
        inicializarMatriz(matriz);
        matrizNula(matriz);
        return matriz;
    }
}

void imprimirMatriz(const Matriz& matriz) {
    for (size_t i = 0; i < matriz.fila; i++) {
        for (size_t j = 0; j < matriz.columna; j++) {
            cout << matriz.matriz[i][j] << "   ";
        }
        cout << endl;
    }
}

int& elemento(const Matriz& matriz, const int& i, const int& j) {
    if (!indiceValido(matriz, i, j)) {
        throw IndiceNoValidoException();
    } else {
        return matriz.matriz[i][j];
    }
}

void liberarMemoria(const Matriz& matriz) {
    for (size_t i = 0; i < matriz.fila; i++) {
        delete[] matriz.matriz[i];
    }
    delete[] matriz.matriz;
}