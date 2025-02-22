#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 8);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MIN);

  radio.setChannel(76);
  radio.openReadingPipe(0, pipe);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    byte data;
    radio.read(&data, sizeof(data));
    Serial.print("Received: ");
    Serial.println(data);
      delay(10);

  }
}