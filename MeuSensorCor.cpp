#include "MeuSensorCor.h"

void MeuSensorCor::lerValores(){
  lerSensoresCor();

  Serial.print("DIR: ");
  Serial.print(leituraSensorCorDir.red);
  Serial.print(", ");
  Serial.print(leituraSensorCorDir.green);
  Serial.print(", ");
  Serial.print(leituraSensorCorDir.blue);
   Serial.print(", ");
  Serial.print(leituraSensorCorDir.clear);

  //imprime os 3 valores retornardos pelo sensor cor
  Serial.print("  ESQ: ");
  Serial.print(leituraSensorCorEsq.red);
  Serial.print(", ");
  Serial.print(leituraSensorCorEsq.green);
  Serial.print(", ");
  Serial.print(leituraSensorCorEsq.blue);
   Serial.print(", ");
  Serial.print(leituraSensorCorEsq.clear);
  
  Serial.println();
  delay(500);
}