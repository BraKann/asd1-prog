#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

void creer_vide(int taille, char **&tab2D)
{
  tab2D = new char*[taille];
  for(int i = 0; i < taille; i++)
  {
    tab2D[i] = new char[taille];
    
  }
}

void init(int taille, char **&tab2D){
  for(int i = 0; i < taille; i++)
  {
    for(int j = 0; j < taille; j++)
    {
      tab2D[i][j] = '-';
    }
  }
}

void affichage(int taille, char **&tab2D)
{
  system("clear");

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
      cout << "|" << " " << tab2D[i][j] << " ";
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

void placer(int taille, char symb, char **&tab2D)
{
  int posL, posC;

  cout << endl << "inserez une position de ligne : ";
  cin >> posL;
  cout << "inserez une position de colonne : ";
  cin >> posC;

  if(tab2D[posL-1][posC-1] == '-')
  {
    tab2D[posL-1][posC-1] = symb; 
  } else {
    cout << endl << "inserez une nouvelle position de ligne : ";
    cin >> posL;
    cout << "inserez une nouvelle position de colonne : ";
    cin >> posC;
    placer(taille, symb, tab2D);
  }
  affichage(taille, tab2D);
  
}

bool winner(int taille, char** &tab2D)
{
  bool isWin = true;

  //check les lignes
  for(int i = 0; i < taille; i++){
    for(int j = 0; j < taille-1; j++){
      if(tab2D[i][j] != tab2D[i][j+1]){
        isWin = false;
      } else {
        isWin = true;
      }
    }
  }

  //check les colonnes 
  for(int i = 0; i < taille; i++){
    for(int j = 0; j < taille-1; j++){
      if(tab2D[j][i] != tab2D[j+1][i])
      {
        isWin = false;
      } else {
        isWin = true;
      }
    }
  }

  //check les diagonales
  for(int i = 0; i < taille-1; i++){
    if(tab2D[i][i] != tab2D[i+1][i+1])
    {
      isWin = false;
    } else {
        isWin = true;
    }
  }

  for(int i = taille-1; i < 0; i++){
    for(int j = 0; j < taille-1; j++){
      if(tab2D[i][j] != tab2D[i-1][j+1])
      {
        isWin = false;
      } else {
        isWin = true;
      }
    }
  }

  return isWin;

}

void desalloc(int taille, char **&tab2D)
{
  for(int i = 0; i < taille; i++)
{
    delete [] tab2D[i];
}

delete[] tab2D;
}

int main()
{
  int taille;
  char symbole1, symbole2;
  char **grille;
  bool isWin_;

  cout << "Donnez la taille de la grille" << endl;
  cin >> taille;

  cout << "Symbole du joueur 1 : X ou O" << endl;
  cin >> symbole1;

  cout << "Symbole du joueur 2 : X ou O" << endl;
  cin >> symbole2;

  creer_vide(taille, grille);
  init(taille,grille);

  affichage(taille, grille);
  placer(taille, symbole1, grille);
  isWin_ = winner(taille,grille);
  placer(taille, symbole1, grille);
  isWin_ = winner(taille,grille);
  cout << isWin_ << endl;
  desalloc(taille, grille);
}