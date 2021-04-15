#ifndef MATRICE_HPP
#define MATRICE_HPP
/*!
 * \file Matrice.hpp
 * \brief Une classe qui définit quelques opérations matricielles
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_types_de_reseaux
 * Classe pour manipuler des matrices (pour la matrice  des liaisons)
 */
namespace Les_types_de_reseaux
{
   /*! \class Matrice
   */
    class Matrice{
         //Les attributs
         private :
          double *(*coefficients); /*!< Tableau dynamique*/

         //Les méthodes
         public :
             /*!
             *  \brief Constructeur Matrice
             */
          Matrice (const int nbLignes, const int nbColonnes);
          
             /*!
             *  \brief Destructeur Matrice
             */
          virtual ~Matrice();
          
          /*!
          *  \fn initAleatoire()
          *  \brief Pour initialiser les poids de manière aléatoire entre 0 et 1
          */
          void initAleatoire();

          /*!
          *  \fn operator * (Matrice m)
          *  \brief surcharge l'opérateur * pour nos matrices
          *
          */
          Matrice operator *(const Matrice &); 
    };
};
#endif
