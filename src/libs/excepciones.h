#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <exception>

// NOTA: NO es necesario que declaren excepciones personalizadas, aunque hacerlo resultara en funciones con una mayor
// cobertura de los distintos casos. Ante la duda, opten por solamente validar las entradas.
// Al sobrecargar el metodo what(), se puede cambiar el mensaje que aparece en pantalla cuando se lanza la excepcion.

class ContactoNoValidoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: el contacto no tiene el formato correcto.";
    }
};

class ContactoRepetidoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: el contacto ya fue agregado a la agenda.";
    }
};

class ArchivoNoExistenteException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: el archivo no existe.";
    }
};

class TamanioInicialNoValidoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: se intento generar un vector con un tamaño no valido. Revisar este valor en constantes.h.";
    }
};

#endif
