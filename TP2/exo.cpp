#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
#include <fstream>

struct Note {
    int nbQuestions;
    char* reponses;
    char note; 
};

struct Classe {
    int nbMax;
    int nbEleve;
    string* etu;
    Note* noteEtu;
};

void initNote(Note* n){
    cin >> n->nbQuestions;
    n->reponses = new char[n->nbQuestions];

    for(int i = 0; i < n->nbQuestions; i++){
        int k = random() % 2;
        if(k == 0){
            n->reponses[i] = ' ';
        } else if(k == 1){
            n->reponses[i] = 'T';
        } else {
            n->reponses[i] = 'F';
        }
    }

    n->note = 'A';

}

void initClasse(Classe* c){
    cin >> c->nbMax;
    c->nbEleve = 0;
    
    c->etu = new string[c->nbMax];
}

int main() {
    Note F1;
    Classe C1;



}