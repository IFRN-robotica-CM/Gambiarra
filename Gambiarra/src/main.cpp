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
  robo.carregarCalibracao();
  // e.iniciar();
}
void loop() {
  // m.girar90Esq();
  // m.parar(5000);
  // m.emFrente();
  // r.getValues();
  // Serial.println("estou aqui");
  // e.seguirLinha();
  // v.lerValores();
  e.executar();
}