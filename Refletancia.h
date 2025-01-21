#ifndef REFLETANCIA_H
#define REFLETANCIA_H

#include <robo_hardware2.h>

class Refletancia {
  
    private:
        #define DIVISOR_BRANCO_PRETO_MAIS_ESQ 80
        #define DIVISOR_BRANCO_PRETO_ESQ 70
        #define DIVISOR_BRANCO_PRETO_CEN 70
        #define DIVISOR_BRANCO_PRETO_FRO 70
        #define DIVISOR_BRANCO_PRETO_DIR 70
        #define DIVISOR_BRANCO_PRETO_MAIS_DIR 80
        
        float SensorLinhaMaisEsq;
        float SensorLinhaEsq;
        float SensorLinhaCen;
        float SensorLinhaFro; 
        float SensorLinhaDir; 
        float SensorLinhaMaisDir;

    public:
        inline bool bbppbb() {return (SensorLinhaMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq > DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen < DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro < DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir > DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bbpbbb() {return (SensorLinhaMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq > DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen < DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir > DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bbbpbb() {return (SensorLinhaMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq > DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen > DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro < DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir > DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);}

        // Curva 90°
        inline bool bbpbpp() {return (SensorLinhaMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq > DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen < DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir < DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool pppbbb() {return (SensorLinhaMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq < DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen < DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir > DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);}

        // Curva comum
        inline bool bbbbbp() {return (SensorLinhaMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq > DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen > DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir > DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bbbbpp() {return (SensorLinhaMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq > DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen > DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir < DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bbbbpb() {return (SensorLinhaMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq > DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen > DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir < DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool ppbbbb() {return (SensorLinhaMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq < DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen > DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir > DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool pbbbbb() {return (SensorLinhaMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq > DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen > DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir > DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bpbbbb() {return (SensorLinhaMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq < DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen > DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir > DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);}

        // Casos de verde
        inline bool pppbpp() {return (SensorLinhaMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq < DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen < DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir < DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool pppppp() {return (SensorLinhaMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq < DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen < DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro < DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir < DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool bbpppp() {return (SensorLinhaMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq > DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen < DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro < DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir < DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR);}
        inline bool ppppbb() {return (SensorLinhaMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq < DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen < DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro < DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir > DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);}

        // Gap
        inline bool bbbbbb() {return (SensorLinhaMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && SensorLinhaEsq > DIVISOR_BRANCO_PRETO_ESQ && SensorLinhaCen > DIVISOR_BRANCO_PRETO_CEN && SensorLinhaFro > DIVISOR_BRANCO_PRETO_FRO && SensorLinhaDir > DIVISOR_BRANCO_PRETO_DIR && SensorLinhaMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);}
               
        inline bool linhaReta(){return(bbppbb() || bbpbbb() || bbbpbb());}
        inline bool     esq90(){return(pppbbb());}
        inline bool     dir90(){return(bbpbpp());}
        inline bool       esq(){return(ppbbbb() || pbbbbb() || bpbbbb());}
        inline bool       dir(){return(bbbbbp() || bbbbpp() || bbbbpb());}
        inline bool     verde(){return(pppbpp() || pppppp() || bbpppp() || ppppbb());}
        inline bool       gap(){return(bbbbbb());}
        
        void atualizarSensoresRefletancia();
        void testar();
        void getValues();
};
    
#endif
