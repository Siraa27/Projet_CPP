#include "CoucheCachee.hpp"
#include "Couche.hpp"
#include "Matrice.hpp"
#include <math.h> 

CoucheCachee::CoucheCachee (const int nbNeurones, const int nbNeuronesCouchePrec) : Couche::Couche(nbNeurones)
{
	biais = new Matrice(nbNeurones, 1);
	LiaisonsEntrees = new Matrice(nbNeurones, nbNeuronesCouchePrec); //nb colonnes = nb neuronnes couche precedentes et nb lignes = nb neurones de notre coucheCachee
}

CoucheCachee::~CoucheCachee() // Couche::~Couche() pas besoin ? 
{
	(*biais).~Matrice();
	(*LiaisonsEntrees).~Matrice();
}

Matrice CoucheCachee::preActivation()
{
	Matrice res = LiaisonsEntrees->operator *(*biais);
	return res;
}

void CoucheCachee::foncActivation(Matrice sum)
{
	for (int i=0; i<getNbNeurones(); i++)
	{
		getNeurone(i).setSortie(1/(1+exp(sum.getMatrice()[i][1])));
	}
}
