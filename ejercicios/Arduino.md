# Ejercicios de programación Arduino con sketch

Gonzalo F. Perez Paina

## Ejercicicios

1. Escribir un programa que encienda un LED cuando un pulsador este presionado y lo apague si se libera. El pulsador izquierdo actúa sobre el LED rojo y el pulsador derecho actúa sobre el LED verde.

1. Modificar el programa anterior para que además haga parpadear el LED amarillo cada un segundo (1 seg. encendido y 1 seg. apagado).<br>(Nota: ver el ejemplo del IDE Arduino `BlinkWithoutDelay`)

1. Escribir un programa que haga parpadear un LED variando la frecuencia del parpadeo con el potenciometro.<br>(Nota: ver el ejemplo `AnalogReadSerial`)

1. Escribir un programa que encienda el LED verde con diferente intensidad ajustable con el potenciómetro. Tener en cuenta que el valor leı́do desde el ADC es de 10 bits y el valor a escribir en la salida PWM es de 8 bits, por lo que se debe aplicar un factor de escala.<br>(Nota: ver los ejemplos `AnalogReadSerial` y `Fade`)

1. Escribir un programa que envı́e por puerto serie (Monitor Serial) el estado de los pulsadores. Enviar de forma continua una lı́nea de texto con el estado de los tres pulsadores, similar a:
    ```
    111
    110
    011
    000
    111
    ```
    donde el caracter `1` y `0` simboliza el pulsador liberado y presionado, respectivamente.

1. Modificar el sketch del ejercicio anterior para que el mensaje esté compuesto de 3 líneas, similar a:
    ```
    Estado izq.: presionado
    Estado med.: libre
    Estado der.: presionado
    
    Estado izq.: presionado
    Estado med.: libre
    Estado der.: libre
    ```

1. Modificar el sketch del ejercicio anterior para que se envı́e un único byte con el estado del pulsador (`1` o `0`).

1. Escribir un programa que cambie el estado de los LEDs al recibir una letra por puerto serie:
    *  Al recibir la letra `v` se debe conmutar el estado del LED verde.
    *  Al recibir la letra `a` se debe conmutar el estado del LED amarillo.
    *  Al recibir la letra `r` se debe conmutar el estado del LED rojo.
(Nota: utilizar la función `Serial.readBytes())`

