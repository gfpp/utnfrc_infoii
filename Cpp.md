# Ejercicios de repaso de C

Gonzalo F. Perez Paina


## Ejercicicios
1. Escribir un programa _"Hola mundo"_ en lenguaje C++ (utilizar `cout` definido en el archivo de cabecera `iostream`).

1. Escribir un programa que solicite al usuario un valor `int`, uno `float` y uno `double` y luego los imprima en pantalla (utilizar `cout` y `cin`).

1. Escribir un programa que realice una división entera utilizando una función con paso de parámetros por referencia:
    1. El programa debe solicitarle al usuario el valor del dividendo y del divisor.
    1. Si el divisor es 0 debe mostrar un mensaje de error y salir.
    1. La división la debe realizar una función cuyo prototipo sea:
        ```cpp
        int divisionEntera(int &a, int &b, int &res);
        ```
        la cual devuelve -1 si el divisor es 0, o 0 en caso contrario. La interacción del programa con el usuario debe ser la que se muestra a continuación:
        ```
        > ./a.out
        Ingrese el dividendo (entero): 10 
        Ingrese el divisor (entero): 2
        10 / 2 = 5
        > ./a.out
        Ingrese el dividendo (entero): 10 
        Ingrese el divisor (entero): 0
        ERROR: división por cero
        ```
    Nota: en este caso la función no devuelve el valor de la operación sino que el valor de retorno se utiliza para indicar si la operación se realizó con éxito o no.

1. Escribir funciones sobrecargadas para realizar la resta entre valores enteros y de punto flotante, y un programa que verifique su funcionamiento.

1. Escribir el archivo fuente `hora1.cpp` donde se implemente la clase de C++ cuya definición se encuentra en el archivo `hora1.h` mostrado a continuación:
    ```cpp
    #ifndef HORA1_H
    #define HORA1_H
    
    class Hora {
      public:
        Hora(); // Constructor
        void establecer(int , int , int );
        void imprimir(); // Formato: 13:15:00
    
      private:
        int hora;    // 0 - 23
        int minuto;  // 0 - 59
        int segundo; // 0 - 59
    };
    ```
    El comportamiento de la clase es el siguiente:
    1. El constructor debe inicializar los datos miembros de la clase a cero.
    1. La función miembro `establecer()` permite fijar el valor de la hora ($h$, $m$ y $s$) luego de verificar que los valores pasados como argumentos sean correctos ($0 \leq h < 24$; y $0 \leq m,s < 59$).
    1. La función miembro `imprimir()` debe imprimir la hora en el formato de 24hs (p.e.: 01:10:22 o  23:59:59).

    A continuación se muestra el código fuente del programa para evaluar la clase `Hora` implementada:
    ```cpp
    #include <iostream>
    #include "hora1.h"
    
    using namespace std;
    
    int main()
    {
      Hora h;     // Instancia el objeto h de la clase Hora
    
      cout << "La hora por defecto es: ";
      h.imprimir();
        
      h.establecer(13, 27, 6);
      cout << "\nLa hora después de estableceres: ";
      h.imprimir();
    
      // Intenta establecer un valor inválido de Hora
      h.establecer(99, 99, 99);    
      cout << "\nDespués de intentar establecer un valor inválido: ";
      h.imprimir();
      cout << endl;

      return 0;
    }
    ```
    Nota: recordar que para compilar ambos archivos fuentes se debe utilizar:
    ```
    > g++ hora1.cpp ejr05.cpp
    ```

1. Modificar la implementación de la clase `Hora` del ejercicio anterior de forma tal que internamente la hora este almacenada como la cantidad de segundos desde la medianoche. La interfaz de la clase debe ser la misma. Para ello:
    1. Codificar los archivos `hora2.h` y `hora2.cpp` con la nueva implementación.
    1. Probar la clase utilizando el mismo código fuente de prueba que el ejercicio anterior.

1. Modificar la implementación de la clase `Hora` del 5 (guardar como `hora3.h` y `hora3.cpp`) donde se incluyan también funciones miembros `set` y `get`. Los prototipos de las funciones se muestran a continuación:
    ```cpp
    void establecerHora(int );  // Para fijar solo el campo 'hora'
    void establecerMinuto(int ); // Para fijar solo el campo 'minuto'
    void establecerSegundo(int ); // Para fijar solo el campo 'segundo'
    int obtenerHora();
    int obtenerMinuto();
    int obtenerSegundo();
    ```

1. Agregar el calificador `const` a las funciones miembros de la clase `Hora` del ejercicio anterior según corresponda.

