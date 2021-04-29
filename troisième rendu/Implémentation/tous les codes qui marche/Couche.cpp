#include "Couche.hpp"
#include "Neurone.hpp"
#include "Matrice.hpp"
#include <stdlib.h>

//Constructeurs
Couche::Couche (const int nbN)
{
	nbNeurones = nbN;
	Neurones = std::vector<Neurone>(nbN);
	for(int i=0; i<nbN; i++)
	{
		Neurones.push_back(Neurone()) ;
	}
}

//Constructeur par recopie
Couche::Couche(Couche &c)
{
	nbNeurones = c.getNbNeurones();
	Neurones = std::vector<Neurone>(nbNeurones);
	for(int i=0; i<nbNeurones; i++)
	{
		Neurones.push_back(c.getNeurone(i)) ;
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
Matrice Couche::recupSortiesNeurones() const
{
	int nbLig = getNbNeurones();
	Matrice res(nbLig,1);
	for (int i=0; i<nbLig; i++)
	{
		(res).setCoefMatrice(i, 0, getNeurone(i).getSortie());
	}
	return res;
}

void Couche::modifNeurone(int i, double s)
{
    Neurones[i].setSortie(s);
}


//-----------------------------------------------------------------------------------