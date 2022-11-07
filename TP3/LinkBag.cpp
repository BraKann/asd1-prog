/*
  ASD1 - TP n°3 - LINK - Christopher CHIABERGE - Pape TOURE - 385K
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
    int quantite;
    t_cls_rarete* classe;
};

struct t_sac 
{
    int capa;
    int occup;
    t_artefact* tab;
};

//---------------------------------------

/*
    initialise une variable de type t_sac et la retourne
*/
t_sac initSac()
{
    t_sac sac;
    sac.capa = 4;
    sac.occup = 0;
    sac.tab = new t_artefact[sac.capa];

    return sac;
}

/*
    augmente la taille de la capacité max du sac de link si l'occupation atteint 2/3 de son maximum
    le if pourrait etre enlever car la verification se fait avant l'appel de augmenterCapaSac dans ajouterArtefact
*/
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
        cout << "le sac a été augmenter" << endl;
    } else {
        cout << "le sac peut encore supporter quelques artefacts !" << endl;
    }
}

/*
    reduit la taille de la capacité max du sac de link si l'occupation atteint 1/6 de son maximum
    le if pourrait etre enlever car la verification se fait avant l'appel de reduireCapaSac dans supprimerArtefact
*/
void reduireCapaSac(t_sac * sac)
{
    if(sac->occup <= (1/6)*sac->capa)
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
        cout << "le sac a été reduit" << endl;
    } else {
        cout << "le sac contient trop d'artefacts pour etre reduit !" << endl;
    }
}

/*
    affiche la capacité et l'occupation actuelle du sac
*/
void afficheInfoSac(t_sac sac)
{
    cout << "la capacité max du sac est de : " << sac.capa << endl;
    cout << "l'occupation du sac est de : : " << sac.occup << endl;
}

/*
    affiche les informations qui constitue un artefact 
*/
void afficheArtefact(t_artefact art)
{
    cout << art.nomArt << "," << art.magique << " magie" << "," << art.poids << " kg" << "," << "type " << (art.classe)->nomRar<< "," << art.prix << " rupee par pièce" << "," << art.quantite << "pièce(s)" << endl;
}

/*
    affiche les informations de tout les artefacts du sac 
*/
void afficheLesArtefacts(t_sac sac)
{
    if(sac.occup != 0)
    {
        for(int i = 0; i < sac.occup; i++)
        {
            cout << "Emplacement " << i+1 << " : ";
            afficheArtefact(sac.tab[i]);
            cout << endl;
        }
    } else {
        cout << "Le sac est vide" << endl;
    }
}

/*
    cherche a partir du nom d'un artefact, sa quantité dans le sac 
*/
void quantiteArtefact(string nomArt, t_sac sac)
{
    int it = 0;

    if(sac.occup != 0) 
    {
        while( ((sac.tab[it]).nomArt != nomArt) && (it <= sac.occup) ){
            it++;
        }
        if( it > sac.occup) {
            cout << "Quantité : " << nomArt << " = 0" << endl;
        } else {
            cout << "Quantité : " << nomArt << " = " << (sac.tab[it]).quantite << endl;
        }
    }

    cout << " le sac ne contient pas d'artefact" << endl;
}

/*
    Creer un artefact en passant par l'utilisateur et le retourne
*/
t_artefact creerArtefact()
{
    t_artefact art;

    cout << "Creer votre artefact" << endl;

    cout << "nom : ";
    cin >> art.nomArt;
    cout << endl << "puissance magique (1-100) : ";
    cin >> art.magique;
    cout << endl << "poids : ";
    cin >> art.poids;
    cout << endl << "prix : ";
    cin >>  art.prix;
    cout << endl << "quantité : ";
    cin >> art.quantite;

    cout << endl << "classe de raretée : ";
    cin >> (art.classe)->nomRar;
    cout << endl << "facteur de raretée : ";
    cin >> (art.classe)->facteur;


    return art;
}

