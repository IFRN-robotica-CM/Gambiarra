#include "Refletancia.h"

void Refletancia::atualizarSensoresRefletancia(){
    SensorLinhaEsq = robo.lerSensorLinhaEsqSemRuido();
    SensorLinhaDir = robo.lerSensorLinhaDirSemRuido(); 
    SensorLinhaMaisEsq = robo.lerSensorLinhaMaisEsqSemRuido();
    SensorLinhaMaisDir = robo.lerSensorLinhaMaisDirSemRuido();
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
