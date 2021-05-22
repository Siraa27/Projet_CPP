#ifndef Matrice_HPP
#define Matrice_HPP
#include <stdexcept>
#include <random>
#include <vector>

using namespace std;

/*!
 * \file Matrice.hpp
 * \brief Une classe qui définit quelques opérations Matricericielles
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_types_de_reseaux
 * Classe pour manipuler des Matrices (pour la Matrice  des liaisons)
 */

/*! \class Matrice
*/
class Matrice{
   //Les attributs
   private :
      vector<vector<double>> matrice; 
      int nbLig;
		int nbCol;

   //Les méthodes
   public :
      /*!
      *  \brief Constructeur Matrice
      */
      Matrice (const int nbLignes, const int nbColonnes);
      Matrice(const int nbLignes, const int nbColonnes, double coef);
      Matrice(const int nbLignes, const int nbColonnes, vector<vector<double>> m);

      /*!
      *  \brief Constructeur Matrice par recopie
      */
		Matrice (const Matrice &);

      /*!
      *  \brief Destructeur Matrice
      */
      ~Matrice();

      /*!
      *  \fn initAleatoire()
      *  \brief Pour initialiser les poids de manière aléatoire entre 0 et 1
      */
      void initAleatoire();

      /*!
      *  \fn operator * (Matrice m)
      *  \brief surcharge l'opérateur * pour nos Matrices
      *
      */
      Matrice operator *(const Matrice &);

      /*!
      *  \fn operator + (Matrice m)
      *  \brief surcharge l'opérateur + pour nos Matrices
      *
      */
      Matrice operator +(const Matrice &);

      /*!
      *  \fn operator - (Matrice m)
      *  \brief surcharge l'opérateur - pour nos Matrices
      *
      */
      Matrice operator -(const Matrice &);

      /*!
      *  \fn getMatrice
      *  \brief retourne matrice**
      *
      */
      vector<vector<double>> getMatrice() const;

      int getnbLig() const;

      int getnbCol() const; 

      /*!
      *  \fn getCoefMatrice
      *  \brief retourne matrice[i][j]
      *
      */
      double getCoefMatrice(const int i,const int j) const;

      /*!
      *  \fn setCoefMatrice
      *  \brief Set un coefficient de la matrice
      *
      */
      void setCoefMatrice(const int i,const int j,const double coef);

      /*!
      *  \fn setCoefs
      *  \brief Set tous les coefs de la matrice à coef
      *
      */
      void setCoefs(const double coef);

      /*!
      *  \fn divMatrice
      *  \brief divise tous les coefs de la matrice par coef
      *
      */
      void divMatrice(const double coef);
};
#endif
