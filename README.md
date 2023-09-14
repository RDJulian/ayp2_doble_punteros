# Doble Punteros

Ejemplos de como utilizar doble punteros en C++. Clase de AyP2 2c2023 (14/9).

## Ejercicios para pensar y resolver en clase:

1. Se tiene un archivo agenda.csv con el siguiente formato:

   > NUMERO,NOMBRE,APELLIDO

   Para que un Contacto sea válido, NUMERO debe ser un entero de 8 dígitos. Sin embargo, un Contacto válido no puede ser
   agregado a la Agenda si ya existe otro contacto con el mismo número.<br>
   La Agenda tendra un tamaño fijo, pero que no sera definido hasta la ejecución del programa: el usuario de la clase
   pasará este tamaño cuando se instancie la Agenda.<br>
   Escribir un programa que instancie la Agenda, procese este archivo, cargue contactos a la agenda, y además permita
   mediante un menú:
    <ol>
    <li> Dar de alta un Contacto, con las consideraciones anteriores.</li>
    <li> Mostrar por pantalla todos los contactos, mostrando:

   > NUMERO - APELLIDO, NOMBRE

    </li>
    <li> Mostrar por pantalla, para cada Contacto:

   > DIR_PUNTERO - DIR_CONTACTO - DIR_NUMERO

    </li>
    </ol>

   Además, todas las instancias de Contacto deberán ser inicializadas en memoria dinámica, y su manejo debe ser mediante
   punteros.<br>
   Al cerrar el programa, se debe guardar el archivo con la información actualizada.

2. Escribir un simple programa que dados dos valores FILA y COLUMNA, **ingresados en tiempo de ejecución**, genere una
   Matriz de tamaño FILA x COLUMNA, inicializada como Matriz nula en memoria dinámica. Manejar la estructura con un
   doble puntero.<br>
   Luego, mostrar por pantalla la Matriz nula, asignar algunos valores a índices válidos, volver a mostrar, finalmente
   liberar la memoria y terminar el programa.