1. Modificar la clase `Hora` del ejercicio anterior para que las funciones miembros puedan ser llamadas en cascada como se muestra en el Listado~\ref{lst:cascada} (utilizar el puntero `this`). 
    ```cpp
    Hora h;
    h.establecerHora(17,30,0).imprimir();
    h.establecerHora(17).establecerMinuto(30).establecerSegundo(0);
    ```
    Escribir un programa de prueba para verificar el correcto funcionamiento.

1. Escribir una clase `Complejo` (nombres de archivos `complejo1.h` y `complejo1.cpp`) que permita realizar aritmética básica con números complejos, junto a un programa que verifique el correcto funcionamiento. Nota: los números complejos son de la forma $a + ib$, donde $i=\sqrt{-1}$.
    1. Utilizar variables `double` para los datos miembros (`private`) de la clase.
    1. Codificar un constructor que permita inicializar un objeto de la clase, el cual debe tener valores predeterminados si no se proporcionan argumentos.
    1. Codifique funciones miembro `public` para: _i)_ sumar dos números complejos, _ii)_ restar dos números complejos e _iii)_ imprimir un número complejo de la forma (`parteReal, parteImaginaria`). P.e.: el complejo $2+3i$ se imprime `(2, 3)`.

1. Escribir un programa que, utilizando la clase `Complejo` del ejercicio anterior, defina e inicialice dos números complejos, los sume y reste, y muestre los resultados.

1. Agregarle a la implementación de la clase `Complejo` del ejercicio 10 funciones `get` para obtener la parte real y la parte imaginaria (nombres de archivos `complejo2.h` y `complejo2.cpp`).

1. Modificar el programa del ejercicio 11 para que las operaciones de suma y resta de los números complejos sean realizadas por sendas funciones definidas en la propia aplicación. Estas funciones deben ser funciones al estilo de C, o sea, funciones no miembros de la clase. En su implementación, estas funciones deben utilizar las funciones miembros `get` de la clase para obtener el valor de complejo.

1. Escribir un programa que asigne y libere memoria dinámica utilizando los operadores `new` y `delete` de C++. El programa debe:
    1. reservar memoria para almacenar un valor entero y uno en punto flotante, y asignarle valores,
    1. reservar memoria para un arreglo unidimensional de enteros e inicializarlos a cero,
    1. imprimir cada una de las variables antes generadas y
    1. liberar la memoria reservada.

1. Modificar la clase `Complejo` del ejercicio 10 para que las operaciones aritméticas se realicen mediante sobrecarga de operadores. Sobrecargar los operadores `+`, `-`, `+=` y `-=` (nombres de archivos `complejo3.h` y `complejo3.cpp`).

1. Modificar la clase `Complejo` del ejercicio 15 para sobrecargar los operadores de inserción y extracción de flujo (`<<` y `>>`). Para el ingreso de un número complejo por le entrada estándar se deben ingresar la parte real e imaginaria separada por un espacio (nombres de archivos `complejo4.h` y `complejo4.cpp`). A continuación se muestra el código fuente del programa para evaluar la clase implementada. 
    ```cpp
    #include <iostream>
    #include "complejo4.h"
    using namespace std;
    
    int main()
    {
      cout << "Ingrese un nro complejo (c1): ";
      Complejo c1;
      cin >> c1;
    
      cout << "Ingrese un nro complejo (c2): ";
      Complejo c2;
      cin >> c2;
      cout << endl;
    
      cout << "Luego de 'resul = c1 + c2'" << endl;
      Complejo resul;
      resul = c1 + c2;
      cout << "c1 = " << c1 << endl << "c2 = " << c2 << endl
        << "resul = " << resul << endl << endl;
    
      cout << "Luego de 'resul = c1 - c2'" << endl;
      resul = c1 - c2;
      cout << "c1 = " << c1 << endl << "c2 = " << c2 << endl
        << "resul = " << resul << endl << endl;
    
      cout << "Luego de 'c2 += c1'" << endl;
      c2 += c1;
      cout << "c1 = " << c1 << endl << "c2 = " << c2 << endl
        << "resul = " << resul << endl << endl;
    
      return 0;
    }
    ```

1. Agregarle a la clase `Complejo` del ejercicio 16 los operadores de igualdad `==` y desigualdad `!=`, y el constructor de copia (nombres de archivos `complejo5.h` y `complejo5.cpp`).

