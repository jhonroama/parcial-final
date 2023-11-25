#include <red-green-blue.h>


LEDRGB::LEDRGB(){
  pin_boton = 35;
  estado_anterior_boton = HIGH;
  estado_del_pulsador = false;
  pin_boton_01 = 36;
  pin_boton_02 = 39;
  pin_boton_03 = 34;
  contador_01 = 255;
  contador_02 = 255;
  contador_03 = 255;

}

void LEDRGB::aumentar_contador(int &contador, int pin) {
    contador += 10;
    analogWrite(pin, contador);
    delay(100);
    if (contador > 255) {
      contador = 255;
      analogWrite(pin, contador);
    }
}

void LEDRGB::disminuir_contador(int &contador, int pin) {
    contador -= 10;
    analogWrite(pin, contador);
    delay(100);
    if (contador < 0) {
      contador = 0;
      analogWrite(pin, contador);
    }
}

void LEDRGB::setup() {
    Serial.begin(9600);
}

void LEDRGB::loop() {
    int estadoBoton = digitalRead(pin_boton);
    int estado1 = digitalRead(pin_boton_01);
    int estado2 = digitalRead(pin_boton_02);
    int estado3 = digitalRead(pin_boton_03);

    if (estadoBoton != estado_anterior_boton) {
      estadoBoton = digitalRead(pin_boton);

        if (estadoBoton == 0) {
            if (!estado_del_pulsador) {
                estado_del_pulsador = true;
                Serial.println("SUBIR");
            } else {
                estado_del_pulsador = false;
                Serial.println("BAJAR");
            }
        }
    }
    if (estado1 == 1 && estado_del_pulsador == 1) {
      disminuir_contador(contador_01, 12);
    } else 
    if (estado1 == 1 && estado_del_pulsador == 0) {
      aumentar_contador(contador_01, 12);
    } else 
    if (estado2 == 1 && estado_del_pulsador == 1) {
      disminuir_contador(contador_02, 13);
    } else 
    if (estado2 == 1 && estado_del_pulsador == 0) {
      aumentar_contador(contador_02, 13);
    } else 
    if (estado3 == 1 && estado_del_pulsador == 1) {
      disminuir_contador(contador_03, 27);
    } else 
    if (estado3 == 1 && estado_del_pulsador == 0) {
      aumentar_contador(contador_03, 27);
    }

    Serial.println(estado_del_pulsador);
    Serial.println("Valores");
    Serial.print(contador_01);
    Serial.print(" ");
    Serial.print(contador_02);
    Serial.print(" ");
    Serial.print(contador_03);
    Serial.print(" ");
    delay(250);
    estado_anterior_boton = estadoBoton;
}
