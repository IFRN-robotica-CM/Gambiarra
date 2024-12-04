#ifndef LAISER_H
#define LAIZER_H

#include <robo_hardware2.h>

class Laiser{
    private:
      int ValorSensorLaizer;
    public:
      inline void atualizarSensorLaiser(){ValorSensorLaizer = robo.lerSensorLaiserFrontal();}
      inline bool  identificouObstaculo(){ return(ValorSensorLaizer <= 70);}
};
    
#endif
