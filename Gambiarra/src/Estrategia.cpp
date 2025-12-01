#include "../include/Estrategia.h"

void Estrategia::seguirLinha() {
  // Atualiza leituras
  refletancia.atualizarSensoresRefletancia();

  
  if (refletancia.frente() || refletancia.gap()) {
    motores.emFrente();
  }
  else if (refletancia.noventaGrausDir() || refletancia.direita()) {
    motores.direita();
  }
  else if (refletancia.noventaGrausEsq() || refletancia.esquerda()) {
    motores.esquerda();
  }
  else if (refletancia.noventaGrausDirVerde()){
    fazerVerde();
  }
  else if (refletancia.noventaGrausEsqVerde()){
    fazerVerde();
  }
  else if (refletancia.encruzilhada()){
    fazerVerde();
  }
  else if (refletancia.encruzilhadaT()){
    fazerVerde();
  }
  else {
    motores.emFrente();
  }

  estadoDeObstaculo = true;
}

 void Estrategia::fazerVerde(){
  motores.parar(500);
  String esq = robo.lerNomeCorEsq();
  String dir = robo.lerNomeCorDir();
  Serial.println("Esq: " + esq + "  |  Dir: " + dir);
  Serial.println(esq != "Verde");
  
  if (esq == "Verde" && dir == "Verde"){
    robo.ligarLedVerde();
    motores.emFrente();
    delay(100);
    motores.girar90Dir();
    motores.girar90Dir();
    robo.desligarLedVerde();
  }

  if (esq != "Verde" && dir == "Verde" ){
    robo.ligarLedAzul();
    motores.emFrente();
    delay(100);
    motores.girar90Dir();
    robo.desligarLedAzul();
  }

  if (esq == "Verde" && dir != "Verde"){
    robo.ligarLedAmarelo();
    motores.emFrente();
    delay(100);
    motores.girar90Esq();
    robo.desligarLedAmarelo();
  }
  else{
    motores.emFrente();
    delay(100);
  }

 }

void Estrategia::executar(){
  dist.atualizarSensorLaiser();
  refletancia.atualizarSensoresRefletancia();

  if (dist.identificouObstaculo() && estadoDeObstaculo){
    desviarObstaculoEsq();
  }
  // else if (refletancia.IdentificaArea()){
  //   motores.emFrente();
  //   delay(100);
  //   motores.parar(1000);

  //   cor.lerSensoresCor();
  //   MeuSensorCor::CORES corDir = cor.verificaCorDir();
  //   MeuSensorCor::CORES corEsq = cor.verificaCorEsq();

  //   if(corDir == cor.CINZA && corEsq == cor.CINZA){
  //     robo.ligarTodosLeds();
  //     resgatar();
  //     robo.desligarTodosLeds();
  //   }
  //   else{
  //     motores.emFrente();
  //     delay(100);
  //   }
  //}
  else{
    seguirLinha();
  }
}

void Estrategia::alinhar(){
  refletancia.atualizarSensoresRefletancia();
  while(!(refletancia.pppp())){
    refletancia.atualizarSensoresRefletancia();
    if(refletancia.desalinhou_direita()){
      motores.esquerda();
    }
    else if(refletancia.desalinhou_esquerda()){
      motores.direita();
    }
    else{
      motores.paraTras();
    }
  }
  motores.parar(500);

}

void Estrategia::desviarObstaculoEsq(){
  motores.parar(500);
  robo.ligarLedVermelho();
  motores.parar(500);
  motores.girar90Esq();
  alinhar();
  motores.emFrente();
  delay(1200);
  motores.girar90Dir();
  motores.emFrente();
  delay(1500);
  motores.girar90Dir();
  motores.emFrente();
  delay(1200);
  alinhar();
  motores.emFrente();
  delay(300);
  motores.girar90Esq();
  refletancia.atualizarSensoresRefletancia();
  while(!(refletancia.bbbb())){
    refletancia.atualizarSensoresRefletancia();
    if(refletancia.desalinhou_direita()){
      motores.direita();
    }
    else if(refletancia.desalinhou_esquerda()){
      motores.esquerda();
    }
    else{
      motores.emFrente();
    }
  }
  robo.desligarLedVermelho();
  estadoDeObstaculo = false;
}

void Estrategia::resgatarComCamera(){
  while (1){
    //Envia o pedido das coordenadas
    Serial.println("GET_CIRCLE");

    //Lê o json com o circulo
    String Circulo = Serial.readString();

    Serial.print("Arduino :");
    Serial.println(Circulo);

    if (Circulo.length() == 0) {
      robo.acionarMotores(-40, 40); // gira devagar
      delay(300);
      continue;
    }

    DynamicJsonDocument docCirculo(1024);

    //Desemcapsula o json
    DeserializationError error = deserializeJson(docCirculo, Circulo);
    
    if (error) {

        Serial.print(F("Falha ao deserializar JSON: "));
        Serial.println(error.f_str());
    }
    
    r = docCirculo["r"];

    Serial.print("Arduino:");
    Serial.println(r);

    if(r < 20){
      robo.acionarMotores(80,80);
      delay(100);
    }
    else if ( r >= 20){
      
      robo.acionarMotores(0, 0);
      delay(100);
      garra.descerBraco();
      garra.abrirGarra();
      motores.emFrente();
      delay(1000);
      // motores.parar(5000);
      garra.fecharGarra();
      delay(900);
      garra.levantarBraco();
      motores.parar(1000);
      motores.girar45Esq();
      motores.parar(5000);

      while (1)
      {
        robo.acionarMotores(0,0);
        Serial.println("GET_RESCUE");
      
      //Lê o json com a area de resgate
      String rescue = Serial.readString();

      Serial.print("Arduino :");
      Serial.println(rescue);
      }
      
      // Serial.println("GET_RESCUE");
      
      // //Lê o json com a area de resgate
      // String rescue = Serial.readString();

      // Serial.print("Arduino :");
      // Serial.println(rescue);

      // DynamicJsonDocument docRescue(1024);

      // //Desemcapsula o json
      // DeserializationError error = deserializeJson(docRescue, rescue);
      
      // if (error) {
      //   Serial.print(F("Falha ao deserializar JSON: "));
      //   Serial.println(error.f_str());
      //   motores.parar(10000);
      //   return;
      // }

      // if(rescue){
      //   robo.desligarTodosLeds();
      //   robo.ligarLedVerde();
      //   motores.parar(5000);
      // }

      // else{
      //   robo.desligarTodosLeds();
      //   robo.ligarLedVermelho();
      //   motores.parar(5000);
      //   motores.paraTras();
      // }
      
    }
    else{
      robo.acionarMotores(0,0);
    }

    robo.acionarMotores(0,0);
  }
}

void Estrategia::resgatar(){
  motores.emFrente();
  delay(1000);
  motores.girar90Dir();
  motores.emFrente();
  delay(3300);
  motores.parar(7000);
  
}

void Estrategia::iniciar(){
  garra.begin();
  garra.fecharGarra();
  garra.levantarBraco();
  delay(1000);
}