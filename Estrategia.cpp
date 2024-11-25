#include "Estrategia.h"

void Estrategia::seguirLinha(){
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
}