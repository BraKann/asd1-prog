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
    Pour l'algorithme de suppression et de nombre de séance restante, avoir un chainage trié 
    ne change rien.
    Difference entre l'ajout trié et non trié :
        l'ajout trié permet d'ameliorer la complexité spatial en n'ajoutant pas les seance 
        deja existante dans la liste.
        L'ajout trié permet, or du pire cas(seance est la plus grande/ajout en queue), d'obtenir
        une complexité temporelle partiellement lineaire.
*/

//------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

/*
    On peut aussi rajouter un tableau de string representant les jours de la semaine et faciliter l'affichage des seances
    Mais cela augmente la complexité spatial de chaque maillon
    On peut en faire une variable const hors des structures pour limiter la complexité spatial
*/
struct t_seance {
    int numeroSemaine;
    int jourSemaine;
    int heures;
    int minutes;
    t_seance* seanceSuivante;
};

//------------------------------------------------------------------------------------------------


/*
    Retourne un jour de la semaine en cdc en fonction du jourSemaine de la seance
    COmplexité temporelle : O(l) constante
*/
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

//question 5.a
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

//question 5.b
void AffichageSeances(t_seance* tete){
    if(tete == nullptr){
        cout << "Pas de seances prevue"<<endl;
    }else{
        while(tete!=nullptr){
            cout<< "Semaine "<< tete->numeroSemaine << " " << getjourSemaine(tete)<< " " << tete->heures<< "h" << tete->minutes<<endl;
            tete = tete->seanceSuivante;
        }
    }
}

//question 5.c
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

/*
    Fonction qui initialise un type t_seance aleatoire et le renvoie
*/
t_seance* creerSeance(){
    t_seance* seance = new t_seance;

    //Nombre aleatoire entre 1 et le nombre de semaines en un an
    seance->numeroSemaine = 1 + (int)(rand() % (52-1+1)); 
    //Nombre aléatoire entre 1 et 7
    seance->jourSemaine = 1 + (int)(rand() % (7-1+1)); 
    //Nombre aléatoire entre 8 et 18
    seance->heures = 8 + (int)(rand() % (18-8+1));

    //Nombre aléatoire entre 0 et 30
    if((int)(rand() % (1-0+1)) == 0) {
        seance->minutes = 0;
    } else {
        seance->minutes = 30;
    }
    seance->seanceSuivante = nullptr;

    return seance;
}

/*
    Fonction comptant le nombre de minutes total dans une seance pour aider a trié les séances
    COmplexité temporelle : O(l) constante
*/
int nbMinutes(t_seance* tete){
    return (tete->minutes*1  + tete->heures*60 + tete->jourSemaine*1440 + tete->numeroSemaine*10080);
}

/*
    question 6.a
    Procédure ajoutant a la queue une seance crée en entrant les données en paramatre 
    Complexité temporelle : O(n)
*/
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

/*
    question 6.b et 7.a
    Utilisation d'une fonction retournant un boolean pour eviter de parcourir tout la liste pour rien 
    et informer si il y a bien eu suppression. 
    Complexité temporelle : O(n)
*/
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

/*
    question 6.c et 7.a
    Fonction retournant un entier represantant le nombre de séance restante apres une certaine seance entrée en paramatre 
    Complexité temporelle : pire cas O(n²), meilleur cas O(n)
*/
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

/*
    question 6.a et 7.a

    Utilisation d'une fonction retournant un boolean pour eviter de parcourir tout la liste pour rien 
    et informer si il y a bien eu un ajout.
    Ajout trié par ordre croissant.
    les données des seances sont toute transformée en minutes pour otpimiser l'algorithme.

    Complexité temporelle : O(n)
*/
bool ajouterSeanceTrie(t_seance* &tete, int nSem, int jour, int h, int min){
    t_seance* nvSeance =new t_seance;
    t_seance* seaCourante = tete;
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
    //Ajout en tete de liste, si liste vide ou la tete est plus grande que la nouvelle
    if(tete == nullptr || nbMinutes(nvSeance) < nbMinutes(tete)){
        nvSeance->seanceSuivante =tete;
        tete= nvSeance;
        tete=seaCourante->seanceSuivante;
        cout<< "avant"<<endl;
        return true;
    }else{
        while(seaCourante!= nullptr){
            //Ajout en cours de liste
            if(nbMinutes(seaCourante)<= nbMinutes(nvSeance) && nbMinutes(nvSeance) < nbMinutes(seaCourante->seanceSuivante)){
                nvSeance->seanceSuivante = seaCourante->seanceSuivante;
                seaCourante->seanceSuivante = nvSeance;
                return true;
            }
            //Ajout en fin de liste
            if(seaCourante->seanceSuivante == nullptr){
                seaCourante->seanceSuivante = nvSeance;
                nvSeance->seanceSuivante = nullptr;
                
                return true;
            }
            seaCourante=seaCourante->seanceSuivante;
        }
        
    }
    return false;
}

//------------------------------------------------------------------------------------------------

int main(){
    t_seance *sea3= new t_seance;
    *sea3 = {49,3,9,30,nullptr};
    t_seance *sea2= new t_seance;
    *sea2 = {48,2,8,00,sea3};
    t_seance *sea1= new t_seance;
    *sea1 = {47,2,15,00,sea2};
    t_seance* tete;
    tete = sea1;
    cout <<"nombre total de seances: " << totalSeance(tete) <<endl;
    AffichageSeances(tete);
    cout <<endl;
    ajouterSeance(tete,50,4,9,30);
    bool ajout =ajouterSeanceTrie(tete,46,5,10,30);
    if(ajout){cout<<"ajout reussi"<<endl;}
    AffichageSeances(tete);
    cout <<endl;
    bool supp =supprimerSeance(tete,48,2,8,0);
    if(supp){cout<< "suppression reussi"<<endl;}
/*  supprimerSeance(tete,50,4,9,30);
    supprimerSeance(tete,47,2,15,30);
    supprimerSeance(tete,49,3,9,30);
*/ 
    AffichageSeances(tete);
    cout << "nombre de seances apres la premiere seance " << nbSeances(tete,47,2,15,00)<<endl;
    desallocSeances(tete);
    cout << "Affichage apres desallocation" << endl;
    AffichageSeances(tete);
    
    /*
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
    */
}