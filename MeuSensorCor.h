#ifndef MEUSENSORCOR_H
#define MEUSENSORCOR_H

#include <robo_hardware2.h>

class MeuSensorCor{
  private:
    #define VALOR_BRANCO_ESQ 0.20
    #define VALOR_BRANCO_DIR 0.29

    HSV sensorCorDir;
    HSV SensorCorEsq;
  
	public:

    inline bool  verdeDir(){return(sensorCorDir.h > 60 && sensorCorDir.s < 0.30 && sensorCorDir.v > 300);}
    inline bool  PretoDir(){return(sensorCorDir.h < 60 && sensorCorDir.s < 0.30 && sensorCorDir.v > 300);}
    inline bool BrancoDir(){return(sensorCorDir.h > 50 && sensorCorDir.s < 0.20 && sensorCorDir.v > 700);}

    inline bool  verdeEsq(){return(SensorCorEsq.h > 60 && SensorCorEsq.s < 0.22 && SensorCorEsq.v > 600);}
    inline bool  PretoEsq(){return(SensorCorEsq.h < 60 && SensorCorEsq.s > 0.27 && SensorCorEsq.v > 300);}
    inline bool BrancoEsq(){return(SensorCorEsq.h > 60 && SensorCorEsq.s < 0.22 && SensorCorEsq.v > 600);}

    inline void atualizarSensoresCor(){sensorCorDir = robo.getHSVDireito(); SensorCorEsq = robo.getHSVEsquerdo();}
		

};

#endif
