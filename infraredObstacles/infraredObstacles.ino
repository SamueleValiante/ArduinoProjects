// Includiamo la libreria che abbiamo appena installato
#include "max6675.h"

// Definiamo i pin a cui abbiamo collegato il modulo MAX6675
int thermoSO = 4;
int thermoCS = 5;
int thermoSCK = 6;

// Inizializziamo l'oggetto termocoppia passando i pin
MAX6675 termocoppia(thermoSCK, thermoCS, thermoSO);

void setup() {
  // Avviamo la comunicazione seriale per leggere i dati sul PC
  Serial.begin(9600);
  
  Serial.println("Avvio lettura Termocoppia MAX6675...");
  Serial.println("Attendere prego...");
  
  // Il modulo MAX6675 richiede un attimo per stabilizzarsi all'avvio
  delay(500);
}

void loop() {
  // Leggiamo la temperatura in gradi Celsius
  float temperatura = termocoppia.readCelsius();

  // Stampiamo i risultati sul Monitor Seriale
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // NOTA IMPORTANTE: Il chip MAX6675 impiega circa 250ms per effettuare una 
  // conversione hardware. Leggere i dati più velocemente porterà a errori.
  // È consigliabile aspettare almeno mezzo secondo (500ms) o 1 secondo intero.
  delay(1000); 
}