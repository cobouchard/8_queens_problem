#include "plateau.h"

bool Plateau::ajouterDame(int posX, int posY)
{
    if (Tableau[posX][posY])
        return false;
    else
    {
        Tableau[posX][posY]=true;
        Plateau::Dame temp;
        temp.posX=posX;
        temp.posY=posY;
        this->lesDames.push_back(temp);
        return true;
    }
}

void Plateau::enleverDame(Plateau::Dame dame)
{
    int index(Plateau::getIndexDame(dame));
    this->lesDames.erase(lesDames.begin()+index);
    Tableau[dame.posX][dame.posY]=false;
}

void Plateau::swapDames(Plateau::Dame dame1, Plateau::Dame dame2)
{

    int x1 = dame1.posX, y1 = dame1.posY;
    int x2 = dame2.posX, y2 = dame2.posY;
    enleverDame(dame1); enleverDame(dame2);
    ajouterDame(x1,y2);
    ajouterDame(x2,y1);

}
