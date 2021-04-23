#include "Interface.hpp"
#include "iostream"
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;
//using namespace Interface_Saisie_des_donnees;
//Interface_Saisie_des_donnees??? namespace using ???

Interface::Interface() {
	nbCouchesCachees=0;
	choixPoid=100;
	typeReseau=0;
	casUtilisation=0;
	nbNeuronesParCouches[0]=0;
}

//ajouter un tableau dyn en attribut en public

void Interface::lectureFichier(std::string nomFic){//fournir le chemin absolu ou relatif
//pourquoi on utilise pas string ? 
//obligé de passer le tableau en param sinon pas d'accés
	ifstream fichier(nomFic, ios::in);  // on ouvre le fichier en lecture
	if(fichier)
	{
		//tout est près
		int indice=1;
		istream_iterator<int> it(fichier); //Un itérateur sur le fichier    
		
		istream_iterator<int> end;   
		while(it != end)   //Tant qu'on a pas atteint la fin
		{
			int nombre;
			fichier >>nombre;
			if (indice==1)
			{ //chargement du type de réseau
				settypeReseau(nombre);
			}
			else if (indice==2)
			{//chargement du cas d'utilisation
				setcasUtilisation(nombre);
			}
			else if (indice==3)
			{//Chargement du nombre de couches cachees
				setnbCouchesCachees(nombre);
			}
			else if((indice>=4)&&(indice<=(getnbCouchesCachees()+4)))
			{//chargement du nombre de neurones par couches cachees
				setnbNeuronesParCouches(nombre, indice-4);
			}
			else {setchoixPoid(nombre);}
			cout << *it << endl;  //On lit
			++it;                 //Et on avance
			indice++;	
		}
		
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." <<endl;
	}
//NB int ia = a - '0'; convertir caractère a en int 
}
//lecture du fichier mot par mot type de réseau+cas d'utilisation+nbCouche+nb neurone par couche+choix inti matrice de poid


void Interface::setnbCouchesCachees(int nb){nbCouchesCachees=nb;}
void Interface::setchoixPoid(int choix){choixPoid=choix;};	
void Interface::settypeReseau(int type){typeReseau=type;};
void Interface::setcasUtilisation(int utilisation){casUtilisation=utilisation;};
void Interface::setnbNeuronesParCouches(int nbneurones, int i)
{
	if (i==0){nbNeuronesParCouches[i]=nbneurones;}
	else {nbNeuronesParCouches.push_back(nbneurones);};
}


int getnbCouchesCachees();
int getchoixPoid();	
int gettypeReseau();
int getcasUtilisation();
int getnbNeuronesParCouches(int ind);


int main() {

	return 0;
}

	
	
