#ifndef ALGO2_DOBLE_PUNTEROS_LECTOR_H
#define ALGO2_DOBLE_PUNTEROS_LECTOR_H

#include "Agenda.h"
#include <string>
#include <vector>

const int CANT_PARAMETROS = 3;
const int DIGITOS_NUMERO = 8;

const int NUMERO = 0;
const int NOMBRE = 1;
const int APELLIDO = 2;

class Lector {
private:
    static std::vector<std::string> split(std::string s, char del);

    static bool esEntero(std::string numero);

    static bool esNumeroValido(std::string entrada);

    static Contacto* generarContacto(std::vector<std::string> linea);

public:
    static void procesarArchivo(Agenda* agenda, std::string ruta_archivo);
};


#endif
