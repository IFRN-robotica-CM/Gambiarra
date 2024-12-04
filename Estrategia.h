#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware2.h>
#include "Motores.h"
#include "Refletancia.h"
#include "Laiser.h"
#include "MeuSensorCor.h"

class Estrategia {
  public:
      void seguirLinha();
      void desviarObstaculoDir();
      void desviarObstaculoEsq();
      void executar();
      void alinhar();
    
  private:
    Refletancia refletancia;
    Motores motores;
    MeuSensorCor cor;
    Laiser dist;

    bool estadoDeObstaculo = true;
};

#endif
