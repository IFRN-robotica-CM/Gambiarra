#include "Estrategia.h"

void Estrategia::seguirLinha(){
  //lê sensores de linha
  refletancia.atualizarSensoresRefletancia();
  
  if (refletancia.frente()){
    motores.emFrente();
  }
  else if(refletancia.direita()){
    motores.direita();
  }
  else if(refletancia.esquerda()){
    motores.esquerda();
  }

  else if(refletancia.pppp()){
    motores.parar(500);
    fazerVerde();
    estadoDeObstaculo = true;
  }
}

void Estrategia::fazerVerde(){
  cor.lerSensoresCor();
  MeuSensorCor::CORES corDir = cor.verificaCorDir();
  MeuSensorCor::CORES corEsq = cor.verificaCorEsq();

  if(corDir == cor.VERDE && corEsq == cor.VERDE){
    robo.ligarLedVerde();

    motores.emFrente();
    delay(300);
    motores.girar90Esq();
    motores.girar90Esq();

    robo.desligarLedVerde();
  }

  else if(!(corDir == cor.VERDE) && corEsq == cor.VERDE){
    robo.ligarLedAmarelo();

    motores.emFrente();
    delay(300);
    motores.girar90Esq();

    robo.desligarLedAmarelo();
  }

  else if(corDir == cor.VERDE && !(corEsq == cor.VERDE)){
    robo.ligarLedAzul();

    motores.emFrente();
    delay(300);
    motores.girar90Dir();

    robo.desligarLedAzul();
  }
  else{
    motores.emFrente();
    delay(300);
  }
}

void Estrategia::executar(){
  dist.atualizarSensorLaiser();

  if (dist.identificouObstaculo() && estadoDeObstaculo){
    desviarObstaculoEsq();
  }
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
  robo.ligarLedSmdVermelho();
  motores.parar(500);
  motores.girar90Esq();
  alinhar();
  motores.emFrente();
  delay(1500);
  motores.girar90Dir();
  motores.emFrente();
  delay(2000);
  motores.girar90Dir();
  motores.emFrente();
  delay(1500);
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
  robo.desligarLedSmdVermelho();
  estadoDeObstaculo = false;
}