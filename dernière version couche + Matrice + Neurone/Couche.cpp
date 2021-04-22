#include "Couche.hpp"
#include <vector>
//using namespace Les_couches_du_reseau;

Couche::Couche (const int nbN)
{
	nbNeurones = nbN;
	nbCouches++;
	indice = nbCouches;
	Neurones = std::vector<Neurone>(nbN);
	for(int i=0; i<nbN; i++)
	{
		Neurones[i] = Neurone();
	}
}
		
Couche::~Couche()
{
	nbNeurones = 0;
	nbCouches--;
	Neurones.clear();
}

int Couche::getNbCouche() const
{
	return nbCouches;
}

int Couche::getNbNeurones() const
{
	return nbNeurones;
}

Neurone Couche::getNeurone(int i) const
{
	return Neurones[i];
}
