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

    else if(sensoresLinha.pppp()){
      motores.emFrente();
      delay(300);
      motores.parar(100);
      
      robo.habilitaTCS34();
      sensorCor.atualizarSensoresCor();
      
      if(!(sensorCor.verdeEsq()) && sensorCor.verdeDir()){
        motores.emFrente();
        delay(200);
        motores.girar90Esq();
        }
        
      else{
        motores.paraTras();
        delay(400);
        motores.emFrente();
        delay(100);
        }
    }
    
  }

void Estrategia::alinharLinha(){
    while(!sensoresLinha.pppp()){
        sensoresLinha.atualizarSensoresRefletancia();
        
        if(sensoresLinha.desalinhou_direita()){
           motores.direita();
        }
        else if(sensoresLinha.desalinhou_esquerda()){
           motores.esquerda();
        }
        else{
        motores.paraTras();
        }
    }
  }

void Estrategia::desviarObstaculoPelaEsq(){
  sensoresLinha.atualizarSensoresRefletancia();
  
  motores.girar90Dir();
 
  alinharLinha();

  motores.emFrente();
  delay(2500);
  
  motores.girar90Esq();
  
  motores.emFrente();
  delay(4000);
  
  motores.girar90Esq();
  
  motores.emFrente();
  delay(1500);

  sensoresLinha.atualizarSensoresRefletancia();
 
  alinharLinha();
  
  motores.emFrente();
  delay(600);
  
  motores.girar90Dir();
}

void Estrategia::desviarObstaculoPelaDir(){
  sensoresLinha.atualizarSensoresRefletancia();
  
  motores.girar90Esq();
 
  alinharLinha();

  motores.emFrente();
  delay(2500);
  
  motores.girar90Dir();
  
  motores.emFrente();
  delay(4000);
  
  motores.girar90Dir();
  
  motores.emFrente();
  delay(1500);

  sensoresLinha.atualizarSensoresRefletancia();
 
  alinharLinha();
  
  motores.emFrente();
  delay(600);
  
  motores.girar90Esq();
}

void Estrategia::executar(){
  sonar.atualizarSensorSonar();
  
  if(sonar.getSensorSonar() <= 7){
    desviarObstaculoPelaDir();
  }
  else{
    seguirLinha();
  }
}
