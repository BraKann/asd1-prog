/*
    ---------------------------------------------------------------------
    TP n°4 - Liste Chainée - 2022 - CHIABERGE Christopher, Enzo ?
    ---------------------------------------------------------------------
*/

/* 
    Question n°1
    1.a salut

    1.b C'est une liste chainée

    1.c une autre liste

    Question n°3.a
    On peut penser qu'on aura 6 allocations en comptant celle pour 
    la cellule qui contient le point. Or si on suit l'execution de la fonction
    enregistrement, il est alloué seulement 5 cellules.

    Question n°7.b


*/

//------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

//-------QUESTION N°2-------
struct t_cellule {
    char info;
    t_cellule *suivant;
};

struct t_seance {
    int numeroSemaine;
    int jourSemaine;
    string tabJour[7] = {"lundi","mardi","mercredi","jeudi","vendredi","samedi","dimanche"};
    int heures;
    int minutes;
    t_seance* seanceSuivante;
};

/*
On peut aussi rajouter un tableau de string representant les jours de la semaine et faciliter l'affichage des seances
Mais cela augmente la complexité spatial de chaque maillon
On peut en faire une variable const hors des structures pour limiter la complexité spatial
struct t_seance {
    int numeroSemaine;
    int jourSemaine;
    int heures;
    int minutes;
    t_seance* seanceSuivante;
};
*/

//-----------------------------------------QUESTION N°2-----------------------------------------

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
        cout << lettre;
        pcel = (*pcel).suivant;
    }
    cout << endl;
}

//------------------------------------------------------------------------------------------------
//-----------------------------------------QUESTION N°3.B-----------------------------------------

void desalloc(t_cellule **tete){

    t_cellule *ptrCourant;

    while(*tete != nullptr){
        ptrCourant = *tete;
        *tete = ptrCourant->suivant;
        delete ptrCourant;
    }
    *tete = nullptr;
}

//----------------------------------------------------------------------------------------------
//-----------------------------------------QUESTION N°4-----------------------------------------

t_cellule* chainage(string cdc){

    t_cellule* tete;
    t_cellule *psuiv;
    t_cellule *pcel;

    pcel = new t_cellule;

    tete = pcel;

    for(char c : cdc){
        pcel->info = c;
        psuiv = new t_cellule;
        pcel->suivant = psuiv;
        pcel = psuiv;
    }
    pcel->suivant = nullptr;

    return tete;
}

//------------------------------------------------------------------------------------------------
//-----------------------------------------QUESTION N°5.A-----------------------------------------

int nbSeances(t_seance* seance){
    
    int nbSeances = 0;
    if(seance == nullptr) return nbSeances;

    t_seance* ptrCourant;
    ptrCourant = seance;
    while(ptrCourant->seanceSuivante != nullptr){
        nbSeances++;
        ptrCourant = ptrCourant->seanceSuivante;
    }
    return nbSeances;
}

/*
int totalSeance(t_seance* tete){
    t_seance *seance;
    int nbseance=0;
    if(tete == nullptr){
        return nbseance;
    }else{
        while(tete!=nullptr){
            seance= tete;
            tete = seance->seanceSuivante;
            nbseance++; 
        }
    }
    return nbseance;
}
*/

//-----------------------------------------QUESTION N°5.B-----------------------------------------

void afficheUneSeance(t_seance* seance){
    if(seance != nullptr){
        cout << "Semaine " << seance->numeroSemaine << " " << seance->tabJour[seance->jourSemaine-1] << " " << seance->heures << "h" << seance->minutes << endl;
    } else { 
        cout << "Aucune seance a afficher" << endl;
    }
}

void afficheSeance(t_seance* seance){  

    if(seance != nullptr){
        t_seance* ptrCourant;
        ptrCourant = seance;
        cout << "----------------------------------" << endl;
        cout << "Affichage de la liste chainee :" << endl;
        while(ptrCourant != nullptr){
            afficheUneSeance(ptrCourant);
            ptrCourant = ptrCourant->seanceSuivante;
        }
        cout << "----------------------------------" << endl;
    } else { cout << "Auncunes seances de programmees" << endl; }
}

