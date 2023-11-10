#include "Estrategia.h"
#include <robo_hardware2.h>

Estrategia estrategia;

void setup() {
  robo.configurar(false);
  Serial.begin(9600);
}

void loop() {
  estrategia.executar();
}
