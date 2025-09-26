#ifndef REFLETANCIA_H
#define REFLETANCIA_H

#include <robo_hardware2.h>

class Refletancia {
  
  private:
    // #define DIVISOR_BRANCO_PRETO_MAIS_ESQ 50
    // #define DIVISOR_BRANCO_PRETO_ESQ 60
    // #define DIVISOR_BRANCO_PRETO_DIR 65
    // #define DIVISOR_BRANCO_PRETO_MAIS_DIR 50
    // #define DIVISOR_BRANCO_PRETO_CENTRAL 0.1
    // #define DIVISOR_BRANCO_PRETO_FRONTAL 52

    #define DIVISOR_BRANCO_PRETO_MAIS_ESQ 42
    #define DIVISOR_BRANCO_PRETO_ESQ 45
    #define DIVISOR_BRANCO_PRETO_DIR 45
    #define DIVISOR_BRANCO_PRETO_MAIS_DIR 45
    #define DIVISOR_BRANCO_PRETO_CENTRAL 1
    #define DIVISOR_BRANCO_PRETO_FRONTAL 38

    #define DIVISOR_CINZA 96
    
  
    float SensorLinhaEsq;
    float SensorLinhaDir; 
    float SensorLinhaMaisEsq;
    float SensorLinhaMaisDir;
    float SensorLinhaCentral;
    float SensorLinhaFrontal; 
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

    inline bool bb() {return (SensorLinhaCentral>DIVISOR_BRANCO_PRETO_CENTRAL && SensorLinhaFrontal>DIVISOR_BRANCO_PRETO_FRONTAL);}
    inline bool bp() {return (SensorLinhaCentral>DIVISOR_BRANCO_PRETO_CENTRAL && SensorLinhaFrontal<DIVISOR_BRANCO_PRETO_FRONTAL);}
    inline bool pb() {return (SensorLinhaCentral<DIVISOR_BRANCO_PRETO_CENTRAL && SensorLinhaFrontal>DIVISOR_BRANCO_PRETO_FRONTAL);}
    inline bool pp() {return (SensorLinhaCentral<DIVISOR_BRANCO_PRETO_CENTRAL && SensorLinhaFrontal<DIVISOR_BRANCO_PRETO_FRONTAL);}
    
    inline bool IdentificaArea() {return(SensorLinhaMaisEsq<DIVISOR_CINZA && SensorLinhaMaisEsq>DIVISOR_BRANCO_PRETO_MAIS_ESQ
                                      && SensorLinhaEsq<DIVISOR_CINZA     && SensorLinhaEsq>DIVISOR_BRANCO_PRETO_ESQ
                                      && SensorLinhaDir<DIVISOR_CINZA     && SensorLinhaDir>DIVISOR_BRANCO_PRETO_DIR
                                      && SensorLinhaMaisDir<DIVISOR_CINZA && SensorLinhaMaisDir>DIVISOR_BRANCO_PRETO_MAIS_DIR
                                      && SensorLinhaFrontal<DIVISOR_CINZA && SensorLinhaFrontal>DIVISOR_BRANCO_PRETO_FRONTAL
                                    );}

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
