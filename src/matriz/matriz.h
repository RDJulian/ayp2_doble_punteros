#ifndef ALGO2_DOBLE_PUNTEROS_MATRIZ_H
#define ALGO2_DOBLE_PUNTEROS_MATRIZ_H

#include <exception>

struct Matriz {
    int** matriz = nullptr;
    size_t fila = 0;
    size_t columna = 0;
};

class DimensionesNoValidasException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: el contacto no tiene el formato correcto.";
    }
};

class IndiceNoValidoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: el indice ingresado no es valido.";
    }
};

//pre: Ninguna de las dimesiones puede ser menor que 1.
//post: Genera una matriz nula con las dimensiones indicadas.
Matriz generarMatriz(const int& fila, const int& columna);

//pre: -
//post: Imprime por pantalla la matriz.
void imprimirMatriz(const Matriz& matriz);

//pre: El indice debe ser valido, es decir, 0 <= i < filas, 0 <= j < columnas.
//post: Devuelve la referecia al elemento accedido.
int& elemento(const Matriz& matriz, const int& i, const int& j);

//pre: -
//post: Libera la memoria reservada por la matriz.
void liberarMemoria(const Matriz& matriz);

#endif