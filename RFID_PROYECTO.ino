#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);  // crear instancia del objeto MFRC522

void setup() {
  Serial.begin(9600);  // inicializar la comunicación serial
  SPI.begin();  // inicializar la comunicación SPI
  mfrc522.PCD_Init();  // inicializar el módulo MFRC522
}

void loop() {
  // buscar tarjetas RFID
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // obtener el UID de la tarjeta
    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uid += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      uid += String(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println("UID de la tarjeta: " + uid);
    mfrc522.PICC_HaltA();  // detener la comunicación con la tarjeta
    mfrc522.PCD_StopCrypto1();  // detener el cifrado
  }
}
