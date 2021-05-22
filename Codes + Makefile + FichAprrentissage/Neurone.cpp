#include "Neurone.hpp"

// Constructeur
Neurone::Neurone(const double out)
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
