#include "Interface.hpp"
#include "InterfaceFichier.hpp"
#include "iostream"
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

//------------------------------------------Les Méthodes-----------------------------------------------
//------------------------------------------------------------------------------------------------------

void InterfaceFichier::lectureFichier(std::string nomFic){//fournir le chemin absolu ou relatif
//pourquoi on utilise pas string ? 
//obligé de passer le tableau en param sinon pas d'accés
	ifstream fichier(nomFic, ios::in);  // on ouvre le fichier en lecture
	if(fichier)
	{
		//tout est près
		int indice=1;
		double nombre;
		 for (double nombre; fichier >> nombre; )  //Tant qu'on a pas atteint la fin du fichier
		{	
			switch (indice)
			{
				case 1://chargement du type de réseau
					if (static_cast<int>(nombre)==1)//Nous n'avons implémenté que réseau Forwarded
					{	
						settypeReseau(static_cast<int>(nombre));
					}
					else 
					{
						cout<<"ERREUR: Type reseau non disponible ou non conforme\n";
					}
					break;
				case 2://chargement du cas d'utilisation
					if (static_cast<int>(nombre)==1)//Nous n'avons implémenté que la classification
					{	
						setcasUtilisation(static_cast<int>(nombre));
					}
					else 
					{
						cout<<"ERREUR: Cas d'utilisation non disponible ou non conforme\n";
					}
					break;
				case 3://Chargement du nombre de couches cachees
					if (static_cast<int>(nombre)>=0)//Nombre de couches doit etre positif
					{	
						setnbCouchesCachees(static_cast<int>(nombre));
					}
					else 
					{
						cout<<"ERREUR: Nombre de couches negatif\n";
					}
					break;
				default:
					if((indice>=4)&&(indice<=(getnbCouchesCachees()+3))||(getnbCouchesCachees()<0))
					{//chargement du nombre de neurones par couches cachees
						if (static_cast<int>(nombre)>0)//Nombre de neurones dans une couche est superieure a 0
						{	
							setnbNeuronesParCouches(static_cast<int>(nombre), indice-4);
						}
						else 
						{
							setnbNeuronesParCouches(-1, 0);
							cout<<"ERREUR: Nombre de neurones negatif ou probleme de couche cachee\n";
						}
					}
					else if (indice==(getnbCouchesCachees()+4))
					{//chargement de l'initialisation de la matrice de poids
						if (static_cast<int>(nombre)>=0)//Poids non negatif
						{	
							setchoixPoid(nombre);
						}
						else 
						{
							cout<<"ERREUR: Initialisation de la matrice de Poids avec des valeurs negatives\n";
						}
						setchoixPoid(nombre);
					}
			}
			indice++;
		}			
		if (indice>(getnbCouchesCachees()+5))//Surcharge de donnees
		{
			cout<<"ERREUR: Le fichier de donnees contient "<< (indice - (getnbCouchesCachees()+5)) <<" donnees supplementaire\n" <<"Nous retiendrons les "<<(getnbCouchesCachees()+4)<<" premieres pour la creation du reseau\n";
		}
		else if (indice<(getnbCouchesCachees()+3))//Peu de donnees
		{
			cout<<"ERREUR: Le fichier contient un nombre de donnees insuffisant\n "<< " ERREUR: Impossible de construire le réseau associe\n";
		settypeReseau(-1);
		}		
		
	}
	else //Si fichier introuvable
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." <<endl;
	}
}

//------------------------------------------------------------------------------------------------------