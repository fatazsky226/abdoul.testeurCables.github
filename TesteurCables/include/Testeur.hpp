#ifndef TESTEUR_H
#define TESTEUR_H


class Testeur
{
private:
    /* data */
    // variable en sortie
    int * pinDroit ;
    int * pinGauche;
    bool etat;

    enum type_Cable{Droit, Croisee, Anormal};

    type_Cable type;
    
    	
        /*int or1;
		int ob1;
		int vt1;
		int vb1;
		int bu1;
		int bb1;
		int mr1;
		int mb1;*/
    
    // variable en entrée
   /*     int or2;
		int ob2;
		int vt2;
		int vb2;
		int bu2;
		int bb2;
		int mr2;
		int mb2;*/
public:
    Testeur(int * pinDroiteCable, int * pinGaucheCable, bool etat_ , type_Cable cables);
    ~Testeur();
    void initialisation();
    void affichage();
    void typeCable();
};

#endif