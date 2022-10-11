#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

void creer_vide(int taille, char** tab2Dgrille)
{
  tab2Dgrille = new char*[taille];
  for(int i = 0; i < taille; i++)
  {
    char* tab2Dgrille = new char[taille];
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
  for(int k = 1; k <= taille; k++)
  {
    cout << "---" << " ";
  }
  cout << endl;


  for(int i = 1; i <= taille; i++)
  {
    cout << i;

    for(int j = 1; j <= taille; j++)
    {
      cout << "| " << "  " ;
    }

    cout << "|" << endl;
    cout << "  ";

    for(int i = 1; i <= taille; i++)
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
  affichage_vide(taille, tab2Dgrille);

}
