#include "Estrategia.h"
#include <robo_hardware2.h>

Estrategia e;

void setup() {
  robo.configurar();
  Serial.begin(9600);
}
void loop() {
  e.seguirLinha();
}