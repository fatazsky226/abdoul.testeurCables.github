#include <Arduino.h>
#include "Testeur.hpp"


/// @brief 
/// @param pinGauche 
/// @param pinDroite 
/// @param cables 

Testeur::Testeur(int *pinGauche, int *pinDroite)
{   
    for (size_t i = 0; i < 8; i++)
    {
        /* code */
            pinO[i] = pinGauche[i];     // Assignation des broches de sortie
            pinMode(pinO[i], OUTPUT);

            pinI[i] = pinDroite[i];                         // Assignation des broches d'entrée avec résistance de tirage vers le bas
            pinMode(pinI[i], INPUT_PULLDOWN);
    } 
}

/// @brief 
Testeur::~Testeur(){}
/// @brief 
//Cette fonction recherche la première broche active et renvoie sa position
float Testeur::recherche() {                            
        int position = 0;
        for (int i = 0; i < 8; i++)
        {
            /* code */
            int res = digitalRead(pinI[i]);     // Lecture de l'état de la broche d'entrée
                
                if (res == 1)
                {
                    /* Assignation de la position de la broche active et arret de recherche */
                    position = i + 1;
                    break;
                }      
        }
        return position;
}

void Testeur::typeCable(){

    int brocheOut[8] ;
        for (int i = 0; i < 8; i++)
        {
            /* code */
            // Activation de la broche de sortie
            digitalWrite(pinO[i], HIGH);
            brocheOut[i]= recherche();  // Recherche de la broche active connectée
            digitalWrite(pinO[i], LOW);    // Désactivation de la broche de sortie

        }

   if (brocheOut[0] == couleur[0] && brocheOut[1] == couleur[1] && brocheOut[2] == couleur[2] && brocheOut[3] == couleur[3] && brocheOut[4] == couleur[4] && brocheOut[5] == couleur[5] && brocheOut[6] == couleur[6] && brocheOut[7] == couleur[7])
   {
    /* code */
        for (size_t i = 0; i < 8; i++)
        {
            /* code */
            Serial.print( brocheOut[i]);
            Serial.print( "  --------  ");
            Serial.println( couleur[i]);
            
        }
        
    Serial.println("Le cable est Droit");
   }
   
    else if (brocheOut[0] == couleur[2] && brocheOut[1] == couleur[5] && brocheOut[2] == couleur[0] && brocheOut[3] == couleur[3] && brocheOut[4] == couleur[4] && brocheOut[5] == couleur[1] && brocheOut[6] == couleur[6] && brocheOut[7] == couleur[7])
   {
    /* code */
        for (size_t i = 0; i < 8; i++)
        {
            /* code */
            // Affichage du resultat
            Serial.print( brocheOut[i]);
            Serial.print( "  --------  ");
            Serial.println( couleur[i]);
        }
        
    Serial.println("Le cable est Croisé");
   }
   
   else {

    Serial.println("Le cable est Défectueux");
   }

}
