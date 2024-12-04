#ifndef MEUSENSORCOR_H
#define MEUSENSORCOR_H

#include <robo_hardware2.h>

class MeuSensorCor{
  private:

	public:
    RGBC leituraSensorCorDir; 
    RGBC leituraSensorCorEsq; 

    inline void lerSensoresCor(){leituraSensorCorDir = robo.getRGBSensorDireito(); leituraSensorCorEsq = robo.getRGBSensorEsquerdo();}

    inline bool   pretoDir(){return(leituraSensorCorDir.clear < 1400);}
    inline bool   verdeDir(){return(leituraSensorCorDir.clear < 2200);}
    inline bool   cinzaDir(){return(leituraSensorCorDir.clear < 2500);}
    inline bool  brancoDir(){return(leituraSensorCorDir.clear < 4500);}

    inline bool brancoEsq(){return(leituraSensorCorEsq.clear < 3000);}
    inline bool  verdeEsq(){return(leituraSensorCorEsq.clear < 1100);}
    inline bool  pretoEsq(){return(leituraSensorCorEsq.clear < 500 );}
    inline bool  cinzaEsq(){return(leituraSensorCorEsq.clear < 1500);}

    void lerValores();
};

#endif
