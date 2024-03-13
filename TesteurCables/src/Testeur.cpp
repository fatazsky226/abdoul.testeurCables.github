#include <Arduino.h>
#include "Testeur.hpp"

Testeur::Testeur(int * pinDroiteCable, int * pinGaucheCable, bool etat_ , type_Cable cables)
{
    pinDroit = pinDroiteCable;
    pinGauche = pinGaucheCable;
    etat = etat_; 
    type = cables; 
}

Testeur::~Testeur(){}

void Testeur::initialisation() {

}

void Testeur::setEtat(bool val){ etat= val;}

void Testeur::setType( type_Cable valtype){ type=valtype;}

void Testeur::typeCable()
{   
    int data[8];

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {   
            int pDroit = *(pinDroit + i);
            int pGauche = *(pinGauche + j);

            pinMode(pDroit, OUTPUT);
            pinMode(pGauche, INPUT_PULLDOWN);

            digitalWrite(pDroit, HIGH);
            delay(100);

            int etat = digitalRead(pGauche);
            int readValue = 0;

            if(etat == HIGH)
                readValue = 1;
            else
                readValue = 0;
            
            digitalWrite(pDroit, LOW);

            if (readValue == 1)
            {
                data[i] = j;
                break;
            }
        }
    }

    bool estEnOrdre = true;

    for (int i = 0; i < 8; i++)
    {
        if (data[i] > data[i + 1])
        {
            estEnOrdre = false;
        }
    }
    
    if (estEnOrdre)
    {
        setEtat(true);
        setType(Droit);
    }

    else if( data[0]==2 && data[1]==5 && data[2]== 0 && data[3]== 3 && data[4]== 4 && data[5]== 1 && data[6]==6 && data[7]==7){
        setEtat(true);
        setType(Croisee);
    }

    else 
    {
        setEtat(false);
        setType(Anormal);
    }
}

void Testeur::affichage()
{

}
