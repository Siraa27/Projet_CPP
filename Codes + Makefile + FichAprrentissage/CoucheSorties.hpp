#ifndef COUCHESORTIES_HPP
#define COUCHESORTIES_HPP
#include "Couche.hpp"
#include "Matrice.hpp"
#include "Neurone.hpp"
#include <iostream>
#include <math.h> 

/*!
 * \file CoucheSorties.hpp
 * \brief C'est un classe qui permet de créer la couche de sorties du réseau, ainsi que de définir leur biais
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_reseau
 * Classe qui permet de créer des couches du réseau
 */

/*! \class CoucheSorties
* \brief Classe représentant la couche de sorties 
*
*/
class CoucheSorties: public Couche{
   // Les attributs 
   private : 
      Matrice biais; /*!< Le biais qui va être optimisé lorsque le programme va tourner pour */
      Matrice LiaisonsEntrees; /*!< Matrice des poids */

      //Les méthodes
      public :
      CoucheSorties(const CoucheSorties&);
      /*!
      *  \brief Constructeur de la classe CoucheSorties
      */
		CoucheSorties(const int nbNeurones=0, const int nbNeuronesCouchePrec=0); /*!<  nb de Neurones d'une couche ne change pas une fois choisi au cours du programme */
      
      /*!
      *  \fn getLiaisonEntrees()
      *  \brief Ce qui nous permet d'acceder a la matrice LiaisonEntrees de la couche
      *  \return matrice des liaisons
      */
      Matrice& getLiaisonEntrees();
      
      /*!
      *  \fn getBiais()
      *  \brief Ce qui nous permet d'acceder a la matrice biais de la couche
      *  \return matrice des biais
      */
      Matrice& getBiais();

      /*!
      *  \fn preActivation()
      *  \brief La fonction de pré activation : méthode qui permet de faire la somme pondérée des entrées
      *  \return matrice des sommes pondérées des entrées pour chaque neurone
      */
      Matrice preActivation(const Couche couchePrec);
            
      /*!
      *  \fn foncActivation()
      *  \brief La fonction d'activation : méthode qui permet d'activer les neurones afin d'optimiser le biais et avoir le bon résultat en sortie
      *  \param Matrice résultant de la fonction de pre activation
      *  \return Elle modifie directement la sortie des neurones
      */
      void foncActivation(Matrice sum);
            
      /*!
      *  \fn derivFoncActivation()
      *  \brief Derivee de la fonction d'activatino
      *  \return valeur de la derivee evaluee en x
      */
      double derivFoncActivation(const double x); //Derivee de la sigmoid
          
      /*! \fn constructionSorties 
      *  \brief La fonction calcule la sortie du réseau
      *  \return résultat du reseau
      */
      void constructionSorties(); //Pas encore implémentée
};

#endif
