/*
  ASD1 - TP n°1 - TIC TAC TOE 
*/

#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

//initialise le tableau 2D
void init(int taille, char** &tab2D)
{
  tab2D = new char*[taille];
  for(int i = 0; i < taille; i++)
  {
    tab2D[i] = new char[taille];
    
  }
}

//remplie le tableau de '-' qui refére a des cases vide et jouable
void remplir(int taille, char** &tab2D){
  for(int i = 0; i < taille; i++)
  {
    for(int j = 0; j < taille; j++)
    {
      tab2D[i][j] = '-';
    }
  }
}

//Affiche la grille de jeu au fur-et-a-mesure de la partie
void afficher(int taille, char** &tab2D)
{
  //vide le terminal CLEAR sur linux
  system("CLEAR");

  //Affichage de la grille de jeu
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
      //permet a chaque appel de afficher de modifier la grille avec le nouveau symbole ajouter
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

//Place selon les position que l'utilisateur choisie le symbole du jouer dans la grille de jeu
void placer(int taille, char symb, char** &tab2D)
{
  int posL, posC;

    cout << endl << "inserez une position de ligne : ";
    cin >> posL;
    cout << "inserez une position de colonne : ";
    cin >> posC;
  
  //condiction de verification des position donner par l'utilisateur
  while( (tab2D[posL-1][posC-1] != '-') || ((posL > taille) || (posC > taille)) ) 
  {
    cout << endl << "inserez une nouvelle position de ligne : ";
    cin >> posL;
    cout << "inserez une nouvelle position de colonne : ";
    cin >> posC;
  }
  //ajout
  tab2D[posL-1][posC-1] = symb; 
  afficher(taille, tab2D);
}

//Verifie la totalité de la grille pour savoir si la partie est gagné par un certain joueur selon les suite de caractere dans la grille
bool winner(char c, int taille, char** &tab2D)
{
  bool isWinner;
  
  //Verification des lignes
  for(int i = 0; i < taille; i++)
  {  
    isWinner = true;
    for(int j = 0; j < taille; j++)
    {
      if(tab2D[i][j] != c){
        isWinner = false;
      }
    }
    if(isWinner){ cout << "winner : " << c ; return true; }
  }

  //Verification des colonnes
  for(int j = 0; j < taille; j++)
  {
    isWinner = true;
    for(int i = 0; i < taille; i++)
    {
      if(tab2D[i][j] != c){
        isWinner = false;
      }
    }
    if(isWinner){ cout << "winner : " << c ; return true; }
  }
  
  //Verification des diagonales
  isWinner = true;
  for(int i = 0; i < taille; i++)
  {
    //isWinner = true;
    if(tab2D[i][i] != c){
      isWinner = false;
    }
  }
  if(isWinner){ cout << "winner : " << c ; return true; }

  isWinner = true;
  for(int i = taille-1; i >= 0; i--)
  {
    //isWinner = true;
    if(tab2D[i][taille-1-i] != c){
      isWinner = false;
    }
  }
  if(isWinner){ cout << "winner : " << c ; return true; }

  //Si aucunes ligne, diagonales ou colonnes n'est remplie du meme caractere retorune qu'il n'y pas de gagnant pour l'etat actuel de la grille
  return false;
}

//Desallocation du tableau 2D
void desalloc(int taille, char** &tab2D)
{
  for(int i = 0; i < taille; i++)
{
    delete [] tab2D[i];
}

  delete[] tab2D;
}

int main()
{
  //Variables
  int taille;
  char symbole1, symbole2;
  char** grille;
  bool isWin_ = false;

  //Début de partie, initilisation des variables par l'utilisateur 
  cout << "Donnez la taille de la grille" << endl;
  cin >> taille;

  cout << "Symbole du joueur 1 : X ou O" << endl;
  cin >> symbole1;

  cout << "Symbole du joueur 2 : X ou O" << endl;
  cin >> symbole2;

  init(taille, grille);
  remplir(taille, grille);
  afficher(taille, grille);

  /*
    structure l'enchainement d'une partie de tic tac toe
    pour indiquer le cas d'une egalité, rajouter dans le tant que (isWin_ == false && grille non totalement remplie)
    donc une fonction booléenne qui regarde si la grille est pleine ou non
  */
  while(isWin_ == false)
  {
    if(isWin_ == false){
      cout << endl << symbole1 << " joue le tour" << endl;
      placer(taille, symbole1, grille);
      isWin_ = winner(symbole1, taille, grille);
    }

    if(isWin_ == false){
      cout << endl << symbole2 << " joue le tour" << endl;
      placer(taille, symbole2, grille);
      isWin_ = winner(symbole2, taille,  grille);
    }
  }

  desalloc(taille, grille);
}