/*
string getjourSemaine(t_seance* seance){
    switch(seance->jourSemaine){
        case 1: return "Lundi";break;
        case 2: return "Mardi";break;
        case 3: return "Mercredi";break;
        case 4: return "Jeudi";break;
        case 5: return "Vendredi";break;
        case 6: return "Samedi";break;
        case 7: return "Dimanche" ;break;
    }
    cout<<"Pas de jour indique, retourne vide"<<endl;
    return "";
}

void AffichageSeances(t_seance* tete){
    t_seance* seance;
    if(tete == nullptr){
        cout << "Pas de seances prevue"<<endl;
    }else{
        while(tete!=nullptr){
            cout<< "Semaine "<< tete->numeroSemaine << " " << getjourSemaine(tete)<< " " << tete->heures<< "h" << tete->minutes<<endl;
            tete = tete->seanceSuivante;
        }
    }
}
*/

//-----------------------------------------QUESTION N°5.C----------------------------------------

void desallocationSeance(t_seance** seance){
    
    if(seance != nullptr){
        t_seance *ptrCourant;

        while(*seance != nullptr){
            ptrCourant = *seance;
            *seance = ptrCourant->seanceSuivante;
            delete ptrCourant;
        }
        seance = nullptr;
        cout << "Desallocation effectuer" << endl;
    } else { cout << "Aucune seance a supprimer" << endl; }
}

/*
void desallocSeances(t_seance* &tete){
    t_seance *seaCourante;
    if(tete==nullptr){
        cout<< "pas de desallocation"<<endl;
    }else{
        while(tete!=nullptr){
            seaCourante = tete;
            tete =seaCourante->seanceSuivante;
            delete seaCourante;
        }
        tete = nullptr;
    }
    
}
*/

//------------------------------------------------------------------------------------------------

//fonction initialise un t_seance aleatoire et le renvoi
t_seance* creerSeance(){

    t_seance* seance = new t_seance;

    seance->numeroSemaine = 1 + (int)(rand() % (52-1+1)); //nbr aleatoire entre 1 et nbr de semaine en un an
    seance->jourSemaine = 1 + (int)(rand() % (7-1+1)); //nbr aleatoire entre 1 et 7
    seance->heures = 8 + (int)(rand() % (18-8+1)); //nbr aletoire entre 8 et 18

    if((int)(rand() % (1-0+1)) == 0) {
        seance->minutes = 0;
    } else {
        seance->minutes = 30;
    }
    seance->seanceSuivante = nullptr;

    return seance;
}

//------------------------------------------------------------------------------------------------
//-----------------------------------------QUESTION N°6.A-----------------------------------------

void ajoutSeance(t_seance** tete){
    t_seance* nouvelleSeance;
    t_seance* ptrCourant;
    nouvelleSeance = creerSeance();
    ptrCourant = *tete;
    if(*tete == nullptr){
        *tete = nouvelleSeance;
    } else {
        while(ptrCourant->seanceSuivante != nullptr){
            ptrCourant = ptrCourant->seanceSuivante;
        }
        ptrCourant->seanceSuivante = nouvelleSeance;
        nouvelleSeance->seanceSuivante = nullptr;
    }
    cout << "Ajout de la seance : " ;
    afficheUneSeance(nouvelleSeance);
}

/*
//question 6.a
void ajouterSeance(t_seance* tete, int nSem, int jour, int h, int min){
    t_seance* nvSeance =new t_seance;
    t_seance* seaCourant = tete;
    while(nSem<0 || nSem > 53){
    cout << "Numero de semaine >0 ?" << endl;
    cin >> nSem;
    }
    while(jour <1 || jour>8){
        cout << "Jour entre 1 et 7 ?" << endl;
        cin >> jour;
    }
    while(h<8 || h>18){
        cout << "Heure entre 8 et 18 ?" << endl;
        cin >> h;
    }
    while(min != 0 && min !=30){
        cout << "Minutes soit 0 soit 30 ?" << endl;
        cin >> min;
    }
    nvSeance->numeroSemaine=nSem;
    nvSeance->jourSemaine=jour;
    nvSeance->heures=h;
    nvSeance->minutes=min;

    while(seaCourant->seanceSuivante!=nullptr){
        seaCourant=seaCourant->seanceSuivante;
    }
    seaCourant->seanceSuivante = nvSeance;
    nvSeance->seanceSuivante = nullptr;
}
*/

