#include "Neurone.hpp"

// Constructeur
Neurone::Neurone(const double out)
{
	sortie = out;
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