1. A partir de la declaración de la clase `Cadena` en el archivo `cadena.h` y del programa mostrados a continuación, codificar el archivo `cadena.cpp` donde se implementen las funciones miembros de la clase. Utilizar asignación dinámica de memoria (con `new` y `delete`) para reservar espacio para almacenar la cadena.
    ```cpp
    #ifndef CADENA_H
    #define CADENA_H
    
    class Cadena {
      public:
        Cadena(int = 20); // Constructor
        ~Cadena();        // Destructor
    
        void establecer(const char * );
        void imprimir() const;
    
      private:
        const int longitud;
        char *cad;
    };
    #endif
    ```
    ```cpp
    #include <iostream>
    #include <cstring>
    #include "cadena.h"

    int main() {
      Cadena cad1;
      cad1.establecer("Hola");
      cad1.imprimir();
    
      Cadena cad2(27);
      cad2.establecer(
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
      cad2.imprimir();
    
      return 0;
    }
    ```

1. Escribir una clase `Cadena` (nombre de archivos `cadena2.h` y `cadena2.cpp`) similar a la del ejercicio anterior en la cual la asignación y la impresión por pantalla de la cadena se realice mediante sobrecarga de operadores.
A continuación se muestra el código fuente para evaluar la implementación de la clase.
    ```cpp
    #include <iostream>
    #include "cadena2.h"
    
    using namespace std;
    
    int main()
    {
      Cadena cad1;
      cad1 << "Prueba1";
      cout << cad1 << endl;
    
      Cadena cad2(8);
      cad2 << "Prueba2";
      cout << cad2 << endl;
    
      cad2 << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      cout << cad2 << endl;
    
      return 0;
    }
    ```

## Resolución

### Ejercicio 1
A continuación se muestran dos ejemplos de código fuente para el programa _Hola mundo_ escritos en C++.
```cpp
#include <iostream>
using namespace std;

int main(void)
{
  cout << "Hola mundo" << endl;
  return 0;
}
```
```cpp
#include <iostream>

int main(void)
{
  std::cout << "Hola mundo" << std::endl;
  return 0;
}
```

La compilación del código fuente y el resultado de su ejecución se muestran a continuación:
```
> g++ hola_mundo.cpp
> ./a.out
Hola mundo
```

### Ejercicio 4
El código fuente de resolución del ejercicio es:
```cpp
#include <iostream>
using namespace std;

int resta(int , int );
float resta(float , float );

int main()
{
  int aEnt, bEnt;
  cout << "Ingrese dos enteros (separados por espacio): ";
  cin >> aEnt >> bEnt;
  cout << "La diferencia de (" << aEnt << " - " << bEnt
    << ") es igual a " << resta(aEnt, bEnt) << endl << endl;

  float aFloat, bFloat;
  cout << "Ingrese dos floats (separados por espacio): ";
  cin >> aFloat >> bFloat;
  cout << "La diferencia de (" << aFloat << " - " << bFloat
    << ") es igual a " << resta(aFloat, bFloat) << endl;
  return 0;
}

int resta(int a, int b)
{
  return (a-b);
}

float resta(float a, float b)
{
  return (a-b);
}
```
en el cual se definen dos funciones `resta()` sobrecargadas y el programa de prueba. Este programa le solicita al usuario dos valores enteros y muestra la resta y lo mismo para valores en punto flotante.
Construcción del programa y el resultado de su ejecución:
```
> g++ sobrecarga_resta.cpp 
> ./a.out 
Ingrese dos enteros (separados por espacio): 23 13
La diferencia de (23 - 13) es igual a 10

Ingrese dos floats (separados por espacio): 5.35 4.16
La diferencia de (5.35 - 4.16) es igual a 1.19
```

### Ejercicio 14
El código fuente de resolución del ejercicio es:
```cpp
#include <iostream>
using namespace std;

const unsigned char TAM = 20;

int main(void)
{
  int *intPtr = new int(10);
  float *floatPtr = new float(3.14);

  int *vec = new int [TAM];
  for(int i = 0; i < TAM; i++)
    vec[i] = 0;

  cout << "El valor int es: " << *intPtr << endl;
  cout << "El valor float es: " << *floatPtr << endl;
  cout << "El arreglo es: ";
  for(int i = 0; i < TAM; i++)
    cout << vec[i] << " ";
  cout << endl;

  delete intPtr;
  delete floatPtr;
  delete [] vec;
  return 0;
}
```
La construcción y ejecución es:
```
> g++ newdelete.cpp
> ./a.out
El valor int es: 10
El valor float es: 3.14
El arreglo es: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```
