#include "validaciones.h"
#include "constantes.h"
#include <algorithm>

using namespace std;

bool esEntero(const string& numero) {
    if (all_of(numero.begin(), numero.end(), [](char digito) { return isdigit(digito); })) {
        return true;
    } else {
        return false;
    }
}

bool esNumeroValido(const string& entrada) {
    return (esEntero(entrada) && entrada.length() == DIGITOS_NUMERO);
}

bool esInformacionValida(const vector<string>& informacion) {
    return (informacion.size() == CAMPOS && esNumeroValido(informacion[NUMERO]));
}