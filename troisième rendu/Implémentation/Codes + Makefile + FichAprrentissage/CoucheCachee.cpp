#include "CoucheCachee.hpp"
#include "Couche.hpp"
#include "Matrice.hpp"
#include <iostream>
#include <math.h> 

//Constructeur
CoucheCachee::CoucheCachee(const CoucheCachee& C) : Couche::Couche(C.getNbNeurones()), biais(C.biais), LiaisonsEntrees(C.LiaisonsEntrees)
{}

//nb colonnes = nb neuronnes couche precedentes et nb lignes = nb neurones de notre coucheCachee
CoucheCachee::CoucheCachee (const int nbNeurones, const int nbNeuronesCouchePrec) : Couche::Couche(nbNeurones), biais(nbNeurones, 1), LiaisonsEntrees(nbNeurones, nbNeuronesCouchePrec)
{}


//destructeur
CoucheCachee::~CoucheCachee()
{
	biais.~Matrice();
	LiaisonsEntrees.~Matrice();
}

// Accesseurs
Matrice CoucheCachee::getLiaisonEntrees()
{
	return LiaisonsEntrees;
}

Matrice CoucheCachee::getBiais()
{
	return biais;
}

void CoucheCachee::setBiais(int i, int j, double coef )
{
	biais.setCoefMatrice(i,j,coef);
}

//-----------------------------------Les Méthodes-----------------------------------
//-----------------------------------------------------------------------------------

//Fonction de pre activation 
Matrice CoucheCachee::preActivation(Couche couchePrec) 
{
	//(Matrice Liaison * Sorties neurones couche precedente) + biais
	//Nous manipulons des matrices 
	Matrice res = LiaisonsEntrees.operator *(couchePrec.recupSortiesNeurones()).operator +(biais);
	return res;
}
//Fonction de activation 
void CoucheCachee::foncActivation(Matrice sum) //sigmoid
{
	for (int i=0; i<getNbNeurones(); i++)
	{
		//On modifie directement la sortie des neurones de la couche
		double res ;
		res = 1./(1+exp(sum.getCoefMatrice(i,0))) ;
		modifNeurone(i, res);
	}
}

double CoucheCachee::derivFoncActivation(double x) //Derivee de la sigmoid
{
	return exp(-x)/((exp(-x) +1)*(exp(-x) +1));
}
//-----------------------------------------------------------------------------------