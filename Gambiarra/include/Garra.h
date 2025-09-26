#include <Servo.h>
#include <Arduino.h>

#define SERVO_BRACO  9     // Pino do servo do braço
#define SERVO_GARRA  11    // Pino do servo da garra

class Garra {
  private:
    Servo servoBraco;
    Servo servoGarra;

  public:
    Garra() {}

    void begin() {
      servoBraco.attach(SERVO_BRACO);
      servoGarra.attach(SERVO_GARRA);
    }

    void fecharGarra() {
      servoGarra.write(0);
      
    }

    void abrirGarra() {
      servoGarra.write(180);
      delay(1000);
    }

    void levantarBraco() {
      servoBraco.write(0);
      delay(1000);
    }

    void medioBraco() {
      servoBraco.write(45);
      delay(1000);
    }

      void medianaBraco() {
      servoBraco.write(15);
      delay(1000);
    }

    void descerBraco() {
      servoBraco.write(70);
      delay(1000);
    }
};
