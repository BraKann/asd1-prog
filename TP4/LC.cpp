/* Question n°1
    1.a salut

    1.b C'est une liste chainée

    1.c une autre liste

    Question n°3.a
    On peut penser qu'on aura 6 allocations en comptant celle pour 
    la cellule qui contient le point. Or si on suit l'execution de la fonction
    enregistrement, il est alloué seulement 5 cellules.
*/

#include <iostream>
using namespace std;
struct t_cellule {
    char info;
    t_cellule *suivant;
};

t_cellule* enregistrement(){
    char lettre;
    t_cellule *pcel;
    t_cellule *psuiv;
    t_cellule *tete;

    cout << "une lettre ? (un point pour terminer)"<<endl;
    cin >> lettre;
    pcel = new t_cellule;
    // ........................... début de la liste
    tete = pcel;

    while(lettre != '.'){
        (*pcel).info = lettre;
        psuiv = new t_cellule;
        (*pcel).suivant = psuiv;
        cout <<"une lettre ? (un point pour terminer)"<<endl;
        cin >> lettre;
        pcel= psuiv;
    }
    // ........................... mémorisation du point final
    (*pcel).info = lettre;
    // ........................... terminaison de la liste
    (*pcel).suivant = nullptr;

    return tete;
}

void affiche(t_cellule *pdeb){
    char lettre;
    t_cellule *pcel;

    pcel = pdeb;
    while(pcel != nullptr){
        lettre = (*pcel).info;
        cout<<lettre;
        pcel = (*pcel).suivant;
    }
    cout<<endl;
}
void desalloc(t_cellule **tete){
    t_cellule *ptrCourant;
    while( *tete != nullptr){
        ptrCourant = *tete;
        *tete = ptrCourant->suivant;
        delete ptrCourant;
    }
    *tete = nullptr;
}

t_cellule chainage(string cdc){
    t_cellule *tete = new t_cellule;
    (*tete).info = cdc[0];
    int i = 0;
    while(cdc[i] != ' '){
        i++;
    }
    for(int j=0;j<i;j++){

    }
}

int main(){
    t_cellule *pcel;
    pcel = enregistrement();
    affiche(pcel);
    desalloc(&pcel);
    affiche(pcel);
}