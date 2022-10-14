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

void afficher(int taille, char **&tab2D)
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
  

  while( (tab2D[posL-1][posC-1] != '-') || ((posL > taille) || (posC > taille)) ) {
    cout << endl << "inserez une nouvelle position de ligne : ";
    cin >> posL;
    cout << "inserez une nouvelle position de colonne : ";
    cin >> posC;
  }

  tab2D[posL-1][posC-1] = symb; 
  afficher(taille, tab2D);
}
  
bool winner(char c, int taille, char** &tab2D)
{
  bool isWinner;
  // Checks Horizontal lines to see if c has won
  for(int i = 0; i < taille; i++){
    
    isWinner = true;
    for(int j = 0; j < taille; j++)
    {
        if(tab2D[i][j] != c){
          isWinner = false;
        }

    }
    if(isWinner) return true;

  }
  // Checks Vertical lines to see if c has won

  for(int j = 0; j < taille; j++){
    isWinner = true;
    for(int i = 0; i < taille; i++)
    {
        if(tab2D[i][j] != c){
          isWinner = false;
        }

    }
    if(isWinner) return true;

  }
  
  // Checks the center diagonal
  for(int i = 0; i < taille; i++){
    isWinner = true;
    
    if(tab2D[i][i] != c){
      isWinner = false;
     }
    

  }
  if(isWinner) return true;


  // If in none of the cases above we win, then we automatically know its not a win(false)
  return false;
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
  bool isWin_ = false;

  cout << "Donnez la taille de la grille" << endl;
  cin >> taille;

  cout << "Symbole du joueur 1 : X ou O" << endl;
  cin >> symbole1;

  cout << "Symbole du joueur 2 : X ou O" << endl;
  cin >> symbole2;

  creer_vide(taille, grille);
  init(taille,grille);
  afficher(taille, grille);

  while(isWin_ == false)
  {
    if(isWin_ == false){
      cout << endl << symbole1 << " joue le tour" << endl;
      placer(taille, symbole1, grille);
      isWin_ = winner(symbole1,taille,grille);
    }

    if(isWin_ == false){
      cout << endl << symbole2 << " joue le tour" << endl;
      placer(taille, symbole2, grille);
      isWin_ = winner(symbole2,taille,grille);
    }
  }
  cout << "winner";
  desalloc(taille, grille);
}