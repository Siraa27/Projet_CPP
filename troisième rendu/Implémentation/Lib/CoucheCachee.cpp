#include "CoucheCachee.hpp"
#include "Couche.hpp"
#include "Matrice.hpp"
#include <math.h> 

//Constructeur
CoucheCachee::CoucheCachee (const int nbNeurones, const int nbNeuronesCouchePrec) : Couche::Couche(nbNeurones)
{
	biais = new Matrice(nbNeurones, 1);
	LiaisonsEntrees = new Matrice(nbNeurones, nbNeuronesCouchePrec); //nb colonnes = nb neuronnes couche precedentes et nb lignes = nb neurones de notre coucheCachee
}

//destructeur
CoucheCachee::~CoucheCachee()
{
	(*biais).~Matrice();
	(*LiaisonsEntrees).~Matrice();
}

//Fontion de pre activation 
Matrice CoucheCachee::preActivation(Couche couchePrec)
{
	//(Produit matriciel Liaison 
	Matrice res = (LiaisonsEntrees->operator *(couchePrec.recupSortiesNeurones())).operator +(*biais);
	return res;
}

void CoucheCachee::foncActivation(Matrice sum)
{
	for (int i=0; i<getNbNeurones(); i++)
	{
		getNeurone(i).setSortie(1/(1+exp(sum.getMatrice()[i][1])));
	}
}

double CoucheCachee::derivFoncActivation(double x)
{
	return exp(-x)/((exp(-x) +1)*(exp(-x) +1));
}