# Doble Punteros

Ejemplos de como utilizar doble punteros en C++. Clase de AyP2 1c2023 (23/3).

## Ejercicios para pensar:

1. Se tiene un archivo agenda.txt con el siguiente formato:
   > NUMERO,NOMBRE,APELLIDO

   Para que un contacto sea válido, NUMERO debe ser un entero de 8 dígitos. Sin embargo, un contacto válido no puede ser
   agregado a la agenda si ya existe otro contacto con el mismo número.<br>
   Además, todas las estructuras deberán ser inicializadas en memoria dinámica, y su manejo debe ser mediante
   punteros.<br><br>
   Escribir un programa que procese este archivo, cargue los contactos a la agenda, y además permita mediante un menú:
    <ol>
    <li> Dar de alta un contacto, con las consideraciones anteriores.</li>
    <li> Mostrar por pantalla todos los contactos, mostrando:

   > NUMERO - APELLIDO, NOMBRE

    </li>
    <li> Mostrar por pantalla, para cada contacto:

   > DIR_PUNTERO - DIR_CONTACTO - DIR_NUMERO - NUMERO

    </li>
    </ol>

   NOTA: En el repositorio hay una "plantilla" para completar durante la clase. Solamente es necesario implementar
   algunas funciones. Los archivos en **src/libs** ya están completos. Sin embargo, se recomienda resolver TODO el
   ejercicio de cero.<br>

2. Escribir un simple programa que dados dos valores FILA y COLUMNA, **ingresados en tiempo de ejecución**, genere una
   matriz de tamaño FILA x COLUMNA, inicializada como matriz nula en memoria dinámica. Manejar la estructura con un
   doble puntero.<br>
   Luego, mostrar por pantalla la matriz nula, asignar algunos valores a índices válidos, volver a mostrar, finalmente
   liberar la memoria y terminar el programa.