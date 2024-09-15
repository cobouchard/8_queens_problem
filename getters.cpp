#include "plateau.h"
#include <iostream>


int Plateau::getNbCollides()
{
    int somme=0;
    for(Plateau::Dame d : lesDames)
    {
        somme+=getCollision(d).size();
    }
    return somme;
}

bool Plateau::getCouleur(Plateau::Dame d)
{
    if((d.posX+d.posY)%2==0)
        return 0;

    else
        return 1;
}

int Plateau::getIndexDame(Plateau::Dame dame)
{
    int posX = dame.posX; int posY = dame.posY;

    for(int i(0); i!=lesDames.size();i++)
    {
        if(posX==lesDames[i].posX && posY==lesDames[i].posY)
            return i;
    }

    return 12345;
}

Plateau::Dame Plateau::getDame(int posX,int posY)
{

    for(int i(0); i!=lesDames.size();i++)
    {
        if(posX==lesDames[i].posX && posY==lesDames[i].posY)
            return lesDames[i];
    }

}

std::vector<Plateau::Dame> Plateau::getCollision(Plateau::Dame dame)
{
    int x(dame.posX); int y(dame.posY);
    std::vector<Plateau::Dame> dames;
    int k(y-x); int k1(y+x);

    for(Plateau::Dame d : lesDames)
    {
        if(d.posX==dame.posX && d.posY==dame.posY)
            continue;
        if(d.posY-d.posX==k || d.posX+d.posY==k1)
            dames.push_back(d);
    }
    return dames;
}

std::vector<Plateau::Dame> Plateau::getCouple(bool couleur)
{
    std::vector<Plateau::Dame> couple;
    for(int i(0);couple.size()!=2; i++)
    {
        if(getCouleur(lesDames[i])==couleur)
        {
            if(couple.size()==1)
            {
                if(std::abs(couple[0].posX-lesDames[i].posX)%2==1)
                {
                    couple.push_back(lesDames[i]);
                }
            }
            else
            {
                couple.push_back(lesDames[i]);
            }
        }
    }

    return couple;

}

bool Plateau::isDame(int posX, int posY)
{
    return Tableau[posX][posY];
}

int Plateau::getEquilibre()
{
    int balance=0;

    for(Plateau::Dame d : lesDames)
    {
        balance+=getCouleur(d);
    }

    return balance-4;
}
