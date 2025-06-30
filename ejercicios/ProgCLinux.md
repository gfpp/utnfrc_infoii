# Ejercicios de programación en C bajo GNU/Linux

Gonzalo F. Perez Paina

## Ejercicicios

 1. Escribir, construir y ejecutar un programa _"Hola mundo!"_ en GNU/Linux, para ello los pasos a seguir son:
     * Editar el archivo `hola.c` con gedit.
     * Abrir una terminal (p.e. `gnome-terminal`) e ir al directorio donde se encuentra el archivo fuente (comando `cd`).
     * Compilar el programa con `gcc` mediante el comando `gcc hola.c -o hola`.
     * Ejecutar mediante `./hola`.

 1. Escribir un programa que sume dos enteros solicitados al usuario y muestre el resultado en pantalla (nombre del código fuente: `suma1.c`). La interacción con el usuario a través de la entrada y salida estándar debe ser como se muestra a continuación:
     ```
     ./suma1 
     Ingrese el primer entero: 2
     Ingrese el segundo entero: 6
     La suma es: 8
     ```

 1. Escribir, construir y ejecutar el programa del código fuente que se muestra a continuación. ¿Qué diferencia tiene este programa con el del ejercicior?.
     ```c
     int main(void)
     {
         int a = 2, b = 3;
         int c = a + b;
     }
     ```

 1. Constuir el programa del ejercicio anterior con la siguiente línea de comando:
     ```
     gcc -Wall suma2.c
     ```
     ¿Qué resultado obtiene y por qué?

 1. Escribir, construir y ejecutar el programa del código fuente que se muestra a continuación. ¿Qué diferencia tiene este programa con el del ejercicio anterior?. ¿Dónde va a parar el resultado que devuelve la función `main`?. Investigue cómo obtener el valor retornado por el programa desde la terminal de Linux.
     ```c
     int main(void)
     {
         int a = 2, b = 3;
         return (a + b);
     }
     ```

 1. Notar que los programas de los ejercicios 3 y 5 no tienen la línea:
     ```c
     #include <stdio.h>
     ```
     ¿Podría explicar por qué se pueden construir y ejecutar sin esta línea?

 1. Construya el programa del siguiente código fuente:  
     ```c
     #include <stdio.h>
     
     int main(void)
     {
         printf("Hola mundo!\n");
         return 0;
     }
     ```

    con las siguientes líneas de comandos:
    * `gcc -Wall -std=c90 hola1.c`
    * `gcc -Wall -std=c99 hola1.c`
    * `gcc -Wall -std=c90 -Werror hola1.c`
    * `gcc -Wall -std=c99 -Werror hola1.c`

    ¿Qué errores o advertencias obtiene en cada caso?. Investigue que significado tiene `-Wall`, `-std=c9x` y `-Werror`.

 1. Ídem al ejercicio anterior con el siguiente programa:
     ```c
     #include <stdio.h>
     
     int main(void)
     {
         printf("Hola mundo!\n");
     }
     ```

 1. Dado el siguiente código fuente:
     ```c
     #include <stdio.h>
     #include <math.h>
     
     int main(void)
     {
         double x = 2.;
         printf("La raíz cuadrada de dos es: %g\n", sqrt(x));
         return 0;
     }
     ```

     Construya el programa con: `gcc -Wall sqrt.c` y responder:

     * ¿Qué errores y/o advertencias obtiene?. Investigue cuál es su significado y cómo corregirlo.
     * ¿Qué errores y/o advertencias obtiene si se elimina la línea `#include <math.h>`? ¿Qué significan esas advertencias y/o errores?

 1. Escribir y construir un programa similar al del ejercicio anterior eliminando la definición de la variable `x` y colocando el valor literal en la función `sqrt()` (o sea, `sqrt(2.)`). ¿Qué sucede al construir el programa con: `gcc -Wall sqrt1.c`?

 1. Configurar gedit para ser utilizado como IDE del lenguaje C.

     * Habilitar la numeración de líneas y el resaltado de sintaxis
     * Habilitar la terminal embebida

     Buscar información para cumplir la consigna.

 1. Descargar, configurar y probar algunos de los IDE mencionados en clase (por ejemplo: Geany y CodeLite). Para ello buscar información al respecto en internet.
