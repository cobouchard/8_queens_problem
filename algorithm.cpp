#include "plateau.h"
#include <stdlib.h>
#include <time.h>


void Plateau::randomPlateau()
{
    srand (time(NULL));
    std::vector<int> lignes={0,1,2,3,4,5,6,7};
    std::vector<int> colonnes={0,1,2,3,4,5,6,7};
    for(int i(0); i!=8;i++)
    {
        int poX=rand()%(lignes.size());
        int poY=rand()%(colonnes.size());
        int x = lignes[poX];
        int y = colonnes[poY];
        ajouterDame(x,y);
        lignes.erase(lignes.begin()+poX);
        colonnes.erase(colonnes.begin()+poY);
    }


}


void Plateau::equilibrage()
{
    int a(getEquilibre());
    std::vector<Plateau::Dame> dames;

    while(a!=0)
    {


        if(a>0)
        {
           dames = getCouple(1);
           swapDames(dames[0],dames[1]);
        }
        else
        {
            dames = getCouple(0);
            swapDames(dames[0],dames[1]);
        }
        a = getEquilibre();
        dames.clear();
    }
}

void Plateau::algo()
{
    equilibrage();

    for(int i(0); i!=1000 && getNbCollides()!=0;i++)
    {
        for(Plateau::Dame d : lesDames)
        {
            std::vector<Plateau::Dame> lesCollis = getCollision(d);
            if(lesCollis.size()==0)
                continue;
            else
            {
                std::vector<Plateau::Dame> tempVect;
                for(Plateau::Dame d1 : lesDames)
                {
                    if(d.posX==d1.posX && d.posY==d1.posY)
                        continue;
                    else
                    {
                        if(getCouleur(d1)!=getCouleur(d))
                            tempVect.push_back(d1);
                    }
                }

                swapDames(d,tempVect[0]);
                nbChange++;
            }
        }
    }
}
