#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware2.h>
#include "Motores.h"
#include "Refletancia.h"
#include "Sonar.h"
#include "MeuSensorCor.h"

class Estrategia {
  public:
      void seguirLinha();
    
  private:
    Refletancia refletancia;
    Motores motores;
    MeuSensorCor cor;
};

#endif
