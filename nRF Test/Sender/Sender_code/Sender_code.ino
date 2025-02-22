#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 8);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() {
  radio.begin();
  Serial.begin(115200);
  radio.setDataRate(RF24_250KBPS);
   radio.setPALevel(RF24_PA_MIN);
  radio.setChannel(76);
  radio.openWritingPipe(pipe);
}

void loop() {
  byte data = analogRead(A0);
  Serial.print("Sent: ");
  Serial.println(data);
  radio.write(&data, sizeof(data));
  delay(10);
}