#include "Interface.hpp"
#include "InterfaceManuelle.hpp"
#include "iostream"
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

//------------------------------------------Les Méthodes-----------------------------------------------
//------------------------------------------------------------------------------------------------------

void InterfaceManuelle::lectureParam(){//fournir le chemin absolu ou 
	int nombre;
	cout<<"Saisir l'entier correspondant au type de reseau souhaite\n";
	cout<<"1: reseau forwarded\n";
	cout<<"2: reseau recurent\n";
	cout<<"0:quitter\n";
	cin>> typeReseau;
	if (typeReseau!=1)//Nous n'avons implémenté que le type réseau Forwarded
	{	
		typeReseau=-1;
		cout<<"ERREUR: Type reseau non disponible ou non conforme\n";
	}

	cout<<"Saisir l'entier correspondant au cas d'utilisation souhaite\n";
	cout<<"1: classification\n";
	cout<<"2: prediction\n";
	cin>> casUtilisation;
	if (casUtilisation!=1)//Nous n'avons implémenté que la classification
	{	
		casUtilisation=-1;
		cout<<"ERREUR: Cas d'utilisation non disponible ou non conforme\n";
	}
	cout<<"Saisir l'entier correspondant au nombre de couches cachees du reseau\n";
	cin>> nbCouchesCachees;
	if (nbCouchesCachees<0)//Nous n'avons implémenté que la classification
	{	
		nbCouchesCachees=-1;
		cout<<"ERREUR: Nombre de couches cachees negatif\n";
	}
	cout<<"Saisir un a un le nombre de neurones dans chaques couches cachees\n";
	for (int i=0;i<nbCouchesCachees;i++){ 
		cin>>nombre;
		if (nombre<=0)//Nombre de neurones dans une couche est superieure a 0
		{	
			nombre=0;
			cout<<"ERREUR: Nombre de neurones négatif\n";
		}
		setnbNeuronesParCouches(nombre, i);}
	cout<<"Comment voulez vous initialiser votre matrice de poids ?\n";	
	cout<<"0: aleatoirement\n";
	cout<<"x un double: tous à x\n";
	cin>>choixPoid;
		if (choixPoid<0)//Poid non négatif
		{	
			choixPoid=-1;
			cout<<"ERREUR: Initialisation de la matrice de Poid avec des valeurs negatives\n";
		}
}

//------------------------------------------------------------------------------------------------------
	
	
