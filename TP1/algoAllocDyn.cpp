#include<iostream>
#include<math.h>
using namespace std;

int main()
{

int taille;
int* tab;
int* tabCarre;


cout << "Saisir une taille de tableau svp" << endl;
cin >> taille;

tab = new int[taille];
tabCarre = new int[taille];

for(int i = 0; i < taille; i++)
{
  cout << "entrez une valeur : " << " ";
  cin >> tab[i];
  tabCarre[i] = tab[i]*tab[i];
  cout << "tab[" << i << "] : " << tab[i] << " " << "tabCarre[" << i << "] : "<< tabCarre[i] << endl;
}

delete[] tab;

cout << endl << "Affichage de tabCarre : " << endl;
for(int i = 0; i < taille; i++)
{
  cout << "tabCarre[" << i << "] : "<< tabCarre[i] << endl;
}

delete[] tabCarre;

cout << endl << "test d'accés au tableau désalloué : " << endl;
cout << "tab[" << taille << "] : " << tab[taille] << endl;
cout << "tabCarre[" << taille << "] : " << tabCarre[taille] << endl; //accés a de la memoire déréferencée, donne des données inconues, gros pb
}
