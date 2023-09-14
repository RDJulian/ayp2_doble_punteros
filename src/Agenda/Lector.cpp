#include "Lector.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> Lector::split(string s, char del) {
    stringstream ss(s);
    string token;
    vector<string> res;
    while (!ss.eof()) {
        getline(ss, token, del);
        res.push_back(token);
    }
    return res;
}

bool Lector::esEntero(string numero) {
    if (all_of(numero.begin(), numero.end(), [](char digito) { return isdigit(digito); })) {
        return true;
    } else {
        return false;
    }
}

bool Lector::esNumeroValido(string entrada) {
    return (esEntero(entrada) && entrada.length() == DIGITOS_NUMERO);
}

Contacto* Lector::generarContacto(vector<string> linea) {
    if (linea.size() == CANT_PARAMETROS && esNumeroValido(linea[NUMERO])) {
        return new Contacto(unsigned(stoi(linea[NUMERO])), linea[NOMBRE], linea[APELLIDO]);
    } else {
        return nullptr;
    }
}

void Lector::procesarArchivo(Agenda* agenda, string rutaArchivo) {
    string linea;
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        return;
    } else {
        while (getline(archivo, linea)) {
            Contacto* contacto = generarContacto(split(linea, ','));
            if (contacto) {
                agenda->agregarContacto(contacto);
            }
        }
        archivo.close();
    }
}