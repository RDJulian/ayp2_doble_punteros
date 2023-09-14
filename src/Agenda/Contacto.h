#ifndef ALGO2_DOBLE_PUNTEROS_CONTACTO_H
#define ALGO2_DOBLE_PUNTEROS_CONTACTO_H

#include <string>
#include <fstream>

class Contacto {
private:
    unsigned int numero;
    std::string nombre;
    std::string apellido;
public:
    Contacto(unsigned int numero, std::string nombre, std::string apellido);

    unsigned int getNumero();

    void guardarContacto(std::ofstream& archivo);

    void mostrarInformacion();

    void mostrarDirecciones();
};

#endif