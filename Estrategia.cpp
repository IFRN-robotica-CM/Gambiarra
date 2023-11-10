#include "Estrategia.h"

void Estrategia::seguirLinha(){

    sensoresLinha.atualizarSensoresRefletancia();

    if(sensoresLinha.frente()){
      motores.emFrente();
    }
    
    else if(sensoresLinha.direita()){
      motores.direita();
    }
    
    else if(sensoresLinha.esquerda()){
      motores.esquerda();
    } 
  }

void Estrategia::executar(){
  seguirLinha();
}
