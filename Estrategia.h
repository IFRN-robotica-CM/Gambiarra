#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware2.h>
#include "Motores.h"
#include "Refletancia.h"

class Estrategia {
  public:

    void executar();
    
  private:

      void seguirLinha();

      Refletancia sensoresLinha;
      Motores motores;
};

#endif
