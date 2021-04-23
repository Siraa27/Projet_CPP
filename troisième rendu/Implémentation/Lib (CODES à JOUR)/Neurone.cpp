#include "Neurone.hpp"
//using namespace Les_couches_du_reseau;

Neurone::Neurone(double out)
{
	sortie = 0;
}

void Neurone::setSortie(const double S)
{
	sortie = S;
}

double Neurone::getSortie() const
{
	return sortie;
}
