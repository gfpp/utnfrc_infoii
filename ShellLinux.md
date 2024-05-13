# La Shell de Linux

Gonzalo F. Perez Paina

## Ejercicicios

1. Utilizar el comando `echo` para imprimir el valor de las variables de entorno `HOME`, `USER`, `PATH`, `SHELL`, `EDITOR`, `PWD` y `OLDPWD`. ¿Qué información contiene cada variable de entorno?

1. El siguiente script (de nombre `envvar.sh`) imprime algunas variables de entorno.
    ```bash
    #!/bin/bash
    
    echo $#
    echo $0
    echo $1
    ```
    Codificar el script, darle permisos de ejecución y ejecutarlo mediante los siguientes comandos:
    ```
    > ./envvar.sh
    > ./envvar.sh hola
    > ./envvar.sh hola 123
    ```
    ¿Qué sucede en cada caso?

1. Escribir un programa en lenguaje C que inicialice dos enteros y devuelva el valor de la suma mediante el `return` de la función principal `main`. Utilizar el comando `echo` para mostrar dicho valor almacenado en la variable de entorno `?`.

1. ¿Qué hacen los siguiente comando de la shell?
    1. `ls $HOME`
    1. `ls /home/$USER`
    1. `cd`
    1. `cd $OLDPWD`
    1. `cd -`

1. Utilizar el comando `man` para ver las páginas de manuales de las funciones de la biblioteca matemática (archivo de cabecera `math.h`) para las funciones `sqrt()` y `pow()`.

1. Ir al directorio `home` del usuario y crear un directorio (`mkdir`) de nombre `tmp` y moverse (`cd`) a este directorio. Luego, generar una estructura de directorios y archivos (usar el comando `touch`) que forme el siguiente árbol:
    ```
    tmp
     |-- dir1
     |-- dir2
     |   |-- dir2a
     |   |   |-- file1
     |   |-- dir2b
     |       |-- file2
     |-- dir3
     ```
    Una vez creados los archivos puede ver que cumpla con la estructura solicitada utilizando el comando `tree` dentro del directorio `tmp`. A continuación:
    1. Ir al directorio `dir2b` y mover el archivo `file2` al directorio `dir2a` (utilizar path relativo)
    1. Estando en el directorio `dir2b`, listar (`ls`) el contenido del directorio `tmp`
    1. Ir al directorio `dir1` y crear el archivo `file3a` bajo el directorio `dir3` utilizando path relativo
    1. Estando en el directorio `dir1`, crear el archivo `file3b` bajo el directorio `dir3` utilizando path absoluto
    1. Ir al directorio `dir2a` y cambiar el nombre del archivo `file1` a `file` (utilizar el comando `mv`)
    1. Ir al directorio `dir2` y eliminar todos los archivos del directorio `dir2a` (`rm dir2a/*`)
    1. Ir al directorio `tmp` y borrar todos los archivos (`rm`) y directorios (`rmdir`) utilizando paths relativos
    1. Borrar el directorio `tmp`

1. Crear un script de bash _"Hola mundo"_ y guardar con nombre `hola.sh`
    ```bash
    #!/bin/bash
    echo "Hola Informática-II"
    ```
    Luego:
    1. Ejecutar con: `> ./hola.sh`. ¿Qué sucede?.
    1. Observarlos permisos del archivo `hola.sh` (`ls -l`).
    1. Agregar permisos de ejecución del usuario (`chmod u+x hola.sh`).
    1. Ejecutar nuevamente.
    1. Desplegar el archivo en la terminal (`cat hola.sh`).
    1. Quiterle permiso de lectura del usuario (`chmod u-r hola.sh`).
    1. Desplegar nuevamente el archivo con el comando `cat`. ¿Qué sucede?.
    1. Ejecutar el script.
    1. Agregar permisos de lectura y de ejecución (`chmod u+wr hola.sh`).

1. Escribir un programa en lenguaje C que calcule la raíz cuadrada de un número entero, que tenga la siguiente interacción con el usuario:
    1. Solicitar al usuario un número entero (cero para salir).
    1. Mostrar en la salida estándar (`stdout`) la raíz cuadrada del entero ingresado.
    1. Mostrar en la salida de error estándar (`stderr`) si el entero es negativo.

    Ejecute el programa:
    1. Redireccionando a un archivo la salida estándar.
    1. Redireccionando a un archivo la salida de error estándar.
    1. Redireccionando la entrada desde un archivo.
    1. Redireccionando la salida de error estándar al archivo `/dev/null`.

    (Utilizar la función `fprintf()` de biblioteca de entrada/salida estándar (`stdio`). Ver la página de manual de dicha función.)

1. Ir al directorio del usuario y crear un directorio de prueba
    ```
    > cd [ENTER]
    > mkdir prueba
    ```
    Luego:
    1. Crear un directorio: `> mkdir dir`
    1. Crear un archivo vacio (0 bytes) dentro del directorio creado: `> touch dir/vacio`
    1. Mostrar los permisos del archivo creado: `> ls -l dir/vacio`
    1. Mostar los permisos del propio directorio (archivo): `> ls -ld dir`. Anotar los permisos en forma numérica (p.e., 735)
    1. Quitar permiso de lectura al directorio: `> chmod u-r dir`
    1. Mostrar los archivos del directorio: `> ls -l dir`. ¿Qué pasa?
    1. Moverse al directorio (`mv dir`) y listar los archivos (`ls`)
    1. Restablecer los permisos originales del directorio creado utilizando notación numérica
    1. Quitar permiso de escritura al directorio (`chmod u-w dir`) y crear otro archivo vacio
    1. Borrar los archivos (`rm`) y directorios (`rmdir`) creados haciendo los cambios de permisos necesarios

1. Abrir una terminal, ejecutar un programa y matarlo con el comando `kill`, por ejemplo:
    1. ejecutar `gedit` en segundo plano: `> gedit &`
    1. listar los procesos y filtrar la salida con `grep`: `> ps aux | grep gedit`
    1. anotar el número de proceso del programa `gedit`
    1. matar el proceso `> kill -KILL <PID>`
