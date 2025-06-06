#ifndef MEUSENSORCOR_H
#define MEUSENSORCOR_H

#include <robo_hardware2.h>

class MeuSensorCor{
  private:

	public:
    RGBC leituraSensorCorDir; 
    RGBC leituraSensorCorEsq; 

    enum CORES{VERDE, BRANCO, PRETO, CINZA};

    inline void lerSensoresCor(){leituraSensorCorDir = robo.lerSensorDeCorDir(); leituraSensorCorEsq = robo.lerSensorDeCorEsq();}

    inline bool   pretoDir(){return(leituraSensorCorDir.clear < 800);}
    inline bool   verdeDir(){return(leituraSensorCorDir.clear < 980);}
    inline bool   cinzaDir(){return(leituraSensorCorDir.clear > 1130);}
    inline bool  brancoDir(){return(leituraSensorCorDir.clear > 1300);}

    inline bool brancoEsq(){return(leituraSensorCorEsq.clear > 1400);}
    inline bool  verdeEsq(){return(leituraSensorCorEsq.clear > 1000);}
    inline bool  pretoEsq(){return(leituraSensorCorEsq.clear < 847);}
    inline bool  cinzaEsq(){return(leituraSensorCorEsq.clear > 1200);}

    CORES verificaCorDir();
    CORES verificaCorEsq();
    void lerValores();
};

#endif
