#include "Estrategia.h"
#include "MeuSensorCor.h"
#include "Refletancia.h"
#include <robo_hardware2.h>

Estrategia e;
MeuSensorCor v;
Refletancia r;

void setup() {
  robo.configurar();
  Serial.begin(9600);
}
void loop() {
  // r.getValues();
  e.seguirLinha();
  // v.lerValores();
}