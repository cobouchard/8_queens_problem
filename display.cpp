#include "plateau.h"
#include <iostream>

void Plateau::affichePlateau()
{
    for(int i=0;i !=8; i++)
    {
        for(int k=0;k !=8; k++)
        {
            std::cout << this->Tableau[i][k];
        }

        std::cout << '\n';
    }

    std::cout << '\n';
}

void Plateau::affichePlateau(bool tab[8][8])
{
    for(int i=0;i !=8; i++)
    {
        for(int k=0;k !=8; k++)
        {
            std::cout << tab[i][k];
        }

        std::cout << '\n';
    }
}




void Plateau::afficheDames(std::vector<Plateau::Dame> dames)
{
    for(Plateau::Dame d : dames)
    {
        std::cout << d.posX << ',' << d.posY << '\n';
    }
}
