#ifndef PARSER_H
#define PARSER_H

#include "constantes.h"
#include "../agenda.h"

//pre: El archivo indicado debe existir.
//post: Procesa el archivo correspondiente a la ruta ingresada y guarda la informacion en la agenda.
void procesarArchivo(Agenda* agenda, const std::string& ruta_archivo);

#endif