#include "plateau.h"
#include <iostream>


Plateau::Plateau()
{
    nbChange=0;
    double somme(0);

    int max(0);
    int min(100000);

    int nb_iter(100);

    for(int i(0); i!=nb_iter; i++)
    {
        nbChange=0;
        initTableau();
        lesDames.clear();
        randomPlateau();


        algo();
        if(nbChange>max)
            max = nbChange;

        if(nbChange<min)
            min = nbChange;
        somme+=nbChange;

        affichePlateau();
   }

    std::cout << somme/nb_iter << '\n';

    std::cout << "Le max est : " << max << '\n'; std::cout << "Le min est : " << min << '\n';
}


void Plateau::initTableau()
{
    for(int i=0; i!=8; i++)
        for(int k=0; k!=8; k++)
            Tableau[i][k]=false;
}






