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

bool esInformacionValida(vector<string> informacion) {
    return (informacion.size() == CAMPOS && esEntero(informacion[NUMERO]) &&
            informacion[NUMERO].length() == DIGITOS_NUMERO);
}