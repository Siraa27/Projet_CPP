#include "CoucheSorties.hpp"
#include "Couche.hpp"
#include "Matrice.hpp"
#include <iostream>
#include <math.h> 

//Constructeur

CoucheSorties::CoucheSorties(const CoucheSorties& C) : Couche::Couche(C.getNbNeurones()), biais(C.biais), LiaisonsEntrees(C.LiaisonsEntrees)
{
	for(int i=0;i<C.getNbNeurones();i++)
	{
		getNeurone(i).setSortie(C.getNeurone(i).getSortie());
	}
}

//nb colonnes = nb neuronnes couche precedentes et nb lignes = nb neurones de notre coucheCachee
CoucheSorties::CoucheSorties (const int nbNeurones, const int nbNeuronesCouchePrec) : Couche::Couche(nbNeurones), biais(nbNeurones, 1), LiaisonsEntrees(nbNeurones, nbNeuronesCouchePrec)
{}

//destructeur
CoucheSorties::~CoucheSorties() 
{
	//(biais).~Matrice();
	//(LiaisonsEntrees).~Matrice();
}

// Accesseurs
Matrice& CoucheSorties::getLiaisonEntrees(){
	return (LiaisonsEntrees);
}

Matrice& CoucheSorties::getBiais(){
	return (biais);
}


//-----------------------------------Les Méthodes-----------------------------------
//-----------------------------------------------------------------------------------

//Fontion de pre activation 
Matrice CoucheSorties::preActivation(Couche couchePrec)
{
	//(Matrice Liaison * Sorties neurones couche precedente) + biais
	//Nous manipulons des matrices 
	Matrice res = (LiaisonsEntrees.operator *(couchePrec.recupSortiesNeurones())).operator +(biais);
	return res;
}

void CoucheSorties::foncActivation(Matrice sum) //sigmoid
{
	for (int i=0; i<getNbNeurones(); i++)
	{
		//On modifie directement la sortie des neurones de la couche
		double res ;
		res = 1./(1+exp(sum.getCoefMatrice(i,0))) ;
		modifNeurone(i, res);
	}
}

double CoucheSorties::derivFoncActivation(double x) //Derivee de la sigmoid
{
	return exp(-x)/((exp(-x) +1)*(exp(-x) +1));
}

//-----------------------------------------------------------------------------------