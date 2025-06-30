# Ejercicios de repaso de C

Gonzalo F. Perez Paina

### Contenido
 - [Matemática](#matematica)
 - [Tipos de datos y bases numericas](#tipodatos)
 - [Cadenas y caracteres](#cadenas)
 - [Uniones](#uniones)

## Ejercicicios

<a name="matematica">

### Matemática
 1. Escribir un programa que calcule el promedio de $N$ números enteros.
     * Solicitar al usuario la cantidad de números a promediar ($N$).
     * Solicitar al usuario los $N$ valores enteros.
     * Calcular el promedio.
     * Imprimir el resultado del promedio.

     La interacción con el usuario a través de la entrada y salida estándar debe ser como se muestra a continuación:
     ```
     ./promedio1
     Ingrese la cantidad de números a promediar: 4
     Ingrese el entero 1: 12
     Ingrese el entero 2: 23
     Ingrese el entero 3: 32
     Ingrese el entero 4: 11
     El promedio es: 19.500000
     ```

 1. Modificar el programa anterior para que el programa no le solicite al usuario la cantidad de números a promediar, en su lugar el programa solicita los números enteros hasta ingresar el valor 0 (cero).

 1. Escribir una función que calcule el promedio de $N$ números enteros en base al siguiente prototipo
     ```c
     double promedio(int * , int );
     ```

     junto al programa que evalúe su correcto funcionamiento.

 1. La función _factorial_ ($n!$) de un entero positivo se define como el producto de los enteros de 1 hasta $n$, por ejemplo: $3!=6$, $4!=24$. Escribir un programa que calcule los factoriales de los números desde el 1 hasta el 10 e imprima los resultados. A continuación se muestra la salida del programa:
     ```
     ./factorial
     1! = 1
     2! = 2
     3! = 6
     4! = 24
     5! = 120
     6! = 720
     7! = 5040
     8! = 40320
     9! = 362880
     10! = 3628800
     ```

 1. Escribir un programa que muestre en pantalla el valor que deben tomar los índices $(i, j)$ para acceder a los elementos de una matriz (arreglo bidimencional) de $N$ filas y $M$ columnas, o sea $\{(i, j) / i=0,\dots,N-1, j=0,\cdots,M-1\}$.
 El tamaño del arreglo se define mediante constantes simbólicas `#define` dentro del programa: `N` para la cantidad de filas y `M` para la cantidad de columnas.

     La salida en pantalla del programa debe ser como se muetra a continuación (para `N=2` y `M=3`). Probar el programa con diferentes valores de `N` y `M`.
     ```
     ./matrixidx1
     i = 0   j = 0
     i = 0   j = 1
     i = 0   j = 2
     i = 1   j = 0
     i = 1   j = 1
     i = 1   j = 2
     ```

 1. Modificar el programa anterior para que la salida sea 
     ```
     (0, 0) (0, 1) (0, 2)
     (1, 0) (1, 1) (1, 2)
     ```

 1. Escribir un programa que calcule las raíces de un polinomio de segundo orden ($ax^2 + bx + c$). El programa debe solicitarle al usuario los valores $a$, $b$ y $c$ y mostrar las soluciones para los tres casos: _i)_ raíces reales distintas, _ii)_ raíces igualesy _iii)_ raíces complejas conjugadas . La interacción con el usuario a través de la entrada y salida estándar debe ser como se muestra a continuación:
     ```
     ./roots 
     Ingrese los coeficientes (a, b, c) separados por espacio: 1 5 6
     Solución: raíces reales distintas (RRD)
     -2.000
     -3.000
     
     ./roots
     Ingrese los coeficientes (a, b, c) separados por espacio: 1 2 1
     Solución: raíces iguales (RI)
     -1.000
     
     ./roots
     Ingrese los coeficientes (a, b, c) separados por espacio: 1 0 1
     Solución: complejos conjugados (RCC)
     -0.000 + 1.000 i
     -0.000 - 1.000 i
     ```

 1. Escribir una función que calcule la distancia entre dos puntos, $p_1=(x_1,y_2)$ y $p_2=(x_2,y_2)$. A continuación se muestra el código fuente del programa al cual hay que agregar la función que realiza el cálculo.
     ```c
     #include <stdio.h>
     #include <math.h> // funciones pow y sqrt
     
     /* Prototipo de la función */
     
     int main(void)
     {
       printf("La distancia entre (%g,%g) y (%g,%g) es %g\n", 
           1.0, 2.0, 3.0, 4.0, distancia(1.0, 2.0, 3.0, 4.0));
       printf("La distancia entre (%g,%g) y (%g,%g) es %g\n", 
           2.0, 3.0, 3.0, 2.0, distancia(2.0, 3.0, 3.0, 2.0));
       printf("La distancia entre (%g,%g) y (%g,%g) es %g\n", 
           -1.0, -1.0, 2.0, 2.0, distancia(-1.0, -1.0, 2.0, 2.0));
       return 0;
     }
     
     /* Implementación de la función */
     ```

 1. Escribir un programa con la misma funcionalidad que el enunciado en el ejercicio 8 donde los puntos $p_1$ y $p_2$ se almacenen como arreglos unidimensionales (vectores) de dimensión 2.

 1. Escribir un programa con la misma funcionalidad que el enunciado en el ejercicio 8 donde los puntos $p_1$ y $p_2$ se almacenen como estructuras (\texttt{struct}) con los campos $x$ e $y$.

 1. Escribir un programa que calcule el producto escalar (punto) y vectorial (cruz) de dos vectores enteros de dimensión 3. La interacción con el usuario a través de la entrada y salida estándar debe ser como se muestra a continuación:
     ```
     ./vproduct
     Producto escalar y vectorial de vectores de dimensión: 3
     Ingrese los elementos del primer vector: 1 2 3
     Ingrese los elementos del segundo vector: 4 5 6
     Producto punto: 32
     Producto vectorial: -3 6 -3
     ```

 1. Escribir un programa que solicite al usuario de forma continuada dos valores enteros (`num` y `den`) e imprima el cociente entre ellos (`num/den`) como valor de punto floatnte (`float`). Además:
     * El programa debe finalizar cuando `den=0`.
     * El valor de salida se debe mostrar con 10 dígitos decimales. 

     Analizar el resultado al ingresar diferentes valores enteros. ¿Qué valores se obtienen al realizar el cociente `1/3`, `1/5` y `1/9` y qué valores se deberían obtener?

 1. Escribir los programas necesarios para verificar las funciones `pow()`, `sqrt()`, `exp()`, `log()`, `log10()`, `ceil()` y `floor()` de la biblioteca matemática (archivo de cabecera `math.h`). (Ver cap.5 D\&D 4ºEd.)

</a>
<a name="tipodatos">

### Tipos de datos y bases numéricas

 1. Escribir un programa que muestre en pantalla la cantidad de bytes que ocupan en memoria las variables de los diferentes tipos de datos disponibles en C, utilizando para ello el operador `sizeof`. Los tipos de datos son: `char` e `int` en su versión `signed`/`unsigned` para ambos y `short`/`long` para `int`; además de `float` y `double`.

 1. Escribir un programa que imprima el valor entero ingresado por teclado (en el rango de 0 a 255) en formato decimal, hexadecimal y binario. El programa debe tener la interacción con el usuario que se muestra a continuación:
     ```
     Ingrese un entero entre 0 y 255 (-1 para salir): 2
        002 d = 0x02 = 0000 0010 b
     Ingrese un entero entre 0 y 255 (-1 para salir): 4
        004 d = 0x04 = 0000 0100 b
     Ingrese un entero entre 0 y 255 (-1 para salir): -1
     ```

 1. Escribir un programa que trabaje con un tipo de dato adecuado para almacenar los parámetros de un círculo, a saber: coordenadas del punto central en un sistema cartesiano y radio, utilizando para ello estructuras (`struct`). El programa tiene que:
     * Declarar un tipo de dato `punto` con una estructura.
     * Declarar un tipo de datos `circulo` que incluya un miembro de tipo `punto` para almacenar el centro del círculo, y un miembro tipo `double` para almacenar el radio del círculo.

      La interacción con el usuario a través de la entrada y salida estándar debe ser como se muestra a continuación:
     ```
     Ingrese las coordenadas del círculo (x, y): 1.2 2.3
     Ingrese el radio del círculo: 2.5
     
     El círculo ingresado es:
       centro: (1.2, 2.3)
       radio: 2.5
     ```

 1. Agregar al programa del ejercicio anterior el cálculo de la distancia del centro del círculo al origen del sistema de coordendas y del área del círculo. Para ello, implementar las funciones cuyos prototipos son:
     ```c
     double dist_origen(struct circulo );
     double area_circ(struct circulo );
     ```

     Indicar si los parámetros de las funciones son pasados por valor o por referencia.<br>
     (Nota: para el cálculo del área utilizar la constante simbólica `M_PI` definida en el archivo de cabecera `math.h`).
    
 1. Escribir un programa que solicite al usuario de forma continuada ingresar dos valores en punto floante (`float`) e imprima la suma con 10 dígitos decimales. El programa debe finalizar cuando alguno de los valores ingresados es cero. ¿Qué valores se obtiene al realizar la suma `0.1 + 0.2`, `0.2 + 0.7` y `0.13 + 0.13` y por qué?

 1. El archivo de cabecera `limits.h` define constantes simbólicas con los valores máximos y mínimos para los diferentes tipos de datos de C. Escribir un programa que muestre en pantalla el valor de las siguientes constantes simbólicas de dicho archivo: `CHAR_BIT`, `CHAR_MIN`, `CHAR_MAX`, `SCHAR_MIN`, `SCHAR_MAX`, `UCHAR_MAX`, `SHRT_MIN`, `SHRT_MAX`, `USHRT_MAX`, `INT_MIN`, `INT_MAX`, `UINT_MAX`, `LONG_MIN`, `LONG_MAX`, `ULONG_MAX`, `LLONG_MIN`, `LLONG_MAX`, `ULLONG_MAX`. Además:
     * Investigue qué representa cada valor.
     * Comprobar los valores obtenidos a partir de la cantidad de bytes que ocupan en memoria los diferentes tipos de datos (ver ejercicio donde se utiliza el operador `sizeof`).

</a>
<a name="cadenas">

### Cadenas y caracteres
 1. Transcribir el siguiente código fuente, construir el programa y ejecutarlo. ¿Cuántos bytes ocupa en memoria el arreglo bidimensional de nombre `dato`?
     ```c
     #include <stdio.h>
     
     #define N 5
     #define M 8
     
     char dato[N][M] = {  {76, 117, 110, 101, 115, 0},
                          {77, 97,  114, 116, 101, 115, 0},
                          {77, 105, 101, 114, 108, 101, 115, 0},
                          {74, 117, 101, 118, 101, 115, 0}, 
                          {86, 105, 101, 114, 110, 101, 115, 0} };
     
     int main(void)
     {
       int i, j;
       for(i = 0; i < N; i++)
       {
         for(j = 0; j < M; j++)
           printf("%c", dato[i][j]);
         printf("\n");
       }
     
       return 0;
     }
     ```

 1. Reemplazar la función `main` del código fuente del ejercicio anterior por el código mostrado a continuación, construir y ejecutar el programa. ¿Qué diferencia encuentra en el resultado de ambos programas?. Justificar la respuesta.
     ```c
     int main(void)
     {
       int i;
       for(i = 0; i < 5; i++)
         printf("%s\n", dato[i]);
     
       return 0;
     }
     ```

 1. Transcribir la definición de la variable `dato` del código fuente del ejercicio 1 en un archivo de texto plano y guardar con el nombre `dias.h`. Luego, realizar las siguientes modificaciones a los programas de los ejercicios 1 y 2:
     * borrar la definición de la variable `dato`
     * agregar la línea `#include "dias.h"`

     Construir y ejecutar estos programas. ¿Qué puede decir de los archivos de cabecera `.h`?

 1. Escribir un programa para obtener el resultado del ejercicio 1 donde los días de la semana se almacenen en un arreglo de punteros tipo `char`. ¿Cuántos bytes se necesitan para almacenar los nombres de los días de la semana?. Compare el resultado con el del ejercicio 1.

 1. Escribir un programa para evaluar las funciones de manejo de caracteres (archivo de cabecera `ctype.h`). Las funciones a evaluar son: `isdigit`, `isalpha`, `isalnum`, `isxdigit`, `islower` y `isupper`. El programa debe solicitarle al usuario que ingrese un caracter de forma continuada hasta precionar Ctrl-C (combinación de teclas Ctrl y C). La interacción con el usuario debe ser como se muestra a continuación:
     ```
     > ./ctype1 
     Ingrese un caracter (Ctrl-C para terminar): a
     isdigit  : NO
     isalpha  : SI
     isalnum  : SI
     isxdigit : SI
     islower  : SI
     isupper  : NO
     Ingrese un caracter (Ctrl-C para terminar): 0
     isdigit  : SI
     isalpha  : NO
     isalnum  : SI
     isxdigit : SI
     islower  : NO
     isupper  : NO
     Ingrese un caracter (Ctrl-C para terminar): ^C
     ```

1. Escribir un programa que le solicite al usuario ingresar una cadena, la cual puede contener espacios, y muestre los valores numéricos de los caracteres que la componen (ASCII) en formato decima y hexadecimal. La salida del programa debe ser como se muestra a continuación:
     ```
     > ./cad2ascii
     Ingrese una cadena (max. 20 caracteres): Hola Info2 :)
     'H' 	 72 	 0x48
     'o' 	 111 	 0x6F
     'l' 	 108 	 0x6C
     'a' 	 97 	 0x61
     ' ' 	 32 	 0x20
     'I' 	 73 	 0x49
     'n' 	 110 	 0x6E
     'f' 	 102 	 0x66
     'o' 	 111 	 0x6F
     '2' 	 50 	 0x32
     ' ' 	 32 	 0x20
     ':' 	 58 	 0x3A
     ')' 	 41 	 0x29
     ```

1. Escribir un programa que imprima mediante un bucle `for` las cadenas pasadas a la función `main` y la cantidad de caracteres (longitud) de cada cadena. A continuación se muestra un ejemplo de la ejecución del programa.
     ```
     > ./mainargs a Hola 123 3.14
     argv[0]: ./mainargs (10)
     argv[1]: a (1)
     argv[2]: Hola (4)
     argv[3]: 123 (3)
     argv[4]: 3.14 (4)
     ```

 1. Modificar el programa del ejercicio 5 para que el programa reciba por línea de comandos el caracter a evaluar, por ejemplo:
     ```
     > ./ctype2 a}
     ```
     
     Además, el programa debe verificar que se recibe un único caracter y en caso contrario indicar error.

 1. El programa mostrado a continuación convierte la hora ingresada como cadena con el formato `HH:MM` a los correspondientes valores enteros para la hora y los minutos. Usando las funciones de la biblioteca estándar, completar el código fuente donde lo indica el comentario. Esto puede realizarse con solo 3 líneas de código. (Nota: suponer que el usuario del programa ingresa la hora siempre en el formato solicitado.)
     ```c
     #include <stdio.h>                            
     #include <stdlib.h>                           
                                                   
     int main(void)                                
     {                                             
         char cadena[6];                             
         unsigned char hora, min;                    
                                                   
         printf("Ingrese la hora en format 'HH:MM': ");
         scanf("%s", cadena);                        
                                                   
         /*
          * Completar aquí
          */
                                                   
         printf("Horas: %d\n", hora);                
         printf("Minutos: %d\n", min);               
         return 0;                                   
     }
     ```

 1. Escribir un programa que realice la suma de dos enteros pasados desde la línea de comandos y tenga la salida como se muestra a continuación:
     ```
     > ./suma 10 12
     10 + 12 = 22
     > ./suma 
     ERROR. Debe ejecutarse:
       ./suma <entero1> <entero2>
     ```

 1. Escribir un programa que reciba dos cadenas por línea de comandos y compare las cadenas utilizando la función `strcmp`, e indicar si la primer cadena es menor, igual o mayor que la segunda.

 1. Escribir un programa que convierta a mayúscuas las cadenas pasadas por línea de comandos
     ```
     > ./toupper hola 123
     ./TOUPPER
     HOLA
     123
     ```

 1. Escribir el cuerpo de la función `float2str` del siguiente programa:

     ```c
     #include <stdio.h>
     #include <stdlib.h>
     #include <math.h>
     
     #define LONGITUD 10
     
     void float2str(float , char * );
     
     int main(void)
     {
         float val;
         char cad[LONGITUD];
     
         val = 3.14;
         float2str(val, cad);
         printf("%s\n", cad);
     
         val = 1.75;
         float2str(val, cad);
         printf("%s\n", cad);
     
         return 0;
     }
     
     void float2str(float val, char *cad)
     {
         /* Completar */
     }
     ```

     La función `float2str` convierte la variable de punto flotante (`float`) `val` a una cadena de caracteres `cad`. El valor a convertir es siempre positivo de `0.00` hasta `9.99`. La implementación de la función no debe hacer uso de las funciones de biblioteca de caracteres y cadenas.

 1. Ampliar la función `float2str()` para que reciba como último argumento la cantidad de cifras decimales que se quieren obtener de la conversión. A continuación se muestra el código fuente del programa de prueba 
     ```c
     #include <stdio.h>
     #include <stdlib.h>
     #include <math.h>
     
     #define LONGITUD 10
     
     void float2str(float , char * , int );
     
     int main(void)
     {
         float val = M_PI;
         char cad[LONGITUD];
     
         float2str(val, cad, 2);
         printf("%s\n", cad);
         float2str(val, cad, 4);
         printf("%s\n", cad);
         float2str(val, cad, 6);
         printf("%s\n", cad);
     
         return 0;
     }
     
     void float2str(float val, char *cad, int ndec)
     {
         /* Completar */
     }
     ```

     donde la salida de del programa es:
     ```
     > ./float2str2 
     3.14
     3.1415
     3.141592
     ```
</a>
<a name="uniones">

### Uniones

 1. Escribir un programa que imprima en pantalla la cantidad de bytes que ocupa en memoria una unión (`union`) de una variable `int` y una `float.` El programa debe declarar la unión e imprimir su tamaño sin definir una variable de dicha unión.

 1. Escribir un programa que imprima en pantalla la cantidad de bytes que ocupa en memoria una unión de una variable `int` y un arreglo de dos elementos `unsigned char`. El programa debe declarar la unión e imprimir su tamaño sin definir una variable de dicha unión.

 1. Escribir un programa que declare una unión de una variable `int` y `float`, utilizando un `typedef` para definir el nuevo tipo `int_float_t`. El programa debe solicitarle al usuario ingresar un valor entero y guardar el valor en el campo correspondiente de la unión e imprimir ambos campos. Luego debe soliciarle al usuario ingresar un valor real y guardar el valor en el campo correspondiente y volver a imprimir la unión. Implementar una función que imprima ambos campos de la unión. Una salida posible de la ejecución del programa es:
 
     ```
     > ./int_float
     Ingrese un entero: 1234
     - El miembro INT de la union es: 1234
     - El miembro FLOAT de la union es: 0.000000
     Ingrese un real: 3.14
     - El miembro INT de la union es: 1078523331
     - El miembro FLOAT de la union es: 3.140000
    ```

 1. Escribir un programa que declare las siguientes uniones:
     * Un entero sin signo (`unsigned int`) y un vector de 4 elementos `unsigned char`.
     * Un entero sin signo y una estructura de nombre `bytes` compuesta de 4 `unsigned char` (byte0 a byte3).
     * Tres campos de las uniones anteriores (entero, vector y estructura).

     El programa debe solicitarle al usuario ingresar un entero e imprimir todos los campos de cada unión.

 1. Completar el programa que se muetra a continuación el cual imprime los bytes que forman una variable entera en formato decimal y hexadecimal. 
     ```c
     #include <stdio.h>
     
     typedef union {
         int entero;
         unsigned char uvec[4];
     } int_uvec_t;

     int main(void)
     {
         int i;
         int_uvec_t u = { 123456 };

         /* Completar */

         return 0
     }
     ```

     A continuación se muestra la salida que debe tener el programa.
     ```
     > ./int2bytes
     Los bytes que conforman el entero 123456 son:
     Decimal (MSB-LSB): 0 1 226 64
     Hexadecimal (MSB-LSB): 0x00 0x01 0xE2 0x40
     ```
     Como se observa, los bytes se imprimen de izquierda a derecha el byte más significativo (MSB: Most Significant Byte) al menos significativo (LSB: Least Significant Byte).

 1. Ídem al ejercicio anterior. El programa a completar es: 
     ```c
     #include <stdio.h>
     #include <math.h>
     
     typedef union {
         float entero;
         unsigned char uvec[4];
     } float_uvec_t;

     int main(void)
     {
         int i;
         float_uvec_t u = { M_PI };

         /* Completar */

         return 0
     }
     ```
     y su salida:
     ```
     > ./float2bytes
     Los bytes que conforman el 'real' 3.141593 son:
     Decimal (MSB-LSB): 64 73 15 219
     Hexadecimal (MSB-LSB): 0x40 0x49 0x0F 0xDB
     ```

</a>
