#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

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
    t_artefact* tab;;
};

int main(){

}