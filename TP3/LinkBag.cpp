/*
  ASD1 - TP n°3 - LINK
*/

#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

//---------------------------------------

struct t_cls_rarete 
{
    string nomRar;
    float facteur;
};

struct t_artefact 
{
    string nomArt;
    int magique;
    int poids;
    int prix;
    int quantité;
    t_cls_rarete* classe;
};

struct t_sac 
{
    int capa;
    int occup;
    t_artefact* tab;
};

//---------------------------------------

t_sac initSac()
{
    t_sac sac;
    sac.capa = 4;
    sac.occup = 0;
    sac.tab = new t_artefact[sac.capa];

    return sac;
}

void augmenterCapaSac(t_sac * sac)
{
    if(sac->occup == (2/3)*sac->capa)
    {
        t_sac tempSac;
        tempSac.capa = sac->capa*2;
        tempSac.tab = new t_artefact[tempSac.capa];
        for(int i = 0; i < sac->occup; i++)
        {
            tempSac.tab[i] = sac->tab[i];
        }
        delete [] sac->tab;
        sac->tab = tempSac.tab;
        sac->capa = tempSac.capa;
    } else {
        cout << "le sac peut encore supporter quelques artefacts !" << endl;
    }
}

void reduireCapaSac(t_sac * sac)
{
    if(sac->occup == (1/6)*sac->capa)
    {
        t_sac tempSac;
        tempSac.capa = sac->capa/2;
        tempSac.tab = new t_artefact[tempSac.capa];
        for(int i = 0; i < sac->occup; i++)
        {
            tempSac.tab[i] = sac->tab[i];
        }
        delete [] sac->tab;
        sac->tab = tempSac.tab;
        sac->capa = tempSac.capa;
    } else {
        cout << "le sac contient trop d'artefacts pour etre reduit !" << endl;
    }
}

void afficheInfoSac(t_sac sac)
{
    cout << "la capacité max du sac est de : " << sac.capa << endl;
    cout << "l'occupation du sac est de : : " << sac.occup << endl;
}

void afficheArtefact(t_artefact art)
{
    cout << art.nomArt << "," << art.magique << " magie" << "," << art.poids << " kg" << "," << "type " << (art.classe)->nomRar<< "," << art.prix << " rupee par pièce" << "," << art.quantité << "pièce(s)" << endl;
}

//ajout si occup<capa*2/3 sinon double puis ajoute 
//l'ajout est trié par magie décroissante
//si art.magie > sac.tab[sac.occup].magie ajout a sac.occup +1 attention a occup<taille*2/3
//sinon cherche sa place puis decaler a droite, faire attention a occup<taille*2/3
void ajouteArtefact(t_sac * sac, t_artefact art)
{
    if()
    {

    } else {

    }
}

//---------------------------------------

int main()
{
    t_sac sac;
    sac = initSac();
    augmenterCapaSac(&sac);
    afficheInfoSac(sac);
    reduireCapaSac(&sac);
    afficheInfoSac(sac);
}