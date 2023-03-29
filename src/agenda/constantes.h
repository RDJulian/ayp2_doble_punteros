#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>

// Archivo
const std::string RUTA_ARCHIVO = "agenda.txt";

// Indices
const int CAMPOS = 3;
const int NUMERO = 0;
const int NOMBRE = 1;
const int APELLIDO = 2;

// Validaciones
const int DIGITOS_NUMERO = 8;

// Array
const int TAMANIO_INICIAL = 2;

// Parser
const char DELIMITADOR = ',';
const char ESPACIO_PALABRAS = ' ';

// Menu
const int ALTA_CONTACTO = 1;
const int MOSTRAR_CONTACTOS = 2;
const int MOSTRAR_DIRECCIONES = 3;
const int SALIR = 4;

// Exit Code
const int ERROR_ARCHIVO = 1;

#endif