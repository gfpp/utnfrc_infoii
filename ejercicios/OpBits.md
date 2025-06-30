# Ejercicios de operadores a nivel de bits

Gonzalo F. Perez Paina

<style>
td, th {
   border: none!important;
}
</style>

## Ejercicicios

1.  Realice las operaciones que se indican a continuación considerando que los operandos son números de 8 bits en notación decimal. Expresar el resultado en notación decimal, binaria y hexadecimal.

    <table>
    <tr>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>a)</i> 13 & 10 </td>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>e)</i> 1 ^ 6 </td>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>i)</i> 90 >> 1 </td>
    </tr>
    <tr>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>b)</i> 26 & 21 </td>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>f)</i> 1 ^ 27 </td>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>j)</i> 1 << 2 </td>
    </tr>
    <tr>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>c)</i> 14 | 13 </td>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>g)</i> 32 >> 4 </td>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>k)</i> 3 << 4 </td>
    </tr>
    <tr>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>d)</i> 33 | 5 </td>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>h)</i> 128 >> 3 </td>
      <td style="width: 200px; height: 50px; font-family: monospace"> <i>l)</i> 11 << 4 </td>
    </tr>
    </table>

1. Resolver las siguientes operaciones expresando el resultado en notación decimal, binaria y hexadecimal.

    <table>
    <tr>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>a)</i> 240 | (1 << 1) </td>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>e)</i> (1 << 0) | (1 << 2) </td>
    </tr>
    <tr>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>b)</i> 168 | (1 << 2) </td>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>f)</i> (1 << 2) | (1 << 4) </td>
    </tr>
    <tr>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>c)</i> 255 & ~(1 << 2) </td>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>g)</i> (1 << 2) | ~(1 << 5) </td>
    </tr>
    <tr>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>d)</i> 254 & ~(1 << 3) </td>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>h)</i> ~(1 << 1) | (1 << 3) </td>
    </tr>
    </table>

1. Si `num` es una variable tipo `unsigned char` cuyo bit menos significativo se designa como b<sub>0</sub> y el más significativo como b<sub>7</sub>. Indicar cuáles son los bits que se modifican y qué valores toman al aplicar las siguientes operaciones:

    <table>
    <tr>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>a)</i> num |= 1 << 2; </td>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>d)</i> num |= (1 << 1) | (1 << 3); </td>
    </tr>
    <tr>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>b)</i> num &= ~(1 << 1) </td>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>e)</i> num &= ~((1 << 2) | (1 << 6)); </td>
    </tr>
    <tr>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>c)</i> num ^= (1 << 3); </td>
      <td style="width: 400px; height: 50px; font-family: monospace"> <i>f)</i> num ^= (1 << 0) | (1 << 1); </td>
    </tr>
    </table>

1. Escribir un programa que imprima en notación binaria un número de 8 bits recibido desde la lı́nea de comandos. El siguiente código fuente muestra el esqueleto del programa con una posible implementación de la función para imprimir en notación binaria una variable tipo `unsigned char`.

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    void binary_print(unsigned char );

    int main(int argc , char *argv[])
    {
        /* Completar */
    }

    void binary_print(unsigned char val)
    {
        unsigned char b, mask = 1 << 7;
    
        for(b = 1; b <= 8*sizeof(unsigned char); b++)
        {
            putchar(val & mask ? '1' : '0');
            mask >>= 1;
        }
    }
    ```
    Completar el cuerpo de la función `main()` para que el programa tenga la interacción del usuario como se muestra a continuación.

    ```
    ./binary
    Uso: ./binary <num>
    ./binary 16
     16 = 00010000
    ./binary 128
     128 = 10000000
    ./binary 160
     160 = 10100000
    ```
    Al ejecutar el programa sin argumentos, el mismo muestra la forma correcta de uso indicando que espera recibir un valor numérico como argumento.

1. Modificar el programa del ejercicio anterior para que pueda imprimir en binario números de 16 bits. Responder además las siguientes preguntas:
    1. ¿Qué tipo de dato del lenguaje C resulta adecuado para almacenar un valor entero positivo de 16 bits?
    1. ¿Cuál es el valor máximo que puede almacenar este tipo de dato?
    1. ¿Qué valores hay que pasarle al programa para que el número binario tenga un único bit en uno (desde el bit b<sub>0</sub> al bit b<sub>15</sub>)?

1. Escribir un programa que realice las operaciones AND, OR y OR exclusiva a nivel de bits entre dos valores numéricos de 8 bits cargados desde la lı́nea de comandos. La interacción con el usuario debe ser como se muestra a continuación, donde los valores de entrada se expresan en notación decimal y el resultado en notación decimal y hexadecimal.
    ```
    ./and_or_xor
    Uso: ./and_or_xor <num1> <num2>
    ./and_or_xor 128 160
     128 &  160 =  128
    0x80 & 0xA0 = 0x80
     128 |  160 = 160
    0x80 | 0xA0 = 0xA0
     128 ^  160 = 032
    0x80 ^ 0xA0 = 0x20
    ```

1. Escribir un programa que muestre el valor de los bits menos significativo (LSB, Least Significant Bit) y más significativo (MSB, Most Significant Bit) de un valor numérico de 8 bits cargado desde la lı́nea de comandos. La interacción con el usuario debe ser como se muestra a continuación.
    ```
    ./lsb_msb
    Uso: ./lsb_msb <num>
    ./lsb_msb 128
    El LSB de 128 es 0
    El MSB de 128 es 1
    ```

1. Escribir un programa que muestre el valor de un bit a elección de una variable numérica de 8 bits. Tanto el número como el bit a leer se pasan por lı́nea de comandos. La interacción con el usuario debe ser como se muestra a continuación.
    ```
    ./get_bit
    Uso: ./get_bit <num> <bit>
    ./get_bit 160 0
    El bit 0 de 160 es 0
    ./get_bit 160 5
    El bit 5 de 160 es 1
    ```

1. Escribir un programa para evaluar el operador de desplazamiento a la izquierda que reciba los dos operandos desde la lı́nea de comandos. La interacción con el usuario debe ser como se muestra a continuación.
    ```
    ./left_shift 2 4
           2 << 4 = 32
    00000010 << 4 = 00100000
    ./left_shift 3 3
           3 << 3 = 24
    00000011 << 3 = 00011000
    ```

1. Escribir un programa para evaluar el operador de desplazamiento a la derecha que reciba los dos operandos desde la lı́nea de comandos.

1. Escribir un programa que ponga a uno lógico un bit especı́fico en un número de 8 bits. La interacción con el usuario debe ser como se muestra a continuación.
    ```
    ./set_bit 6 0
       6 = 00000110
       7 = 00000111
    ./set_bit 11 6
       11 = 00001011
       75 = 01001011
    ```

1. Escribir un programa que ponga a cero lógico un bit especı́fico en un número de 8 bits.

1. Escribir un programa que conmute (toggle) el estado (de 0 a 1 y de 1 a 0) un bit en un número de 8 bits.

1. Escribir un programa que reciba por lı́nea de comandos un entero de 32 bits e imprima en pantalla el valor de los bytes que lo componen en notación hexadecimal. La interacción con el usuario debe ser como se muestra a continuación.
    ```
    ./int_bytes 255
    255 = 00 00 00 FF
    ./int_bytes 65535
    65535 = 00 00 FF FF
    ./int_bytes 123456789
    123456789 = 07 5B CD 15
    ```
