#include "Matrice.hpp"
#include <stdexcept>

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

void Matrice::initAleatoire()
{
		for (int i=0; i< nbLig; i++)
		{
			
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
			mat.matrice[i][j]= matrice[i][j] + m.matrice[i][j];
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
			mat.matrice[i][j]= matrice[i][j] - m.matrice[i][j];
		}
	}
    return mat;
}