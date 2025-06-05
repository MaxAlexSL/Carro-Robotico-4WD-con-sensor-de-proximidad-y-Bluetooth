// Pines del L298N
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;

// Pines del HC-SR04
const int trigPin = 2;
const int echoPin = 3;

// Variables
long duracion;
int distancia;
char estadoComando = 'x'; // estado actual del comando

void setup() {
  Serial.begin(9600);  // Comunicación con HC-06

  // Pines motores
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Pines sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  distancia = medirDistancia();

  // Si hay datos por Bluetooth
  if (Serial.available()) {
    char comando = Serial.read();
    estadoComando = comando; // Actualiza el estado actual
  }

  // Verificar el comando actual
  switch (estadoComando) {
    case 'd': // izquierda
      digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
      break;

    case 'a': // derecha
      digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
      break;

    case 's': // atrás
      digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
      break;

    case 'w': // adelante, pero con verificación constante
      if (distancia > 10) {
        digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
      } else {
        detener();
        Serial.println("¡Obstáculo detectado! Detenido.");
        estadoComando = 'x';  // Cambio de estado a detenido
      }
      break;

    case 'x': // detener
    default:
      detener();
      break;
  }
}

int medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH, 30000);  // Espera máxima 30ms
  int distanciaCm = duracion * 0.034 / 2;

  if (distanciaCm == 0) distanciaCm = 999; // Sin lectura
  return distanciaCm;
}

void detener() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
