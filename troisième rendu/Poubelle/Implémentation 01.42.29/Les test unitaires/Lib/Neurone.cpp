#include "Neurone.hpp"
//using namespace Les_couches_du_reseau;

// Constructeur
Neurone::Neurone(double out)
{
	sortie = 0;
}

// Mutateur 
void Neurone::setSortie(const double S)
{
	sortie = S;
}

// Accesseur
double Neurone::getSortie() const
{
	return sortie;
}
