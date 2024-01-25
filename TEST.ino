#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Crea un objeto MFRC522

void setup() {
  Serial.begin(9600);   // Inicializa la comunicación serial
  SPI.begin();      // Inicializa la comunicación SPI
  mfrc522.PCD_Init();   // Inicializa el módulo RFID
  Serial.println("Acerca una tarjeta RFID al lector...");
}

void loop() {
  // Verifica si hay una nueva tarjeta RFID presente
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Lee el UID de la tarjeta RFID
    Serial.print("UID de la tarjeta: ");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println();

    mfrc522.PICC_HaltA();   // Detiene la comunicación con la tarjeta RFID
  }
}
