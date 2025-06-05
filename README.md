# Carro-Robotico-4WD-con-sensor-de-proximidad-y-Bluetooth
Carro controlado por Arduino con 4 motores, L298N y un sensor de proximidad

# 🤖 Carro Robótico 4WD con Sensor de Proximidad y Bluetooth

Este es un proyecto de robótica con Arduino que permite controlar un **carro de 4 ruedas (4WD)** mediante comandos Bluetooth (`w`, `a`, `s`, `d`) desde un celular. Además, cuenta con **sensores de proximidad** que evitan colisiones frontales de forma automática.

---

## 🚀 Funcionalidades

- Control de movimiento con comandos por Bluetooth.
- Sensado de obstáculos con sensores de proximidad (ej. HC-SR04 o IR).
- Capacidad para moverse hacia adelante, atrás, izquierda y derecha.
- Controlado por un Arduino Uno y un módulo L298N para los motores DC.
- Alimentado por dos baterías de 3.7 V.

---

## 🧰 Componentes Utilizados

| Componente                  | Cantidad |
|-----------------------------|----------|
| Arduino UNO                 | 1        |
| Módulo L298N                | 1        |
| Motores DC (4WD)            | 4        |
| Sensores de proximidad (IR/Ultrasónico) | 2 |
| Módulo Bluetooth HC-05/06   | 1        |
| Baterías 3.7V (en serie)    | 2        |
| Jumpers y cables            | Varios   |
| Protoboard (opcional)       | 1        |

---

## 🔌 Esquema de Conexiones

### ➤ Motores:
- **Motor A (izquierda):**
  - IN1 → pin 8 (Arduino)
  - IN2 → pin 9
- **Motor B (derecha):**
  - IN3 → pin 10
  - IN4 → pin 11
- **ENA →** pin 5 (PWM)
- **ENB →** pin 6 (PWM)

### ➤ Bluetooth (HC-05):
- VCC → 5V
- GND → GND
- TX → pin 2 (Arduino RX)
- RX → pin 3 (Arduino TX) *(usa divisor de voltaje)*

### ➤ Sensor de proximidad:
- Trigger → pin 12
- Echo → pin 13

### ➤ Alimentación:
- Baterías 3.7V x2 en serie (7.4V) → pin 12V del L298N
- GND de baterías → GND del L298N y Arduino

---

## 💻 Control por Bluetooth

Usa una app como **Bluetooth Electronics** o **Arduino Bluetooth Controller** desde tu celular y envía los siguientes comandos:

| Comando | Acción         |
|---------|----------------|
| `w`     | Adelante       |
| `s`     | Atrás          |
| `a`     | Girar izquierda|
| `d`     | Girar derecha  |

> Si el sensor detecta un obstáculo, el carro se detiene automáticamente aunque presiones `w`.

---

## 📄 Código fuente

El código está disponible en [`carro.ino`](carro.ino). Incluye las siguientes funciones:

- Lectura de comandos Bluetooth.
- Control de motores con el L298N.
- Lectura del sensor de distancia.
- Lógica de evasión de obstáculos.

---

## 📷 Imagen del montaje (opcional)

> Puedes agregar una imagen aquí si tienes una foto del montaje o un esquema en Fritzing.

---

## ✍️ Autor

**Max Alex Soncco Luque
Jean Franco Colque Galindo
Jadyra Ch'aska Choque Quispe**  
Creado con fines educativos y de aprendizaje de robótica con Arduino.

---

## 📜 Licencia

Este proyecto está bajo la licencia MIT. Eres libre de usarlo, modificarlo y compartirlo.

---

## ⭐ ¿Te gustó?

¡Dale una estrella ⭐ al repositorio si te pareció útil o interesante!

