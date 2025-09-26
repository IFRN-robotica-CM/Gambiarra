#include <Arduino.h>
#include "Estrategia.h"
#include "MeuSensorCor.h"
#include "Refletancia.h"
#include "Motores.h" 
#include <robo_hardware2.h>
Estrategia e;
MeuSensorCor v;
Refletancia r;
Motores m;

void setup() {
  robo.configurar();
  Serial.begin(9600);
  e.iniciar();
}
void loop() {
  // m.emFrente();
  // r.getValues();
  // Serial.println("estou aqui");
  // e.seguirLinha();
  // v.lerValores();
  e.executar();
}