//A REFAIRE RIEN NE VAS
//ajout si occup<capa*2/3 sinon double puis ajoute 
//l'ajout est trié par magie décroissante
//si art.magie > sac.tab[sac.occup].magie ajout a sac.occup +1 attention a occup<taille*2/3
//sinon cherche sa place puis decaler a droite, faire attention a occup<taille*2/3
void ajouteArtefact(t_sac * sac, t_artefact art)
{
    int it = 0;

    if(sac->occup == 0) {
        sac->tab[0] = art;
        sac->occup++;
    } 
    else if(art.magique < sac->tab[sac->occup-1].magique)
    {
        sac->tab[sac->occup] = art;
        sac->occup++;
        if(sac->occup >= (2/3)*sac->capa)
        {
            augmenterCapaSac(sac);
        }        
    } else {
        if(sac->occup < (2/3)*sac->capa){
            while(art.magique < sac->tab[it].magique){
                it++;
            }
            for(int i = sac->occup; i >= it; i--){
                sac->tab[i+1] = sac->tab[i];
            }
            sac->tab[it] = art;
            sac->occup++;
            if(sac->occup >= (2/3)*sac->capa)
            {
                augmenterCapaSac(sac);
            }      
        } else {
            augmenterCapaSac(sac);
            while(art.magique < sac->tab[it].magique){
                it++;
            }
            for(int i = sac->occup; i >= it; i--){
                sac->tab[i+1] = sac->tab[i];
            }
            sac->tab[it] = art;
            sac->occup++;
        }
    }
    cout << "L'artefact a été ajouté" << endl;
}

/*
    Supprime un artefact du sac de link en donnant son nom
    Supprimer en passant la quantité a zero 
    Ou
    Supprimer en réallouant un tableau sans l'artefacte donc effectuer 
    un décallage dans le tableau pour garder l'ordre
*/
bool supprimerArtefact(t_sac* sac, string art_nom)
{
    bool est_retirer = false;
    int it = 0;
    t_sac temp;
    
    while((sac->tab[it]).nomArt != art_nom && it < sac->occup){
        it++;
    }

    if(it = sac->occup && sac->tab[it].nomArt == art_nom )
    {
        temp.capa = sac->capa;
        temp.tab = new t_artefact[temp.capa];
        for(int i = 0; i < sac->occup-1; i++)
        {
            temp.tab[i] = sac->tab[i];
            temp.occup++;
        }
        delete [] sac->tab;
        sac->tab = temp.tab;
        sac->occup = temp.occup;
        est_retirer = true;     
    } 
    else if(sac->tab[it].nomArt == art_nom) 
    {
        temp.capa = sac->capa;
        temp.tab = new t_artefact[temp.capa];
    
        for(int i = 0; i < it; i++)
        {
            temp.tab[i] = sac->tab[i];
            temp.occup++;
        }
        for(int i = it+1; i < sac->occup; i++)
        {
            temp.tab[i-1] = sac->tab[i];
            temp.occup++;   
        }
        delete [] sac->tab;
        sac->tab = temp.tab;
        sac->occup = temp.occup;
        est_retirer = true;
    } else {
        cout << "L'artefact ne peut pas etre supprimer car il n'est pas dans le sac" << endl;
        return est_retirer;
    }
    
    if(sac->occup <= (1/6)*sac->capa) 
    {
        reduireCapaSac(sac);
    }

    cout << "L'artefact a été supprimer du sac" << endl;
    return est_retirer;
}

/*
    retourne la valeur en rupee de vente des artefacts compris dans le sac
*/
int valeurTotaleVente(t_sac sac)
{
    int prixTotale = 0;
    for(int i = 0; i < sac.occup; i++)
    {
        prixTotale = (((sac.tab[i]).classe)->facteur) * ((sac.tab[i]).prix);
    }
    return prixTotale;
}

//si sac non vide et si le premier element = le second alors appele de la fonction d'egalité
//sinon retorune le premier artefact du tableau car il est supposer trié par ordre decroissant de pouvoir magique
t_artefact maxForceMagique(t_sac sac)
{
    return sac.tab[0];
}

//creer un tableau de n art qui on la meme force magique et le renvoie 
t_artefact* egaliteForceMagique(t_sac sac)
{

}

/*
    suite d'appel de fonction qui suivent le scénario demander en page 1 du TP
*/
void scenario()
{
    t_sac sac = initSac();
    t_artefact art1 = creerArtefact();

    afficheInfoSac(sac);
    afficheArtefact(art1);

    ajouteArtefact(&sac,art1);
    afficheInfoSac(sac);

    quantiteArtefact(art1.nomArt, sac);

    afficheLesArtefacts(sac);

    valeurTotaleVente(sac);

    maxForceMagique(sac);

    supprimerArtefact(&sac, art1.nomArt);
    afficheInfoSac(sac);
    quantiteArtefact(art1.nomArt, sac);

    afficheLesArtefacts(sac);

    delete [] sac.tab;
}

//---------------------------------------

int main()
{
    scenario();
}