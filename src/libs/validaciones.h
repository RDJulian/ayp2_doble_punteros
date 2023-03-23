#ifndef ALGO2_PRACTICA1_INTRODUCCION_VALIDACIONES_H
#define ALGO2_PRACTICA1_INTRODUCCION_VALIDACIONES_H

#include <string>
#include <vector>

//pre: -
//post: Devuelve true si la entrada es un entero, false de lo contrario.
bool esEntero(const std::string& numero);

//pre: -
//post: Devuelve true si la informacion es correcta (tres elementos, el numero es entero y tiene 8 digitos).
bool esInformacionValida(std::vector<std::string> informacion);

#endif