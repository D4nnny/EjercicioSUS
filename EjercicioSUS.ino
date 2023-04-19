// Definir los pines del sensor ultrasónico
#define TRIGGER_PIN 2
#define ECHO_PIN 3

void setup() {
  // Iniciar la comunicación serial a 9600 baudios
  Serial.begin(9600);
  
  // Configurar los pines del sensor ultrasónico
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Disparar un pulso de ultrasonido
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Leer el tiempo que tarda el eco en regresar
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Convertir el tiempo a distancia en centímetros
  float distance = duration * 0.034 / 2;
  
  // Imprimir la distancia en la consola serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Esperar un momento antes de realizar otra medición
  delay(500);
}
