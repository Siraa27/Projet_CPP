#ifndef COUCHE_HPP
#define COUCHE_HPP
#include "Neurone.hpp"
/*!
 * \file Couche.hpp
 * \brief Les propriétés d'une couche : son nombre de neurones ainsi que sa fonction d'activation
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les couches du reseau
 * Classe représentnant les couches du réseau
 */
namespace Les_couches_du_reseau 
{
   /*! \class Couche
   * \brief Classe représentant une couche
   */
    class Couche{
         //Les attributs
         private : 
          int nbNeurones; /*!< Le nombre de neurones d'une couche*/
          Neurone* Neurones; /*!< Le tableau qui contient tous les neurones d'une couche*/
          int indice ; /*!< L'indice d'un neurone*/

         //Les méthodes
         public :
             /*!
             *  \brief Constructeur de la classe Couche
             *  \param nbNeurones : nombre de neurones par couche, fixe d'où le "const"
             */
		  Couche (const int nbNeurones); /*!<  nb de Neurones d'une couche ne change pas une fois choisi au cours du programme */
             
             /*!
             *  \brief Destructeur de la classe Couche
             */
          virtual ~Couche();
          
             /*!
             *  \fn preActivation()
             *  \brief La fonction de pré activation
             *  Méthode qui permet de faire la somme pondérée des entrées
             *  \return Somme pondérée des entrées. Le résultat est passé en paramètre de la fonction d'activation
             */
          double preActivation(const double sum);
            
             /*!
             *  \fn foncActivation(const double sum)
             *  \brief La fonction d'activation 
             *  Méthode qui permet d'activer les neurones afin d'optimiser le biais et avoir le bon résultat en sortie
             *	\param sum : somme pondérée des entrées
             *  \return la valeur du neurone après l'activation
             */
          double foncActivation(const double sum);
    };
};
#endif
