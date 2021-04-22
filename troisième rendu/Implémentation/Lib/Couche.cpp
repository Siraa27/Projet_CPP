#include "Couche.hpp"
#include "Neurone.hpp"
#include "Matrice.hpp"
#include <stdlib.h>
//using namespace Les_couches_du_reseau;

Couche::Couche (const int nbN)
{
	nbNeurones = nbN;
	Neurones = std::vector<Neurone>(nbN);
	for(int i=0; i<nbN; i++)
	{
		Neurones[i] = Neurone();
	}
}
		
Couche::~Couche()
{
	nbNeurones = 0;
	Neurones.clear();
}

int Couche::getNbNeurones() const
{
	return nbNeurones;
}

Neurone Couche::getNeurone(int i) const
{
	return Neurones[i];
}

Matrice Couche::recupSortiesNeurones()
{
	int nbLig = getNbNeurones();
	Matrice res = new Matrice(nbLig, 1)
	for (i=0; i<nbLig; i++)
	{
		setCoefMatrice(i, 1, getNeurone(i).getSortie());
	}
}