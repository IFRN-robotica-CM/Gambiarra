#include "Estrategia.h"
#include "MeuSensorCor.h"
#include "Refletancia.h"
#include <robo_hardware2.h>

Estrategia e;
MeuSensorCor c;
Refletancia r;

void setup() {
  robo.configurar();
  Serial.begin(9600);
}
void loop() {
  e.executar();
  // r.getValues();
  // c.lerValores();
}