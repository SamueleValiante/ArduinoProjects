// Includiamo la libreria che abbiamo appena installato
#include "max6675.h"
#include <TM1637Display.h>

#define DIO 8
#define CLK 9

// Definiamo i pin a cui abbiamo collegato il modulo MAX6675
int thermoSO = 4;
int thermoCS = 3;
int thermoSCK = 2;

// parola ciao
uint8_t ciao[] = {
  SEG_A | SEG_D | SEG_E | SEG_F, // C
  SEG_B | SEG_C, // I
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G, // A
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F// O
};

uint8_t c[] = {SEG_A | SEG_D | SEG_E | SEG_F};

// Inizializziamo l'oggetto termocoppia passando i pin
MAX6675 termocoppia(thermoSCK, thermoCS, thermoSO);

// inizializzo il display
TM1637Display display(CLK, DIO);

void setup() {
  // Avviamo la comunicazione seriale per leggere i dati sul PC
  Serial.begin(9600);

  display.setBrightness(4);
  display.clear();
  
  display.setSegments(ciao);

  // Il modulo MAX6675 richiede un attimo per stabilizzarsi all'avvio
  delay(2000);
}

void loop() {

  display.clear();

  // Leggiamo la temperatura in gradi Celsius
  float temperatura = termocoppia.readCelsius();

  // Stampiamo i risultati sul display
  display.showNumberDec(temperatura, false, 3, 0);

  display.setSegments(c, 1, 3);

  // NOTA IMPORTANTE: Il chip MAX6675 impiega circa 250ms per effettuare una 
  // conversione hardware. Leggere i dati più velocemente porterà a errori.
  // È consigliabile aspettare almeno mezzo secondo (500ms) o 1 secondo intero.
  delay(1000); 
}