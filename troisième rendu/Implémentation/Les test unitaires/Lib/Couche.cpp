#include "Couche.hpp"
#include "Neurone.hpp"
#include "Matrice.hpp"
#include <stdlib.h>

//Constructeur
Couche::Couche (const int nbN)
{
	nbNeurones = nbN;
	Neurones = std::vector<Neurone>(nbN);
	for(int i=0; i<nbN; i++)
	{
		Neurones[i] = Neurone();
	}
}
		
//destructeur
Couche::~Couche()
{
	nbNeurones = 0;
	Neurones.clear();
}

//getters
int Couche::getNbNeurones() const
{
	return nbNeurones;
}

Neurone Couche::getNeurone(int i) const
{
	return Neurones[i];
}

//-----------------------------------Les Méthodes-----------------------------------
//-----------------------------------------------------------------------------------

//Recupere les sorties des neurones de la couche et les stock dans une matrice
Matrice Couche::recupSortiesNeurones()
{
	int nbLig = getNbNeurones();
	Matrice res = Matrice(nbLig, 1);
	for (int i=0; i<nbLig; i++)
	{
		(res).setCoefMatrice(i, 1, getNeurone(i).getSortie());
	}
	return res;
}

//-----------------------------------------------------------------------------------