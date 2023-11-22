#ifndef MEUSENSORCOR_H
#define MEUSENSORCOR_H

#include <robo_hardware2.h>

class MeuSensorCor{
  private:
    #define DIVISOR_H_DIR_VERDE  60
    #define DIVISOR_S_DIR_VERDE  0.30
    #define DIVISOR_V_DIR_VERDE  300

    #define DIVISOR_H_DIR_PRETO  60
    #define DIVISOR_S_DIR_PRETO  0.30
    #define DIVISOR_V_DIR_PRETO  300

    #define DIVISOR_H_DIR_BRANCO  50
    #define DIVISOR_S_DIR_BRANCO  0.20
    #define DIVISOR_V_DIR_BRANCO  700


    #define DIVISOR_H_ESQ_VERDE  60
    #define DIVISOR_S_ESQ_VERDE  0.30
    #define DIVISOR_V_ESQ_VERDE  600

    #define DIVISOR_H_ESQ_PRETO  60
    #define DIVISOR_S_ESQ_PRETO  0.27
    #define DIVISOR_V_ESQ_PRETO  400

    #define DIVISOR_H_ESQ_BRANCO  60
    #define DIVISOR_S_ESQ_BRANCO  0.30
    #define DIVISOR_V_ESQ_BRANCO  600

    HSV sensorCorDir;
    HSV SensorCorEsq;
  
	public:

    inline bool  verdeDir(){return(sensorCorDir.h >  DIVISOR_H_DIR_VERDE && sensorCorDir.s <  DIVISOR_S_DIR_VERDE && sensorCorDir.v >  DIVISOR_V_DIR_VERDE);}
    inline bool  PretoDir(){return(sensorCorDir.h <  DIVISOR_H_DIR_PRETO && sensorCorDir.s <  DIVISOR_S_DIR_PRETO && sensorCorDir.v >  DIVISOR_V_DIR_PRETO);}
    inline bool BrancoDir(){return(sensorCorDir.h > DIVISOR_H_DIR_BRANCO && sensorCorDir.s < DIVISOR_S_DIR_BRANCO && sensorCorDir.v > DIVISOR_V_DIR_BRANCO);}

    inline bool  verdeEsq(){return(SensorCorEsq.h >  DIVISOR_H_ESQ_VERDE && SensorCorEsq.s <  DIVISOR_S_ESQ_VERDE && SensorCorEsq.v <  DIVISOR_V_ESQ_VERDE);}
    inline bool  PretoEsq(){return(SensorCorEsq.h <  DIVISOR_H_ESQ_PRETO && SensorCorEsq.s >  DIVISOR_S_ESQ_PRETO && SensorCorEsq.v <  DIVISOR_V_ESQ_PRETO);}
    inline bool BrancoEsq(){return(SensorCorEsq.h > DIVISOR_H_ESQ_BRANCO && SensorCorEsq.s < DIVISOR_S_ESQ_BRANCO && SensorCorEsq.v > DIVISOR_V_ESQ_BRANCO);}

    inline bool      direita(){return(!(verdeEsq()) && verdeDir() );}
    inline bool     esquerda(){return(!(verdeDir()) && verdeEsq() );}
    inline bool becoSemSaida(){return(verdeDir() && verdeEsq());}

    inline void atualizarSensoresCor(){sensorCorDir = robo.getHSVDireito(); SensorCorEsq = robo.getHSVEsquerdo(); sensorCorDir = robo.getHSVDireito(); SensorCorEsq = robo.getHSVEsquerdo(); sensorCorDir = robo.getHSVDireito(); SensorCorEsq = robo.getHSVEsquerdo(); sensorCorDir = robo.getHSVDireito(); SensorCorEsq = robo.getHSVEsquerdo(); sensorCorDir = robo.getHSVDireito(); delay(500); SensorCorEsq = robo.getHSVEsquerdo();}
		
    inline void getValuesEsq(){Serial.print("Valor do sensor de cor Esq: "); Serial.print(SensorCorEsq.h); Serial.print(", "); Serial.print(SensorCorEsq.s); Serial.print(", "); Serial.print(SensorCorEsq.v); Serial.println(); delay(500);}
    inline void getValuesDir(){Serial.print("Valor do sensor de cor Dir: "); Serial.print(sensorCorDir.h); Serial.print(", "); Serial.print(sensorCorDir.s); Serial.print(", "); Serial.print(sensorCorDir.v); Serial.println(); delay(500);}
    inline void getValues(){getValuesEsq();getValuesDir();}

    void testar();
    //inline void testar(){Serial.print("sensor cor Dir:");if(verdeDir()){Serial.println("verde");}else{{Serial.println("Não verde");}Serial.print("sensor cor Esq:");if(verdeEsq()){Serial.println("verde");}else{{Serial.println("Não verde");} delay(500);}


};

#endif
