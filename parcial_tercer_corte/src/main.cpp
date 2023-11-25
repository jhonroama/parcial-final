#include <Arduino.h>
#include <red-green-blue.h>

LEDRGB led_colores;
void setup() {
  led_colores.setup(); 
}

void loop() {
  led_colores.loop();
}