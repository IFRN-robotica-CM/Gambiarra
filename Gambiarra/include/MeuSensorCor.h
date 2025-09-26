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

    inline bool   pretoDir(){return(leituraSensorCorDir.clear > 0   && leituraSensorCorDir.clear < 300);}
    inline bool   verdeDir(){return(leituraSensorCorDir.clear > 300 && leituraSensorCorDir.clear < 700);}
    inline bool   cinzaDir(){return(leituraSensorCorDir.clear > 700 && leituraSensorCorDir.clear < 1000);}
    inline bool  brancoDir(){return(leituraSensorCorDir.clear > 1000);}

    inline bool brancoEsq(){return(leituraSensorCorEsq.clear > 1000);}
    inline bool  verdeEsq(){return(leituraSensorCorEsq.clear > 300 && leituraSensorCorEsq.clear < 700);}
    inline bool  pretoEsq(){return(leituraSensorCorEsq.clear > 0   && leituraSensorCorEsq.clear < 300);}
    inline bool  cinzaEsq(){return(leituraSensorCorEsq.clear > 700 && leituraSensorCorEsq.clear < 1000);}

    CORES verificaCorDir();
    CORES verificaCorEsq();
    void lerValores();
};

#endif
