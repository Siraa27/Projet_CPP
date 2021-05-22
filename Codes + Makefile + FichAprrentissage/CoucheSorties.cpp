#include "CoucheSorties.hpp"

//Constructeur

CoucheSorties::CoucheSorties(const CoucheSorties& C) : Couche::Couche(C.getNbNeurones()), biais(C.biais), LiaisonsEntrees(C.LiaisonsEntrees)
{}

//nb colonnes = nb neuronnes couche precedentes et nb lignes = nb neurones de notre coucheCachee
CoucheSorties::CoucheSorties (const int nbNeurones, const int nbNeuronesCouchePrec) : Couche::Couche(nbNeurones), biais(nbNeurones, 1), LiaisonsEntrees(nbNeurones, nbNeuronesCouchePrec)
{}

// Accesseurs
Matrice CoucheSorties::getLiaisonEntrees() const{
	return (LiaisonsEntrees);
}

Matrice CoucheSorties::getBiais() const{
	return (biais);
}


//-----------------------------------Les Méthodes-----------------------------------
//-----------------------------------------------------------------------------------

//Fontion de pre activation 
Matrice CoucheSorties::preActivation(const Couche couchePrec)
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

double CoucheSorties::derivFoncActivation(const double x) //Derivee de la sigmoid
{
	return exp(-x)/((exp(-x) +1)*(exp(-x) +1));
}

//-----------------------------------------------------------------------------------