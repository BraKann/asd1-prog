#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
#include <fstream>

struct Etudiant
{
    string* reponses;
    string id;
    int note;
};

struct Fichier_note 
{
    int nbMaxEtu;
    int nbQuestions;
    string* bonne_reponse;
    Etudiant* etu; 
};

void initEtu(Etudiant* e)
{
    

}

void initNote(Fichier_note* f){

    cin >> f->nbQuestions; //remplacer par un var. alea entre 1 et 40
    cin >> f->nbMaxEtu; //remplacer par un var. alea entre 1 et 40

    f->reponses = new string[f->nbMaxEtu];
    for(int i = 0; i < f->nbMaxEtu; i++)
    {
        string note = "";
        for(int j = 0; j < f->nbQuestions; j++)
        {
            int k = rand() % 2;
            if(k == 0){
                note += ' ';
            } else if(k == 1){
                note += 'T';
            } else {
                note += 'F';
            }
        }
        f->reponses[i] = note;
    }
    
    f->etu = new string[f->nbMaxEtu];

}


int main() {

    Fichier_note F1;
    



}