#include <Arduino.h>

class LEDRGB {
private:
  int pin_boton;
  bool estado_anterior_boton;
  bool estado_del_pulsador;
  int pin_boton_01;
  int pin_boton_02;
  int pin_boton_03;
  int contador_01;
  int contador_02;
  int contador_03;

public:
  LEDRGB();
  void aumentar_contador (int & contador, int pin);
  void disminuir_contador(int & contador, int pin); 
  void setup();
  void loop();
};