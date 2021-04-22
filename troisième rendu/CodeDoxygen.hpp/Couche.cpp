#include "Couche.hpp"
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