//-----------------------------------------QUESTION N°6.B/7.A-----------------------------------------

//Utilisation d'une fonction retournant un boolean pour eviter de parcourir tout le programme pour rien 
//et informer si il y a bien eu suppression. 
bool supprimerSeance(t_seance* &tete,int nSem,int jour,int h, int min){
    t_seance* seaAvant = tete;
    t_seance* seaCourant = seaAvant->seanceSuivante;
    if((seaAvant->numeroSemaine==nSem) && (seaAvant->jourSemaine=jour)
        && (seaAvant->heures==h) && (seaAvant->minutes==min)){
        tete=tete->seanceSuivante;
        delete seaAvant;
        return true;
    }else {
        while(seaCourant->seanceSuivante != nullptr){
            if((seaCourant->numeroSemaine==nSem) && (seaCourant->jourSemaine=jour)
            && (seaCourant->heures==h) && (seaCourant->minutes==min)){
                seaAvant->seanceSuivante=seaCourant->seanceSuivante;
                delete seaCourant;
                seaCourant = seaAvant->seanceSuivante;
                return true;
            }else{
                seaAvant = seaAvant->seanceSuivante;
                seaCourant=seaCourant->seanceSuivante;
                if((seaCourant->seanceSuivante== nullptr) &&(seaCourant->numeroSemaine==nSem) && (seaCourant->jourSemaine=jour)
                && (seaCourant->heures==h) && (seaCourant->minutes==min)){
                    delete seaCourant;
                    seaAvant->seanceSuivante = nullptr;
                    return true;
                }
            }
        }
    }
    return false;
}

//-----------------------------------------QUESTION N°6.C/7.A---------------------------------------

/*
//Question 6.c et 7.a
int nbSeances(t_seance* tete,int nSem,int jour,int h, int min){
    t_seance* seaCourant = tete;
    if(tete==nullptr){
        return 0;
    }else{
        while(seaCourant!=nullptr){
            if((seaCourant->numeroSemaine==nSem) && (seaCourant->jourSemaine=jour)
            && (seaCourant->heures==h) && (seaCourant->minutes==min)){
                return totalSeance(seaCourant)-1;  
            }
            seaCourant = seaCourant->seanceSuivante;
        }
    }
    return 0;
}
*/

//------------------------------------------------------------------------------------------------
//-----------------------------------------QUESTION N°7.A/6.A-------------------------------------

