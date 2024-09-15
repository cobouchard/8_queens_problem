#ifndef PLATEAU_H
#define PLATEAU_H

#include "vector"

class Plateau
{


public:

    struct Dame
    {
        int posX;
        int posY;
    };

    //initialization (plateau.cpp

    void initTableau();
    Plateau();

    //getters

    int getNbCollides();
    int getIndexDame(Dame dame);
    bool getCouleur(Dame d);
    std::vector<Dame> getCouple(bool couleur);
    Dame getDame(int posX,int posY);
    std::vector<Dame> getCollision(Dame dame);
    bool isDame(int posX, int posY);
    int getEquilibre();

    //display

    void affichePlateau();
    void affichePlateau(bool tab[8][8]);
    void afficheDames(std::vector<Dame> dames);

    //movement

    bool ajouterDame(int posX, int posY);
    void enleverDame(Dame dame);
    void swapDames(Dame dame1, Dame dame2);

    //algorithm

    void algo();
    void equilibrage();
    void randomPlateau();



private :

    bool Tableau[8][8];
    std::vector<Plateau::Dame> lesDames;
    int nbChange;



};




#endif // PLATEAU_H
