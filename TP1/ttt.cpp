#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

void creer_vide(int taille, char **&tab2Dgrille)
{
  tab2Dgrille = new char*[taille];
  for(int i = 0; i < taille; i++)
  {
    tab2Dgrille[i] = new char[taille];
    
  }
}

void init(int taille, char **&tab2Dgrille){
  for(int i = 0; i < taille; i++)
  {
    for(int j = 0; j < taille; j++)
    {
      tab2Dgrille[i][j] = '-';
    }
  }
}

void affichage_vide(int taille, char **&tab2Dgrille)
{
  system("CLS");

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
      cout << "|" << " " << tab2Dgrille[i][j] << " ";
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

void placer(int taille, char symb, char **&tab2Dgrille)
{
  int posL, posC;
  cout << endl << "inserez pos pour ligne : ";
  cin >> posL;
  cout << "inserez pos pour colonne : ";
  cin >> posC;
  if(tab2Dgrille[posL-1][posC-1] == '-')
  {
    tab2Dgrille[posL-1][posC-1] = symb; 
  } else {
    cout << endl << "inserez nouvelle pos pour ligne : ";
    cin >> posL;
    cout << "inserez nouvelle pos pour colonne : ";
    cin >> posC;
    placer(taille, symb, tab2Dgrille);
  }
  affichage_vide(taille, tab2Dgrille);
}

void desalloc(int taille, char **&tab){
  for(int i = 0; i < taille; i++)
{
    delete [] tab[i];
}

delete[] tab;
}

int main()
{
  int taille;
  char symbole1, symbole2;
  char **tab2D;


  cout << "Donnez la taille de la grille" << endl;
  cin >> taille;

  cout << "Symbole du joueur 1 : X ou O" << endl;
  cin >> symbole1;

  cout << "Symbole du joueur 2 : X ou O" << endl;
  cin >> symbole2;

  creer_vide(taille, tab2D);
  init(taille,tab2D);

  affichage_vide(taille, tab2D);
  placer(taille, symbole1, tab2D);
  placer(taille, symbole1, tab2D);

  desalloc(taille, tab2D);
}