#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

void creer_vide(int taille, char** tab2Dgrille)
{
  tab2Dgrille = new char*[taille];
  for(int i = 0; i < taille; i++)
  {
    tab2Dgrille[i] = new char[taille];
    
  }
}

void init(int taille, char** tab2Dgrille){
  for(int i = 0; i < taille; i++){
    for(int j = 0; j < taille; j++){
      tab2Dgrille[i][j] = '-';
    }
  }
}

void affichage_vide(int taille, char** tab2Dgrille)
{
  //cout << clear;

  cout << " ";
  for(int k = 1; k <= taille; k++)
  {
    cout << "  " << k << " ";
  }
  cout << endl;

  cout << "  ";
  for(int k = 0; k < taille; k++)
  {
    cout << "---" << " ";
  }
  cout << endl;


  for(int i = 0; i < taille; i++)
  {
    cout << i+1;

    for(int j = 0; j < taille; j++)
    {
      cout << "| " << "  " << tab2Dgrille[i][j];
    }

    cout << "|" << endl;
    cout << "  ";

    for(int i = 0; i < taille; i++)
    {
        cout << "---" << " ";
    }
    cout << endl;
  }

}

void placer(char symb, int posC, int posL, char** tab2Dgrille)
{
  if(tab2Dgrille[posC][posL] = '-')
  {
    tab2Dgrille[posC][posL] = symb; 
  } else {
    cin >> posC;
    cin >> posL;
    placer(symb, posC, posL, tab2Dgrille);
  }
}

void desalloc(int taille, char** tab2D){
  for(int i = 0; i < taille; i++)
{
    delete(tab2D[i]);
}

delete [] tab2D;
}

int main()
{
  int taille;
  char symbole1, symbole2;
  char** tab2Dgrille;


  cout << "Donnez la taille de la grille" << endl;
  cin >> taille;

  cout << "Symbole du joueur 1 : X ou O" << endl;
  cin >> symbole1;

  cout << "Symbole du joueur 2 : X ou O" << endl;
  cin >> symbole2;

  creer_vide(taille, tab2Dgrille);
  init(taille,tab2Dgrille);
  affichage_vide(taille, tab2Dgrille);
  desalloc(taille, tab2Dgrille);
}
