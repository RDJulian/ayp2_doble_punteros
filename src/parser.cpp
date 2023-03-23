#include "parser.h"
#include "excepciones.h"
#include "validaciones.h"
#include "contacto.h"
#include <fstream>
#include <vector>

using namespace std;

// FUNCIONES PRIVADAS

//pre: -
//post: Devuelve la informacion de la linea, separada en base al DELIMITADOR.
vector<string> procesarLinea(const std::string& linea);

//pre: La informacion debe tener solamente dos elementos y la cantidad debe ser entera.
//post: Devuelve una fruta con la informacion ingresada.
Contacto* generarContacto(vector<string> informacion);

// ACLARACION SUPER IMPORTANTE: NO PUEDEN USAR VECTOR PARA EL PRIMER TP.
vector<string> procesarLinea(const string& linea) {
    vector<string> informacion;
    string dato;
    for (char caracter: linea) {
        if (caracter == DELIMITADOR) {
            informacion.push_back(dato);
            dato.clear();
        } else if (caracter == ESPACIO_PALABRAS) {
            dato += ' ';
        } else if (isalnum(caracter)) {
            dato += caracter;
        }
    }
    informacion.push_back(dato);
    return informacion;
}

Contacto* generarContacto(vector<string> informacion) {
    if (!esInformacionValida(informacion)) {
        throw ContactoNoValidoException();
    } else {
        return generarContacto((unsigned) stoi((informacion[NUMERO])), informacion[NOMBRE],
                               informacion[APELLIDO]);
    }
}

// FUNCIONES PUBLICAS

void procesarArchivo(Agenda* agenda, const string& ruta_archivo) {
    string linea;
    ifstream archivo(ruta_archivo);
    if (!archivo.is_open()) {
        throw ArchivoNoExistenteException();
    } else {
        while (getline(archivo, linea)) {
            vector<string> informacion = procesarLinea(linea);
            try {
                Contacto* contacto = generarContacto(informacion);
                // NOTA: Al programar esta funcion, inmediatamente se deberia ver los contactos en pantalla.
                agregarContacto(agenda, contacto);
            } catch (ContactoNoValidoException& e) {
                // Ignora, pero puede mandar la linea problematica a otro archivo, por ejemplo.
            }
        }
    }
    archivo.close();
}