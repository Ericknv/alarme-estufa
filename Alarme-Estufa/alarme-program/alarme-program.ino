// Pino analógico do sensor de temperatura TMP36
#define PIN_SENSOR_TEMPERATURA A1

// Pinos do motor de ventilador, LED vermelho e buzina
#define PIN_VENTILADOR 5
#define PIN_LED_VERMELHO 11
#define PIN_BUZINA 9

void setup() {
  // Define os pinos como saída
  pinMode(PIN_VENTILADOR, OUTPUT);
  pinMode(PIN_LED_VERMELHO, OUTPUT);
  pinMode(PIN_BUZINA, OUTPUT);

  // Inicializa a comunicação serial para monitoramento
  Serial.begin(9600);
}

void loop() {
  // Faz a leitura da tensão do sensor de temperatura TMP36
  int tensao = analogRead(PIN_SENSOR_TEMPERATURA);

  // Converte a tensão em temperatura (considerando que o sensor gera 10mV por grau Celsius)
  float temperatura = (tensao * 5.0) / 1023.0;
  temperatura = (temperatura - 0.5) * 100.0;

  // Exibe a temperatura no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // Verifica se a temperatura é maior ou igual a 30 °C
  if (temperatura >= 30) {
    // Liga o motor de ventilador
    digitalWrite(PIN_VENTILADOR, HIGH);
  } else {
    // Desliga o motor de ventilador
    digitalWrite(PIN_VENTILADOR, LOW);
  }

  // Verifica se a temperatura é maior que 50 °C
  if (temperatura > 50) {
    // Liga o LED vermelho e a buzina
    digitalWrite(PIN_LED_VERMELHO, HIGH);
    digitalWrite(PIN_BUZINA, HIGH);
  } else {
    // Desliga o LED vermelho e a buzina
    digitalWrite(PIN_LED_VERMELHO, LOW);
    digitalWrite(PIN_BUZINA, LOW);
  }

  // Aguarda um intervalo antes de fazer a próxima leitura
  delay(1000);
}
