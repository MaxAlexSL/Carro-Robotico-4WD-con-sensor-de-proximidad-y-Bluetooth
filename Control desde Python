import serial
import keyboard  # pip install keyboard

# Reemplaza COM6 con el puerto de tu HC-06
puerto = 'COM4'
baudrate = 9600

try:
    arduino = serial.Serial(puerto, baudrate, timeout=1)
    print("Conectado a", puerto)
except:
    print("Error al conectar al puerto")
    exit()

print("Presiona W/A/S/D para mover el robot. X para detener. Esc para salir.")

while True:
    if keyboard.is_pressed("w"):
        arduino.write(b'w')
    elif keyboard.is_pressed("s"):
        arduino.write(b's')
    elif keyboard.is_pressed("a"):
        arduino.write(b'd')
    elif keyboard.is_pressed("d"):
        arduino.write(b'a')
    elif keyboard.is_pressed("x"):
        arduino.write(b'x')
    elif keyboard.is_pressed("esc"):
        print("Saliendo...")
        break
