#include "Interface.hpp"
#include "iostream"
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

///////////////////////////////////////////////////////////Constructeur////////////////////////////////////////////////////////////////
int verif;
Interface::Interface() {
	typeReseau=-1;
	nbCouchesCachees=-1;
	nbNeuronesEntree=-1;
	nbNeuronesSortie=-1;
	choixPoid=-1;
	typeReseau=-1;
	casUtilisation=-1;
	nbNeuronesParCouches.push_back(1);
	nbNeuronesParCouches[0]=0;
}
///////////////////////////////////////////////////////Validation du Reseau////////////////////////////////////////////////////////
int Interface::validationReseau(){
	if(typeReseau==-1||casUtilisation==-1||nbNeuronesEntree==-1||nbNeuronesSortie==-1||nbCouchesCachees==-1||nbNeuronesParCouches[0]==-1||choixPoid==-1)
	{
		cout<<"le reseau est non conforme \n";
		verif=0;
	}
	else
	{
		cout<<"le reseau est conforme \n";
		verif= 1;
	}
	return(verif);
}

///////////////////////////////////////////////////////////////SETTERS////////////////////////////////////////////////////////////////
void Interface::setnbCouchesCachees(int nb){nbCouchesCachees=nb;}
void Interface::setnbNeuronesEntree(int nb){nbNeuronesEntree=nb;}
void Interface::setnbNeuronesSortie(int nb){nbNeuronesSortie=nb;}
void Interface::setchoixPoid(double choix){choixPoid=choix;}	
void Interface::settypeReseau(int type){typeReseau=type;}
void Interface::setcasUtilisation(int utilisation){casUtilisation=utilisation;}
void Interface::setnbNeuronesParCouches(int nbneurones, int i)
{
	if (i==0){nbNeuronesParCouches[0]=nbneurones;}
	else {nbNeuronesParCouches.push_back(nbneurones);};
}

/////////////////////////////////////////////////////////////GETTERS/////////////////////////////////////////////////////////////////////
int Interface::getnbCouchesCachees(){return (nbCouchesCachees);}
int Interface::getnbNeuronesEntree(){return (nbNeuronesEntree);}
int Interface::getnbNeuronesSortie(){return (nbNeuronesSortie);}
double Interface::getchoixPoid(){ return(choixPoid);}	
int Interface::gettypeReseau(){ return(typeReseau);}
int Interface::getcasUtilisation(){ return(casUtilisation);}
int Interface::getnbNeuronesParCouches(int ind){ return(nbNeuronesParCouches[ind]);}


