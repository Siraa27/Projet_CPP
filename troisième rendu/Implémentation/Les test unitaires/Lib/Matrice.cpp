#include "Matrice.hpp"
#include <stdexcept>
#include <random>

//Constructeurs
Matrice::Matrice(const int nbLignes, const int nbColonnes)
{
	nbLig = nbLignes;
	nbCol = nbColonnes;
	matrice = new double*[nbLignes];
	for(int i = 0;i < nbLignes;++i) 
	{
		matrice[i] = new double[nbColonnes];
	}
}

/*
Matrice::Matrice(const int nbLignes, const int nbColonnes, double** t)
{
	nbLig = nbLignes;
	nbCol = nbColonnes;
	matrice = new double*[nbLignes];
	for(int i = 0;i < nbLignes;++i) 
	{
		matrice[i] = new double[nbColonnes];
	}
	t = {{1, 2, 3}{4, 5, 6}{7, 8, 9}};
}
*/
Matrice::Matrice(const int nbLignes, const int nbColonnes, double coef)
{
	nbLig = nbLignes;
	nbCol = nbColonnes;
	matrice = new double*[nbLignes];
	for(int i = 0;i < nbLignes;++i) 
	{
		matrice[i] = new double[nbColonnes];
	}
	for(int i = 0;i < nbLignes;++i) 
	{
		for (int j = 0;j < nbColonnes;++j)
		{
			matrice[i][j] = coef;
		}
	}
}

//Constructeur par recopie
Matrice::Matrice (const Matrice & mat)
{
	nbLig = mat.nbLig;
	nbCol = mat.nbCol;
	matrice = new double*[nbLig];
	for(int i = 0;i < nbLig;++i) 
	{
		matrice[i] = new double[nbCol];
	}
	for(int i=0; i<nbLig;i++)
	{
		for(int j=0; j<nbCol; j++)
		{
			matrice[i][j] = mat.matrice[i][j];
		}
	}
}

//Destructeur
Matrice::~Matrice()
{
    for(int i = 0;i < nbLig;++i) delete [] matrice[i];
    delete [] matrice;
    nbLig=0;
    nbCol=0;
}

double** Matrice::getMatrice()
{
	return matrice;
}

// Retourne l'élément ij de la matrice
double Matrice::getCoefMatrice(int i, int j)
{
	if (i>=nbLig || (j>=nbCol)) 
	{
		throw std::length_error("Erreur indices");
	}
	return matrice[i][j];
}

//Set le coefficient (i,j) de la matrice
void Matrice::setCoefMatrice(int i, int j, double coef)
{
	if (i>=nbLig || (j>=nbCol)) 
	{
		throw std::length_error("Erreur indices");
	}
	matrice[i][j] = coef;
}

//initialise alétatoirement la matrices
void Matrice::initAleatoire()
{
		for (int i=0; i< nbLig; i++)
		{
			for (int j=0; j< nbCol; j++)
			{
				double coef = (double) rand()/RAND_MAX;
				setCoefMatrice(i, j, coef);
			}
		}
}

//A placer dans un bloc try & catch
Matrice Matrice::operator *(const Matrice &m)
{
	//m1 (matrice) nbLig x nbCol ; m2 (m) m.nbLig x m.nbCol
	//avec nbCol = m.nbLig
	if (nbCol != m.nbLig) 
	{
		throw std::length_error("Erreur taille matrice");
	}
	
    Matrice mat = Matrice(nbLig, m.nbCol);

	//Produit matricielle
	for (int i=0;i<nbLig;i++)
	{
		for (int j=0;j<m.nbCol;j++)
		{
			for (int k=0;k<nbCol;k++)
			{
				mat.matrice[i][j]= matrice[i][k]*m.matrice[k][j]+mat.matrice[i][j];
			}
		}
	}
    return mat;
}

//A placer dans un bloc try & catch
Matrice Matrice::operator +(const Matrice &m)
{
	//m1 (matrice) nbLig x nbCol ; m2 (m) m.nbLig x m.nbCol
	//avec nbCol = m.nbLig
	if ((nbCol != m.nbCol) || (nbLig != m.nbLig)) 
	{
		throw std::length_error("Erreur taille matrice");
	}
	
    Matrice mat = Matrice(nbLig, nbCol);

	for (int i=0;i<nbLig;i++)
	{
		for (int j=0;j<nbCol;j++)
		{
			mat.matrice[i][j]= matrice[i][j] + m.matrice[i][j]; //Somme coef par coef
		}
	}
    return mat;
}

Matrice Matrice::operator -(const Matrice &m)
{
	//m1 (matrice) nbLig x nbCol ; m2 (m) m.nbLig x m.nbCol
	//avec nbCol = m.nbLig
	if ((nbCol != m.nbCol) || (nbLig != m.nbLig)) 
	{
		throw std::length_error("Erreur taille matrice");
	}
	
    Matrice mat = Matrice(nbLig, nbCol);

	for (int i=0;i<nbLig;i++)
	{
		for (int j=0;j<nbCol;j++)
		{
			mat.matrice[i][j]= matrice[i][j] - m.matrice[i][j]; //Soustraction coef par coef
		}
	}
    return mat;
}