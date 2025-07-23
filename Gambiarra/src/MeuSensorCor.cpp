#include "../include/MeuSensorCor.h"

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
  Serial.print(", ");

  MeuSensorCor::CORES cor = verificaCorDir();

  if (cor == BRANCO){
    Serial.print("Branco");
  }
  else if (cor == CINZA){
    Serial.print("Cinza");
  }
  else if (cor == PRETO){
    Serial.print("Preto");
  }
  else if (cor == VERDE){
    Serial.print("Verde");
  }
  else{
    Serial.print("Cor não identificada!");
  }
  
  //imprime os 3 valores retornardos pelo sensor cor
  Serial.print("  ESQ: ");
  Serial.print(leituraSensorCorEsq.red);
  Serial.print(", ");
  Serial.print(leituraSensorCorEsq.green);
  Serial.print(", ");
  Serial.print(leituraSensorCorEsq.blue);
  Serial.print(", ");
  Serial.print(leituraSensorCorEsq.clear);
  Serial.print(", ");
  
  cor = verificaCorEsq();

  if (cor == BRANCO){
    Serial.print("Branco");
  }
  else if (cor == CINZA){
    Serial.print("Cinza");
  }
  else if (cor == PRETO){
    Serial.print("Preto");
  }
  else if (cor == VERDE){
    Serial.print("Verde");
  }
  else{
    Serial.print("Cor não identificada!");
  }
  
  Serial.println();
  delay(500);
}

MeuSensorCor::CORES MeuSensorCor::verificaCorDir(){
  if (brancoDir()){
    return BRANCO;
  }
  else if (cinzaDir()){
    return CINZA;
  }
  else if (verdeDir()){
    return VERDE;
  }
  else if (pretoDir()){
    return PRETO;
  }
  
}

MeuSensorCor::CORES MeuSensorCor::verificaCorEsq(){
  if (brancoEsq()){
    return BRANCO;
  }
  else if (cinzaEsq()){
    return CINZA;
  }
  else if (pretoEsq()){
    return PRETO;
  }
  else if (verdeEsq()){
    return VERDE;
  }

}