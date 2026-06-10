#include <DHT11.h>

#define DHT11_PIN 7 

// La tua libreria vuole il pin qui tra parentesi
DHT11 dht11(DHT11_PIN); 

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 TEST PROGRAM");
  Serial.println("------------------");
}

void loop() {
  // Variabili per memorizzare i dati
  int humidity = 0;
  int temperature = 0;

  // Tentativo di lettura
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  // Controllo dei risultati tramite i codici errore della tua libreria
  if (result == 0) {
    Serial.print("Humidity (%): ");
    Serial.print(humidity);
    Serial.print("\tTemperature (C): ");
    Serial.println(temperature);
  } else {
    // Se result non è 0, c'è un errore
    Serial.print("Error: ");
    Serial.println(DHT11::getErrorString(result));
  }

  // Aspetta 2 secondi (il DHT11 è lento nelle letture)
  delay(2000);
}