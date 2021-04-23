#include "Interface.hpp"
#include "iostream"
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;
//using namespace Interface_Saisie_des_donnees;
//Interface_Saisie_des_donnees??? namespace using 

Interface::Interface() {
	typeReseau=-1;
	nbCouchesCachees=-1;
	choixPoid=-1;
	typeReseau=-1;
	casUtilisation=-1;
	nbNeuronesParCouches.push_back(1);
	nbNeuronesParCouches[0]=0;
}


//NB int ia = a - '0'; convertir caractère a en int 

//lecture du fichier mot par mot type de réseau+cas d'utilisation+nbCouche+nb neurone par couche+choix inti matrice de poid


void Interface::setnbCouchesCachees(int nb){nbCouchesCachees=nb;}
void Interface::setchoixPoid(double choix){choixPoid=choix;};	
void Interface::settypeReseau(int type){typeReseau=type;};
void Interface::setcasUtilisation(int utilisation){casUtilisation=utilisation;};
void Interface::setnbNeuronesParCouches(int nbneurones, int i)
{
	if (i==0){nbNeuronesParCouches[0]=nbneurones;}
	else {nbNeuronesParCouches.push_back(nbneurones);};
}


int Interface::getnbCouchesCachees(){return(nbCouchesCachees);};
double Interface::getchoixPoid(){return(choixPoid);};	
int Interface::gettypeReseau(){return(typeReseau);};
int Interface::getcasUtilisation(){return(casUtilisation);};
int Interface::getnbNeuronesParCouches(int ind){return(nbNeuronesParCouches[ind]);};
//Dans InterfaceManuelle

void Interface::lectureParam(){//fournir le chemin absolu ou 
	int nombre;
	cout<<"Saisir l'entier correspondant au type de reseau souhaite\n";
	cout<<"1: reseau forwarded\n";
	cout<<"2: reseau recurent\n";
	cout<<"0:quitter\n";
	cin>> typeReseau;
	if (typeReseau!=1)//Nous avons implémenté que réseau Forwarded
	{	
		typeReseau=-1;
		cout<<"ERREUR: Type reseau non disponible ou non conforme\n";
	}

	cout<<"Saisir l'entier correspondant au cas d'utilisation souhaite\n";
	cout<<"1: classification\n";
	cout<<"2: prediction\n";
	cin>> casUtilisation;
	cout<<"Saisir l'entier correspondant au nombre de couches cachees du reseau\n";
	cin>> nbCouchesCachees;
	cout<<"Saisir un a un le nombre de neurones dans chaques couches cachees\n";
	for (int i=0;i<nbCouchesCachees;i++){ 
		cin>>nombre;
		setnbNeuronesParCouches(nombre, i);}
	cout<<"Comment voulez vous intisaliser votre matrice de poid ?\n";	
	cout<<"0: aleatoirement\n";
	cout<<"x un double: tous à x\n";
	cin>>choixPoid;}

void Interface::lectureFichier(std::string nomFic){//fournir le chemin absolu ou relatif
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
					if (static_cast<int>(nombre)==1)//Nous avons implémenté que réseau Forwarded
					{	
						settypeReseau(static_cast<int>(nombre));
					}
					else 
					{
						cout<<"ERREUR: Type reseau non disponible ou non conforme\n";
					}
					break;
				case 2://chargement du cas d'utilisation
					if (static_cast<int>(nombre)==1)//Nous avons implémenté que réseau Forwarded
					{	
						setcasUtilisation(static_cast<int>(nombre));
					}
					else 
					{
						cout<<"ERREUR: Cas d'utilisation non disponible ou non conforme\n";
					}
					break;
				case 3://Chargement du nombre de couches cachees
					if (static_cast<int>(nombre)>=0)//Nous avons implémenté que réseau Forwarded
					{	
						setnbCouchesCachees(static_cast<int>(nombre));
					}
					else 
					{
						cout<<"ERREUR: Nombre de couche négative\n";
					}
					break;
				default:
					if((indice>=4)&&(indice<=(getnbCouchesCachees()+3)))
					{//chargement du nombre de neurones par couches cachees
						if (static_cast<int>(nombre)>0)//Nombre de neurone dans une couche est superieure a 0
						{	
							setnbNeuronesParCouches(static_cast<int>(nombre), indice-4);
						}
						else 
						{
							cout<<"ERREUR: Nombre de neurones négatif\n";
						}
					}
					else if (indice==(getnbCouchesCachees()+4))
					{//chargement de l'initialisation de la matrice de poid
						if (static_cast<int>(nombre)>=0)//Poid non négatif
						{	
							setchoixPoid(nombre);
						}
						else 
						{
							cout<<"ERREUR: Initialisation de la matrice de Poid avec des valeurs negatives\n";
						}
						setchoixPoid(nombre);
					}
			}
			indice++;
		}			
		if (indice>(getnbCouchesCachees()+4))//Surcharge de donnees
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
int main() {
	
	Interface A;
	std::string Fichier;
	cout<<"Entrer le nom de votre fichier de paramètre, de la racine\n";
	cin>>Fichier;
	A.lectureFichier(Fichier);
	cout<< "type Reseau\n"<<A.gettypeReseau();
	cout<< "cas utilisation\n"<<A.getcasUtilisation();
	cout<< "nbcouche cachees\n"<<A.getnbCouchesCachees();
	cout<< "nbneuroen0\n"<<A.getnbNeuronesParCouches(0);
	cout<< "nbneuroen1\n"<<A.getnbNeuronesParCouches(1);
	cout<< "choix de poid \n"<<A.getchoixPoid();
	return 0;
}
