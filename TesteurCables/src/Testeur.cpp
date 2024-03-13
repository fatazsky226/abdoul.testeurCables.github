#include "Testeur.hpp"
#include <Arduino.h>

using namespace std;

Testeur::Testeur(int * pinDroiteCable, int * pinGaucheCable, bool etat_ , type_Cable cables)
{
    pinDroit = pinDroiteCable;
    pinGauche = pinGaucheCable;
    etat = etat_; 
    type = cables; 
}

Testeur::~Testeur()
{
}

Testeur::initialisation() {

    
}

void Testeur::typeCable()
{   

    for (int i = 0; i < 7; i++)
    {
        /* code */
            pinMode(pinD[i], OUTPUT);
            pinMode(pinG[j], INPUT_PULLDOWN);

    }
    
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            digitalWrite(pinD[i], HIGH);
            delay(100);

            int etat = digitalRead(pinG[j]);
            int readValue = 0;

            if(etat == HIGH)
                readValue = 1;
            else
                readValue = 0;
            
            digitalWrite(pinD[i], LOW);
            delay(100);
        }
    }
}

void Testeur::affichage()
{
    for (int i = 0; i < 8; i++) 
    { 
        pinMode(pinDroit[i], OUTPUT);
        digitalWrite(pinDroit[i], HIGH); //envoyer le signal

        int etat = digitalRead(pinGauche[i]); // lire l'état de la broche

        if (etat == HIGH) {
            Serial.println("Le cable est bien brancher ");
        }
        else {
            Serial.println("Le cable n'est pas bien brancher ");
        }

        digitalWrite(pinDroit[i], LOW); //initialise les broches
    }

}
