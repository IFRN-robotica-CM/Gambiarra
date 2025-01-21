#include "Estrategia.h"

void Estrategia::seguirLinha(){
  robo.ligarLedSmdVerde();
  refletancia.atualizarSensoresRefletancia();
  if (refletancia.linhaReta() || refletancia.gap()){
      motores.emFrente();
  }

  else if(refletancia.dir()){
    motores.direita();
  }
  else if(refletancia.esq()){
    motores.esquerda();
  }
  else if(refletancia.verde()){
    robo.ligarLedVermelho();
    motores.parar(1000);
    robo.desligarLedVermelho();
  }

  else if(refletancia.esq90()){
    motores.emFrente();
    delay(300);
    motores.girar90Esq();
  }
  else if(refletancia.dir90()){
    motores.emFrente();
    delay(300);
    motores.girar90Dir();
    }
  robo.desligarLedSmdVerde();
  estadoDeObstaculo = true;
}

// void Estrategia::executar(){
//   dist.atualizarSensorLaiser();

//   if (dist.identificouObstaculo() && estadoDeObstaculo){
//     desviarObstaculoEsq();
//   }
//   else{
//     seguirLinha();
//   }
// }
// 
// void Estrategia::alinhar(){
//   refletancia.atualizarSensoresRefletancia();
//   while(!(refletancia.pppp())){
//     refletancia.atualizarSensoresRefletancia();
//     if(refletancia.desalinhou_direita()){
//       motores.esquerda();
//     }
//     else if(refletancia.desalinhou_esquerda()){
//       motores.direita();
//     }
//     else{
//       motores.paraTras();
//     }
//   }
//   motores.parar(500);

// }

// void Estrategia::desviarObstaculoEsq(){
//   robo.ligarLedSmdVermelho();
//   motores.parar(500);
//   motores.girar90Esq();
//   alinhar();
//   motores.emFrente();
//   delay(1500);
//   motores.girar90Dir();
//   motores.emFrente();
//   delay(2000);
//   motores.girar90Dir();
//   motores.emFrente();
//   delay(1500);
//   alinhar();
//   motores.emFrente();
//   delay(300);
//   motores.girar90Esq();
//   refletancia.atualizarSensoresRefletancia();
//   while(!(refletancia.bbbb())){
//     refletancia.atualizarSensoresRefletancia();
//     if(refletancia.desalinhou_direita()){
//       motores.direita();
//     }
//     else if(refletancia.desalinhou_esquerda()){
//       motores.esquerda();
//     }
//     else{
//       motores.emFrente();
//     }
//   }
//   robo.desligarLedSmdVermelho();
//   estadoDeObstaculo = false;
// }