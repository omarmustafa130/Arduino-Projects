#include "TOF10120.h"

TOF10120 sensor = TOF10120();

void setup() {
  Serial.begin(115200);
  sensor.init();
}

void loop() {
  int distance_mm = sensor.distance();
  float distance_in = distance_mm / 25.4;  // Convert mm to inches
  
  Serial.print("distance: ");
  Serial.print(distance_mm);
  Serial.print(" mm (");
  Serial.print(distance_in, 2);  // The ",2" formats to 2 decimal places
  Serial.println(" in)");
  
  delay(100);
}