#include "Refletancia.h"

void Refletancia::atualizarSensoresRefletancia(){
    SensorLinhaEsq     = robo.lerSensorLinhaEsq();
    SensorLinhaDir     = robo.lerSensorLinhaDir(); 
    SensorLinhaMaisEsq = robo.lerSensorLinhaMaisEsq();
    SensorLinhaMaisDir = robo.lerSensorLinhaMaisDir();
}

void Refletancia::getValues(){
  atualizarSensoresRefletancia();
  
  Serial.print("Sensores refletancia: +esq: ");
  Serial.print(SensorLinhaMaisEsq);
  Serial.print("; esq:");
  Serial.print(SensorLinhaEsq); 
  Serial.print("; dir:");
  Serial.print(SensorLinhaDir); 
  Serial.print("; +dir:");
  Serial.println(SensorLinhaMaisDir);

  delay(500);
    
}

void Refletancia::testar(){
  atualizarSensoresRefletancia();
  
  if(bbbb()){
    Serial.println("BBBB");
  }
  else if(bppb()){
    Serial.println("BPPB");  
  }
  else if(pppp()){
    Serial.println("PPPP"); 
  }
   else if(pppb()){
    Serial.println("PPPB"); 
  }
   else if(ppbb()){
    Serial.println("PPBB"); 
  }
   else if(pbbb()){
    Serial.println("PBBB"); 
  }
   else if(bpbb()){
    Serial.println("BPBB"); 
  }
   else if(bppp()){
    Serial.println("BPPP"); 
  }
   else if(bbpp()){
    Serial.println("BBPP");  
  }
   else if(bbpb()){
    Serial.println("BBPB"); 
  }
   else if(bbbp()){
    Serial.println("BBBP"); 
  }
  
}