bool ajoutTri(t_seance** seance){
    bool estAjouter_ = false;
    t_seance* nouvelleSeance;
    t_seance* ptrCourant;
    t_seance* temp;
    nouvelleSeance = creerSeance();
    if(*seance == nullptr){
        *seance = nouvelleSeance;
    } else {
        ptrCourant = *seance;
        while(ptrCourant->seanceSuivante != nullptr){
            if((ptrCourant->seanceSuivante)->numeroSemaine > nouvelleSeance->numeroSemaine){
                if(ptrCourant->numeroSemaine > nouvelleSeance->numeroSemaine){
                    nouvelleSeance->seanceSuivante = ptrCourant;
                    ptrCourant = *seance;
                    estAjouter_ = true;
                    return estAjouter_;
                } else {
                    nouvelleSeance->seanceSuivante = ptrCourant->seanceSuivante;
                    ptrCourant->seanceSuivante = nouvelleSeance;
                    estAjouter_ = true;
                    return estAjouter_;
                }
            } else if(ptrCourant->numeroSemaine == nouvelleSeance->numeroSemaine){
                if((ptrCourant->seanceSuivante)->jourSemaine > nouvelleSeance->jourSemaine){
                    if(ptrCourant->jourSemaine > nouvelleSeance->jourSemaine){
                        nouvelleSeance->seanceSuivante = ptrCourant;
                        ptrCourant = *seance;
                        estAjouter_ = true;
                        return estAjouter_;
                    } else {
                        nouvelleSeance->seanceSuivante = ptrCourant->seanceSuivante;
                        ptrCourant->seanceSuivante = nouvelleSeance;
                        estAjouter_ = true;
                        return estAjouter_;
                    }
                    //ajout
                } else if(ptrCourant->jourSemaine == nouvelleSeance->numeroSemaine){
                    if((ptrCourant->seanceSuivante)->heures > nouvelleSeance->heures){
                        if(ptrCourant->heures > nouvelleSeance->heures){
                            nouvelleSeance->seanceSuivante = ptrCourant;
                            ptrCourant = *seance;
                            estAjouter_ = true;
                            return estAjouter_;
                        } else {
                            nouvelleSeance->seanceSuivante = ptrCourant->seanceSuivante;
                            ptrCourant->seanceSuivante = nouvelleSeance;
                            estAjouter_ = true;
                            return estAjouter_;
                        }
                    //ajout
                    } else if(ptrCourant->heures == nouvelleSeance->heures){
                        if((ptrCourant->seanceSuivante)->minutes > nouvelleSeance->minutes){
                            if(ptrCourant->minutes > nouvelleSeance->minutes){
                                nouvelleSeance->seanceSuivante = ptrCourant;
                                ptrCourant = *seance;
                                estAjouter_ = true;
                                return estAjouter_;
                            } else {
                                nouvelleSeance->seanceSuivante = ptrCourant->seanceSuivante;
                                ptrCourant->seanceSuivante = nouvelleSeance;
                                estAjouter_ = true;
                                return estAjouter_;
                            }
                        }
                    }
                }
            }
        ptrCourant->seanceSuivante = nouvelleSeance;
        nouvelleSeance->seanceSuivante = nullptr;
        }
    }
    return estAjouter_;
}

//------------------------------------------------------------------------------------------------
//-----------------------------------------QUESTION N°8-------------------------------------------


//------------------------------------------------------------------------------------------------

int main(){

    t_cellule *pcel;
    pcel = enregistrement();
    affiche(pcel);
    desalloc(&pcel);
    affiche(pcel);

    //---------------------------

    string ch = "ok";
    pcel = chainage(ch);
    affiche(pcel);
    desalloc(&pcel);

    //---------------------------
    
    t_seance* seance;
    seance = nullptr;

    afficheUneSeance(seance);

    ajoutSeance(&seance);
    afficheSeance(seance);

    ajoutSeance(&seance);
    afficheSeance(seance);

    ajoutSeance(&seance);
    afficheSeance(seance);

    desallocationSeance(&seance);

/*
    t_seance *sea3= new t_seance;
    *sea3 = {49,3,9,30,nullptr};
    t_seance *sea2= new t_seance;
    *sea2 = {48,2,8,0,sea3};
    t_seance *sea1= new t_seance;
    *sea1 = {47,2,15,30,sea2};
    t_seance* tete;
    tete = sea1;
    cout <<"nombre total de seances: " << totalSeance(tete) <<endl;
    AffichageSeances(tete);
    cout <<endl;
    ajouterSeance(tete,50,4,9,30);
    AffichageSeances(tete);
    cout <<endl;
    bool supp =supprimerSeance(tete,48,2,8,0);
    if(supp){cout<< "suppression reussi"<<endl;}
    supprimerSeance(tete,50,4,9,30);
    supprimerSeance(tete,47,2,15,30);
    supprimerSeance(tete,49,3,9,30);

    AffichageSeances(tete);
    cout << "nombre de seances apres la premiere seances " << nbSeances(tete,47,2,15,30)<<endl;
    desallocSeances(tete);
    //Affichage apres desallocation (aucun affichage)
    AffichageSeances(tete);
*/
}