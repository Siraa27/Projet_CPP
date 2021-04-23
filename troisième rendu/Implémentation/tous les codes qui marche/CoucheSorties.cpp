#include "CoucheSorties.hpp"
#include "Couche.hpp"
#include "Matrice.hpp"
#include <math.h> 

//Constructeur
CoucheSorties::CoucheSorties (const int nbNeurones, const int nbNeuronesCouchePrec) : Couche::Couche(nbNeurones)
{
	biais = new Matrice(nbNeurones, 1);
	LiaisonsEntrees = new Matrice(nbNeurones, nbNeuronesCouchePrec); //nb colonnes = nb neuronnes couche precedentes et nb lignes = nb neurones de notre coucheCachee
}

//destructeur
CoucheSorties::~CoucheSorties() 
{
	(*biais).~Matrice();
	(*LiaisonsEntrees).~Matrice();
}

// Accesseurs
Matrice CoucheSorties::getLiaisonEntrees(){
	return (*LiaisonsEntrees);
}

Matrice CoucheSorties::getBiais(){
	return (*biais);
}


//-----------------------------------Les Méthodes-----------------------------------
//-----------------------------------------------------------------------------------

//Fontion de pre activation 
Matrice CoucheSorties::preActivation(Couche couchePrec)
{
	//(Matrice Liaison * Sorties neurones couche precedente) + biais
	//Nous manipulons des matrices 
	Matrice res = (LiaisonsEntrees->operator *(couchePrec.recupSortiesNeurones())).operator +(*biais);
	return res;
}

void CoucheSorties::foncActivation(Matrice sum) //sigmoid
{
	for (int i=0; i<getNbNeurones(); i++)
	{
		//On modifie directement la sortie des neurones de la couche
		getNeurone(i).setSortie(1/(1+exp(sum.getMatrice()[i][1])));
	}
}

double CoucheSorties::derivFoncActivation(double x) //Derivee de la sigmoid
{
	return exp(-x)/((exp(-x) +1)*(exp(-x) +1));
}

//-----------------------------------------------------------------------------------