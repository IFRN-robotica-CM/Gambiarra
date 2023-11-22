#include "MeuSensorCor.h"

void MeuSensorCor::testar(){
  Serial.print("sensor cor Dir:");
  if(verdeDir()){
    Serial.println("verde");
    }
  else{
    Serial.println("Não verde");
    }
  Serial.print("sensor cor Esq:");
  if(verdeEsq()){
    Serial.println("verde");
    }
  else{
    Serial.println("Não verde");
    } 
  delay(500);}
