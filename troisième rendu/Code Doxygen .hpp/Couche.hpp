#ifndef COUCHE_HPP
#define COUCHE_HPP
#include "Neurone.hpp"
/*!
 * \file Couche.hpp
 * \brief Les propriétés d'une couche : son nombre de neurones ainsi que sa fonction d'activation
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_reseau
 * Ensemble de classes représentant toutes les couches du réseau
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
             *  \param const int nbNeurones : entier représentant le nombre de neurones d'une couche ne change pas une fois choisi au cours du programme
             */
		  Couche (const int nbNeurones); 
             /*!
             *  \brief Destructeur de la classe Couche 
             */
          virtual ~Couche();
         
    };
};
#endif
