#include "Interface.hpp"

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
int Interface::validationReseau() const{
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
void Interface::setnbCouchesCachees(const int nb){nbCouchesCachees=nb;}
void Interface::setnbNeuronesEntree(const int nb){nbNeuronesEntree=nb;}
void Interface::setnbNeuronesSortie(const int nb){nbNeuronesSortie=nb;}
void Interface::setchoixPoid(const double choix){choixPoid=choix;}	
void Interface::settypeReseau(const int type){typeReseau=type;}
void Interface::setcasUtilisation(const int utilisation){casUtilisation=utilisation;}
void Interface::setnbNeuronesParCouches(const int nbneurones,const int i)
{
	if (i==0){nbNeuronesParCouches[0]=nbneurones;}
	else {nbNeuronesParCouches.push_back(nbneurones);};
}

/////////////////////////////////////////////////////////////GETTERS/////////////////////////////////////////////////////////////////////
int Interface::getnbCouchesCachees() const {return (nbCouchesCachees);}
int Interface::getnbNeuronesEntree() const {return (nbNeuronesEntree);}
int Interface::getnbNeuronesSortie() const {return (nbNeuronesSortie);}
double Interface::getchoixPoid() const {return(choixPoid);}	
int Interface::gettypeReseau() const {return(typeReseau);}
int Interface::getcasUtilisation() const {return(casUtilisation);}
vector<int> Interface::getnbNeuronesCouches() const {return nbNeuronesParCouches;}
int Interface::getnbNeuronesParCouches(const int i) const {return nbNeuronesParCouches[i];}


