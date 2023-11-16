#include "Estrategia.h"

void Estrategia::seguirLinha() {

  sensoresLinha.atualizarSensoresRefletancia();

  if (sensoresLinha.frente()) {
    motores.emFrente();
  }

  else if (sensoresLinha.direita()) {
    motores.direita();
  }

  else if (sensoresLinha.esquerda()) {
    motores.esquerda();
  }

  else if (sensoresLinha.pppp()) {
    fazerVerde();
  }

}

void Estrategia::fazerVerde(){
    motores.emFrente();
    delay(300);
    motores.parar(100);
    
    robo.habilitaTCS34();
    sensorCor.atualizarSensoresCor();

    if (sensorCor.direita()) {
      motores.emFrente();
      delay(200);
      motores.girar90Esq();
    }
    
    else if (sensorCor.esquerda()) {
      motores.emFrente();
      delay(200);
      motores.girar90Dir();
    }

    else if (sensorCor.becoSemSaida()) {
      motores.emFrente();
      delay(200);
      motores.girar90Dir();
      motores.girar90Dir();
    }

    else {
      motores.paraTras();
      delay(400);
      motores.emFrente();
      delay(200);
    }
  
  }

void Estrategia::alinharLinha() {
  while (!sensoresLinha.pppp()) {
    sensoresLinha.atualizarSensoresRefletancia();

    if (sensoresLinha.desalinhou_direita()) {
      motores.direita();
    }
    else if (sensoresLinha.desalinhou_esquerda()) {
      motores.esquerda();
    }
    else {
      motores.paraTras();
    }
  }
}

void Estrategia::desviarObstaculoPelaEsq() {
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
  delay(2000);

  sensoresLinha.atualizarSensoresRefletancia();

  alinharLinha();

  motores.emFrente();
  delay(600);

  motores.girar90Dir();

  sensoresLinha.atualizarSensoresRefletancia();
  if (sensoresLinha.bbbb()) {
    motores.paraTras();
    delay(500);
  }
}

void Estrategia::desviarObstaculoPelaDir() {
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
  delay(2000);

  sensoresLinha.atualizarSensoresRefletancia();

  alinharLinha();

  motores.emFrente();
  delay(600);

  motores.girar90Esq();

  sensoresLinha.atualizarSensoresRefletancia();
  if (sensoresLinha.bbbb()) {
    motores.paraTras();
    delay(500);
  }
}

void Estrategia::executar() {
  sonar.atualizarSensorSonar();

  if (sonar.getSensorSonar() <= 7) {
    desviarObstaculoPelaDir();
  }
  else {
    seguirLinha();
  }
}
