#ifndef MATRICE_HPP
#define MATRICE_HPP
/*!
 * \file Matrice.hpp
 * \brief Une classe simple qui définit quelques opérations matricielles
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_types_de_réseaux
 * Classe qui permet de manipuler des matrices
 */
namespace Les_types_de_réseaux
{
   /*! \class Matrice
   *
   *
   */
    class Matrice{
         //Les attributs
         private :
          double *(*coefficients); /*!< Tableau dynamique*/

         //Les méthodes
         public :
             /*!
             *  \brief Constructeur
             *
             */
          Matrice (int nbLignes, int nbColonnes);
             /*!
             *  \brief Destructeur
             *
             *  Destructeur de la classe Couche
             */
          virtual ~Matrice();
          /*!
          *  \fn initAleatoire()
          *  \brief Pour initialiser les poids de manière aléatoire entre 0 et 1
          *
          */
         void initAleatoire();

         /*!
         *  \fn prodMatriciel(Matrice m)
         *  \brief calcul le produit matriciel
         *
         */
        void prodMatriciel(Matrice m); //a corriger !!!!!!!!

    };
};
#endif
