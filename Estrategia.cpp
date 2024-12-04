#include "Estrategia.h"

void Estrategia::seguirLinha(){
  robo.ligarLedSmdVerde();
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
    robo.ligarLedVermelho();
    motores.parar(1000);

    //descomente apenas para debug :)
    cor.lerValores();

    cor.lerSensoresCor();
    if(cor.verdeDir() && cor.verdeEsq()){
      robo.ligarLedVerde();
      motores.emFrente();
      delay(300);
      motores.girar90Esq();
      motores.girar90Esq();
      robo.desligarLedVerde();
    }

    else if(cor.verdeEsq() && cor.brancoDir()){
      robo.ligarLedAmarelo();
      motores.emFrente();
      delay(300);
      motores.girar90Esq();
      robo.desligarLedAmarelo();
    }

    else if(cor.verdeDir() && cor.brancoEsq()){
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
    robo.desligarLedVermelho();
    estadoDeObstaculo = true;
  }

  else if(refletancia.ppbb()){
    motores.emFrente();
    delay(300);
    motores.girar90Esq();
  }
  else if(refletancia.bbpp()){
    motores.emFrente();
    delay(300);
    motores.girar90Dir();
  }
  robo.desligarLedSmdVerde();
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