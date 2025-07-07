# Ejercicios de comunicación entre PC y placa Arduino

Gonzalo F. Perez Paina

<style>
td, th {
   border: none!important;
}
</style>

## Ejercicicios

1. Escribir un programa de PC para la comunicación serie con la placa Arduino con el sketch [`ToggleLEDSerial.ino`](https://github.com/ciiiutnfrc/ponchitoCIII/blob/master/sketch/ToggleLEDSerial/ToggleLEDSerial.ino) que:
    1. Abra el puerto serie `/dev/ttyACM0` (o `/dev/ttyUSB0` dependiendo de la placa) a 9600 bps (se puede utilizar el comando `stty` para ver la configuración por defecto del puerto serie y determinar si es necesario modificar la velocida de comunicación).
    1. Muestre un menú en pantalla de forma continuada donde se solicite al usuario ingresar los siguientes caracteres: `'v'` para cambiar el estado del LED verde, `'a'` para el LED amarillo, `'r'` para el LED rojo, hasta ingresar `'s'` para salir.
    1. Cierre el puerto serie.

1. El sketch de Arduino [`ButtonStateSerialBin.ino`](https://github.com/ciiiutnfrc/ponchitoCIII/blob/master/sketch/ButtonStateSerialBin/ButtonStateSerialBin.ino) envía por el puerto serie el estado de tres pulsadores que están conectados a los pines 4, 7 y 8. El estado de los pulsadores se envía como cadena con tres caracteres que pueden ser `'1'` o `'0'`. Escribir un programa de PC para la comunicación serie con la placa Arduino con sketch antes mencionado, el cual lea de forma continuada una cadena de 4 caracteres (3 estados de pulsadores y retorno de carro) y la imprime en la salida estándar.

1. El sketch Arduino [`ADCFull.ino`](https://github.com/ciiiutnfrc/ponchitoCIII/blob/master/sketch/ADCFull/ADCFull.ino) toma el valor del ADC (Analog to Digital Converter) y lo envía por puerto serie en diferentes formatos. El $`\mu`$C de la placa Arduino, al recibir el caracter `'c'` envía el valor como cadena de caracteres de longitud fija, al recibir `'e'` lo envía como número entero (4 bytes) y al recibir `'f'` lo envía como número en punto flotante (4 bytes de la representación `float`).<br>
    Se puede utilizar el monitor serial del IDE Arduino para probar la recepción solo si se solicita el valor como cadena. Sin embargo, para observar los valores en representación como número entero o punto flotante es conveniente utilizar `cutecom` y ver los valores en representación hexadecimal, o bien escribir un programa para realizar la conversión de datos entre los tipos adecuados.<br>

    El código fuente [`read_int.c`](../src/pc/c/read_int.c) muestra un ejemplo de lectura por puerto serie de un valor entero (`int`) recibido en formato binario. A partir de este ejemplo, escribir un programa de PC para la comunicación serie con la placa Arduino que:
    1. Abra el puerto serie pasado desde la línea de comandos a una velocidad de comunicación de 9600 bps.
    1. Muestre un menú de forma continuada donde se solicite al usuario ingresar los siguientes caracteres: `'c'` para solicitar el valor del ADC como cadena, `'e'` para solicitar el valor como entero, `'f'` como punto flotante, e imprimir el valor recibido. O bien, `'s'` para terminar la ejecución del programa.
    1. Cierre el puerto serie.

1. El sketch [`Display7segSerie.ino`](../src/arduino/sketch/Display7segSerie/Display7segSerie.ino) es un programa que recibe por puerto serie un valor (byte) y lo visualiza en un display de 7 segmentos conectado a 8 pines digitales de salidas. La conexiones entra la placa Arduino UNO y el display de 7 segmentos son: segmento A con `PB0`, B con `PB1`, y los segmentos C hasta DP con `PD2` hasta `PD7` (ver [enlace](ATmega328ESdig.md)).
    Utilizar el programa `cutecom` (no puede utilizarse con el Monitor Serial del IDE Arduino dado que el mismo solo transmite datos en formato cadena) para enviar datos de la PC a la placa Arduio. Para ello se debe configurar la entrada en modo hexadecimal; seleccionar `Hex` en el menú desplegable ubicado al lado del campo de edición de entrada (`Input`).
    1. ¿Qué números en hexadecimal deben enviarse desde la PC al $`\mu`$C para encender de a uno los diferentes segmentos del display?
    1. ¿Qué números en hexadecimal deben enviarse para representar de forma aproximada las diferentes letras del abecedario en el display?

1. Escribir un programa en lenguaje C con la misma funcionalidad del sketch [`Display7segSerie.ino`](../src/arduino/sketch/Display7segSerie/Display7segSerie.ino) , donde los GPIO y la UART se programen mediante el acceso a los registros del $`\mu`$C ATmega328.

1. Escribir un programa de PC que solicite al usuario ingresar un valor hexadecimal y luego lo envíe por el puerto serie, para reemplazar la terminal serial `cutecom` del ejercicio anterior. Este programa debe trabajar con el dispositivo serie que se le pasa como argumento en la línea de comandos. Además, debe leer el valor hexadecimal desde la entrada estándar utilizando la función `scanf` y terminar su ejecución si el valor ingresado es mayor a `0xFF`.

1. Escribir un programa de PC que envíe una serie de valores por el puerto serie cada 1 seg. (el archivo de dispositivo se pasa por la lína de comandos). Los valores a enviar deben representar de forma aproximada las letras del abecedario en el display de 7 segmentos. Por ejemplo, utilizando la conexión de la placa Arduino UNO con el display de 7 segmentos como en los ejercicios anteriores (ver [enlace](ATmega328ESdig.md)), se pueden armar las siguientes letras: `a` con el valor `0x77`, `h` con `0x76`, `n` con `0x54`, `t` con `0x78`, etc.

1. Escribir un programa de PC que realice una petición de lectura del valor del ADC del $`\mu`$C ATmega328 grabado con el sketch [`ADCFull.ino`](https://github.com/ciiiutnfrc/ponchitoCIII/blob/master/sketch/ADCFull/ADCFull.ino) en formato de punto flotante cada 100mseg. (utilizar la función `usleep` para generar el tiempo de espera), y muestre el valor leído por la salida estándar. El programa debe recibir por línea de comando el dispositivo serie con el cual trabajar y la cantidad de dígitos decimales a utilizar para mostrar el valor.
    Por ejempo, si el programa se ejecuta con:
    ```
    $> ./read_adc /dev/ttyUSB0 2
    ```
    se imprimen los valores con dos decimales como:
    ```
    2.21
    2.21
    2.33
    2.45
    ```
    y si se ejecuta con:
    ```
    $> ./read_adc /dev/ttyUSB0 6
    ```
    se imprimen los valores con seis decimales como:
    ```
    1.221896
    1.041056
    0.845552
    0.703812
    ```
    Luego, ejecutar el programa redireccionando la salida estándar a un archivo, tal como:
    ```
    $> ./read_adc /dev/ttyUSB0 4 > datos.txt
    ```
    Estos valores almacenados en un archivo puede utilizarse luego para generar una gráfica.

    A continuación se muestra un script de Python para graficar los datos del archivo `datos.txt`:
    ```python
    #!/usr/bin/env python3
    
    import numpy as np
    from matplotlib import pyplot as plt
    
    data = np.loadtxt('datos.txt')
    
    plt.plot(data)
    plt.show()
    plt.grid()
    ```
    Para usarlo hay que crear un archivo con extensión `.py` (p.e. `plot_txt.py`) en el mismo directorio donde se encuentra el archivo de datos, darle permisos de ejecución y ejecutar el script desde la línea de comandos.
