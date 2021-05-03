#ifndef Matrice_HPP
#define Matrice_HPP
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
      double ** matrice; /*!< Tableau dynamique*/
      int nbLig;
		int nbCol;

   //Les méthodes
   public :
      /*!
      *  \brief Constructeur Matrice
      */
      Matrice (const int nbLignes, const int nbColonnes);
      Matrice(const int nbLignes, const int nbColonnes, double coef);
      Matrice(const int nbLignes, const int nbColonnes, double** t);

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
      double** getMatrice();

      /*!
      *  \fn getCoefMatrice
      *  \brief retourne matrice[i][j]
      *
      */
      double getCoefMatrice(int i, int j);

      /*!
      *  \fn setCoefMatrice
      *  \brief Set un coefficient de la matrice
      *
      */
      void setCoefMatrice(int i, int j, double coef);

      /*!
      *  \fn setCoefs
      *  \brief Set tous les coefs de la matrice à coef
      *
      */
      void setCoefs(double coef);

      /*!
      *  \fn divMatrice
      *  \brief divise tous les coefs de la matrice par coef
      *
      */
      void divMatrice(double coef);
};
#endif
