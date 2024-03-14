#ifndef TESTEUR_H
#define TESTEUR_H


class Testeur
{

    private:
        /* data */

        int pinI[8];    // tableau des Entrées de signal pour chaque couleur 

        int pinO[8];    // tableau des sorties de signal pour chaque couleur

        /// @brief 

        const int couleur[8]={1, 2, 3, 4, 5, 6, 7, 8}; // Numerotation des couleur selon un branchement de cable Droit par défaut
        
    public:
        /// @brief 
        /// @param pinGauche 
        /// @param pinDroite 
        
        Testeur(int * pinGauche, int * pinDroite);

        ~Testeur(); // Destructeur 

        float recherche(); 

       // Fonction qui teste le cable et le type du cable
        void typeCable();
};

#endif     //TESTEUR_HPP
