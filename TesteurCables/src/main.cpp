#include<Arduino.h>
#include"Testeur.hpp"

#define PINI1 15
#define PINI2 2
#define PINI3 4
#define PINI4 5
#define PINI5 18
#define PINI6 19
#define PINI7 21
#define PINI8 22

// Declaration des pins du deuxième coté
#define PINO1 13
#define PINO2 14
#define PINO3 27
#define PINO4 26
#define PINO5 25
#define PINO6 33
#define PINO7 32
#define PINO8 12


int pinI[]= {PINI1, PINI2, PINI3, PINI4, PINI5, PINI6, PINI7, PINI8 };

int pinO[]= {PINO1, PINO2, PINO3, PINO4, PINO5, PINO6, PINO7, PINO8 };

        Testeur testeur(pinO, pinI);

void setup(){

        
        Serial.begin(9600);
        
        
}

void loop(){

                testeur.typeCable();
                delay(1000);
}