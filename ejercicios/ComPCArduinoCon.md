# Conexión TTY entre la PC y la placa Arduino UNO
Al conectar una placa Arduino a la PC con sistema operativo GNU/Linux se genera un dispositivo serie, que generalmente se encuentra en `/dev/ttyACM0` o bien `/dev/ttyUSB0`. Este dispositivo serie se utiliza para grabar el programa al microcontrolador de la placa y puede usarse también para comunicar la PC con la placa Arduino. Una manera de determinar el dispositivo donde se mapea el puerto serie al conectar una placa Arduino es a través del comando \texttt{dmesg}, el cual brinda información de Kernel del SO GNU/Linux.

A continuación se muestra la salida del comando `dmesg` al conectar la placa Arduino UNO Rev3:
```
> dmesg -H | tail
[Jul31 13:32] usb 1-1: new full-speed USB device number 29 using xhci_hcd
[  +0,150543] usb 1-1: New USB device found, idVendor=2341, idProduct=0043
[  +0,000005] usb 1-1: New USB device strings: Mfr=1, Product=2, SerialNumber=220
[  +0,000004] usb 1-1: Manufacturer: Arduino (www.arduino.cc)
[  +0,000003] usb 1-1: SerialNumber: 7563031343635141A1E2
[  +0,004172] cdc_acm 1-1:1.0: ttyACM0: USB ACM device
```
y para la placa Arduino UNO CH340:
```
> dmesg -H | tail
[Jul31 14:08] usb 1-1: new full-speed USB device number 21 using xhci_hcd
[  +0.148997] usb 1-1: New USB device found, idVendor=1a86, idProduct=7523
[  +0.000002] usb 1-1: New USB device strings: Mfr=0, Product=2, SerialNumber=0
[  +0.000002] usb 1-1: Product: USB2.0-Serial
[  +0.002049] ch341 1-1:1.0: ch341-uart converter detected
[  +0.000448] usb 1-1: ch341-uart converter now attached to ttyUSB0
```

Como se observa, la placa Arduino UNO Rev3 genera el dispositivo `/dev/ttyACM0` mientras que la placa Arduino UNO CH430 el dispositivo `/dev/ttyUSB0`.


