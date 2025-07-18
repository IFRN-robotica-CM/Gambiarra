#include "Estrategia.h"

//-=-=-=-SEGUIR LINHA-=-=-//
void Estrategia::seguirLinha(){
  //Lê sensores de linha
  refletancia.atualizarSensoresRefletancia();

  //Se todos forem brancos
  if(refletancia.bbbb() && refletancia.bb()){
    //Para e lê o sensor de cor
    motores.parar(1000);
    cor.lerSensoresCor();
    MeuSensorCor::CORES corDir = cor.verificaCorDir();
    MeuSensorCor::CORES corEsq = cor.verificaCorEsq();
    
    //Se for área de resgate
    if(corDir == cor.CINZA && corEsq == cor.CINZA){
      motores.parar(1000);
      robo.ligarTodosLeds();
      delay(1000);
      robo.desligarTodosLeds();
    }
    //Se não vai pra frente
    else{
      motores.emFrente();
      delay(50);
    }
  }

  if (refletancia.frente()){
    motores.emFrente();
  }
  else if(refletancia.direita()){
    motores.direita();
  }
  else if(refletancia.esquerda()){
    motores.esquerda();
  }

  else if(refletancia.bbpp()){
    if(refletancia.pp() || refletancia.bp()){
      motores.parar(1000);
      fazerVerde();
    }else{
      motores.direita();
    }
  }

  else if(refletancia.ppbb()){
    if(refletancia.pp() || refletancia.bp()){
      motores.parar(1000);
      fazerVerde();
    }else{
      motores.esquerda();
    }
  }
  else if(refletancia.pppp()){
    motores.parar(1000);
    robo.ligarTodosLeds();
    delay(100);
    robo.desligarTodosLeds();
    delay(100);
    fazerVerde();
    estadoDeObstaculo = true;
  }
}

void Estrategia::testarCasoCor(){
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
    cor.lerValores();
  }
}



void Estrategia::fazerVerde(){
  cor.lerSensoresCor();
  MeuSensorCor::CORES corDir = cor.verificaCorDir();
  MeuSensorCor::CORES corEsq = cor.verificaCorEsq();

  if(corDir == cor.VERDE && corEsq == cor.VERDE){
    robo.ligarLedVerde();

    motores.emFrente();
    delay(100);
    robo.acionarMotores(80, -80);
    delay(2200);
    motores.emFrente();
    delay(300);

    robo.desligarLedVerde();
  }

  else if(!(corDir == cor.VERDE) && corEsq == cor.VERDE){
    robo.ligarLedAmarelo();

    motores.emFrente();
    delay(100);
    motores.girar90Esq();

    robo.desligarLedAmarelo();
  }

  else if(corDir == cor.VERDE && !(corEsq == cor.VERDE)){
    robo.ligarLedAzul();

    motores.emFrente();
    delay(100);
    motores.girar90Dir();

    robo.desligarLedAzul();
  }
  else{
    motores.emFrente();
    delay(100);
  }
}

void Estrategia::executar(){
  dist.atualizarSensorLaiser();

  if (dist.identificouObstaculo() && estadoDeObstaculo){
    desviarObstaculoDir();
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
void Estrategia::desviarObstaculoDir(){
  robo.ligarLedSmdVermelho();
  motores.parar(500);
  motores.girar90Dir();
  alinhar();
  motores.emFrente();
  delay(1500);
  motores.girar90Esq();
  motores.emFrente();
  delay(2000);
  motores.girar90Esq();
  motores.emFrente();
  delay(1500);
  alinhar();
  motores.emFrente();
  delay(300);
  motores.girar90Dir();
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