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

//namespace Les_types_de_reseaux
//{
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
             /*!
             *  \brief Constructeur Matrice par recopie
             */
		  Matrice (const Matrice &);
          
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
          *  \brief surcharge l'opérateur * pour nos Matrices
          *
          */
          Matrice operator *(const Matrice &); 
          
          /*!
          *  \fn getMatrice
          *  \brief retourne matrice**
          *
          */
          double** getMatrice();
    };
//};
#endif
