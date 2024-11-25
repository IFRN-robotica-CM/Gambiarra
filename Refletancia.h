#ifndef REFLETANCIA_H
#define REFLETANCIA_H

#include <robo_hardware2.h>

class Refletancia {
  
    private:
    
        #define DIVISOR_BRANCO_PRETO_MAIS_ESQ 80
        #define DIVISOR_BRANCO_PRETO_ESQ 70
        #define DIVISOR_BRANCO_PRETO_DIR 70
        #define DIVISOR_BRANCO_PRETO_MAIS_DIR 80

        float SensorLinhaEsq;
        float SensorLinhaDir; 
        float SensorLinhaMaisEsq;
        float SensorLinhaMaisDir;


    public:
        
        inline bool pppp() {return (SensorLinhaMaisEsq<DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq<DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir<DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir<DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool pppb() {return (SensorLinhaMaisEsq<DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq<DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir<DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir>DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool ppbb() {return (SensorLinhaMaisEsq<DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq<DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir>DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir>DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool pbbb() {return (SensorLinhaMaisEsq<DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq>DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir>DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir>DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bppp() {return (SensorLinhaMaisEsq>DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq<DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir<DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir<DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bppb() {return (SensorLinhaMaisEsq>DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq<DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir<DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir>DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bpbb() {return (SensorLinhaMaisEsq>DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq<DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir>DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir>DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bbpp() {return (SensorLinhaMaisEsq>DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq>DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir<DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir<DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bbpb() {return (SensorLinhaMaisEsq>DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq>DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir<DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir>DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bbbp() {return (SensorLinhaMaisEsq>DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq>DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir>DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir<DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bbbb() {return (SensorLinhaMaisEsq>DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq>DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaDir>DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir>DIVISOR_BRANCO_PRETO_MAIS_DIR);}

        inline bool   frente(){return (bbbb() || bppb());}
        inline bool esquerda(){return (pppb() || pbbb() || bpbb());}
        inline bool  direita(){return (bppp() || bbpb() || bbbp());}
        inline bool  casoCor(){return (pppp() || ppbb() || bbpp());}
        
        inline bool  desalinhou_direita(){return (bppp() || bbpp() || bbpb() || bbbp());}
        inline bool desalinhou_esquerda(){return (pppb() || ppbb() || pbbb() || bpbb() );}
        
        void atualizarSensoresRefletancia();
        void testar();
        void getValues();
};
    
#endif
