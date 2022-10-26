#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

const int N = 6; //est le nombre de question dans un test   
using t_tab = bool[N];

struct t_qcm {
    t_tab reponse;
    string id;
};

void saisie(t_qcm * QCM){
    cout << "id : ";
    cin >> QCM->id;
    for(int i = 0; i < N; i++){
        cout << "Question n°" << i+1 << " reponse :";
        cin >> (QCM->reponse)[i];
    }
}

void correction(t_qcm QCM, t_tab br){
    int note;
    float pourcentage;
    note = 0;
    cout << "etudiant : " << QCM.id << " ";

    for(int i = 0; i < N; i++){
        cout << QCM.reponse[i] << " ";
        if(QCM.reponse[i] == br[i]){
            note = note +2;
        } else {
            note = note - 1;
        }
    }

    pourcentage = (note/N)*100;

    if(pourcentage >= 90){
        cout << "note de " << QCM.id << ": A" << endl;
    } else if(pourcentage >= 80){
        cout << "note de " << QCM.id << ": B" << endl;
    } else if(pourcentage >= 70){
        cout << "note de " << QCM.id << ": C" << endl;
    } else if(pourcentage >= 60){
        cout << "note de " << QCM.id << ": D" << endl;
    } else {
        cout << "note de " << QCM.id << ": F" << endl;
    }
}

int main() {
    t_qcm q;
    saisie(&q);
    t_tab bonne_reponse = {true,false,false,true,true,false};
    correction(q,bonne_reponse);
}

