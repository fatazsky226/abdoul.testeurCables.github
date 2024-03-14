#include<Arduino.h>
#include"Testeur.hpp"

/*
L'ordre des couleur 
OrangeBlanc: PIN01;     orange: PIN02;     VertBlanc: PIN03;    Bleu: PIN04
bleuBlanc  : PIN05;     vert  : PIN06;     marronblanc: PIN07;  marron: PIN08
*/

// Définition des broches d'entrée
#define PINI1 15
#define PINI2 2
#define PINI3 4
#define PINI4 5
#define PINI5 18
#define PINI6 19
#define PINI7 21
#define PINI8 22

// Définition des broches de sortie
#define PINO1 13
#define PINO2 14
#define PINO3 27
#define PINO4 26
#define PINO5 25
#define PINO6 33
#define PINO7 32
#define PINO8 12

// 

// Tableau des broches d'entrée
int pinI[]= {PINI1, PINI2, PINI3, PINI4, PINI5, PINI6, PINI7, PINI8 };

// Tableau des broches de sortie
int pinO[]= {PINO1, PINO2, PINO3, PINO4, PINO5, PINO6, PINO7, PINO8 };

// Création d'une instance de la classe Testeur avec les broches d'entrée et de sortie
Testeur testeur(pinO, pinI);

void setup(){

        
        Serial.begin(9600);
        
        
}

void loop(){

                testeur.typeCable();    // Appel de la fonction
                delay(3000);         // Attente de 3secondes
}