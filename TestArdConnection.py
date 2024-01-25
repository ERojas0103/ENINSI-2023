import serial

# configurar el puerto serial
arduino = serial.Serial('COM4', 9600)  # puerto y velocidad de comunicación

while True:
    # leer los datos del Arduino
    data = arduino.readline().decode('utf-8')

    # imprimir los datos leídos
    print(data)
