#ifndef CALIBRADOR_H
#define CALIBRADOR_H

#include <robo_hardware2.h>
#include "Refletancia.h"
#include "MeuSensorCor.h"

class Calibrador {
  
    private:
    
    public:
      void calibrarLinha();
      void calibrarCor();

      Refletancia sensoresLinha;
      MeuSensorCor sensorCor;
        
};
    
#endif
