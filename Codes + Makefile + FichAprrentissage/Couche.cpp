#include "Couche.hpp"

//Constructeurs
Couche::Couche (const int nbN)
{
	nbNeurones = nbN;
	for(int i=0; i<nbN; i++)
	{
		Neurones.push_back(new Neurone()) ;
	}
}

//Constructeur par recopie
Couche::Couche(Couche &c)
{
	nbNeurones = c.getNbNeurones();
	Neurones = c.GetNeurones();
}

//destructeur
Couche::~Couche()
{
	nbNeurones = 0;
	for(int i=0; i<Neurones.size(); i++)
	{
		delete Neurones[i];
	}
	Neurones.clear();
}

//getters
int Couche::getNbNeurones() const
{
	return nbNeurones;
}

std::vector<Neurone*> Couche::GetNeurones()
{
	return Neurones;
}

Neurone* Couche::getNeurone(const int i) const
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
		(res).setCoefMatrice(i, 0, getNeurone(i)->getSortie());
	}
	return res;
}

void Couche::modifNeurone(const int i,const double s)
{
    Neurones[i]->setSortie(s);
}

std::ostream & operator <<(std::ostream & flux, const Couche& C)
{
	for(int i=0; i<C.getNbNeurones(); i++)
	{
		flux<<"Sortie du "<<i<<" eme neurone : "<<C.getNeurone(i)->getSortie()<<"\n";
	}
	return flux;
}

//-----------------------------------------------------------------------------------