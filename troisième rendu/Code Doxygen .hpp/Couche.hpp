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
          double biais[] ; /*!< Le biais qui va être optimisé lorsque le programme va tourner pour */
          Matrice LiaisonsEntrees; /*!< Matrice des poids initialisée en entrée via l'InterfaceUtilisateur */

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
          
             /*!
             *  \fn preActivation()
             *  \brief La fonction de pré activation : méthode qui permet de faire la somme pondérée des entrées
             *  \return Somme pondérée des entrées. Le résultat est passé en paramètre de la fonction d'activation
             */
          double preActivation();
            
             /*!
             *  \fn foncActivation()
             *  \brief La fonction d'activation : méthode qui permet d'activer les neurones afin d'optimiser le biais et avoir le bon résultat en sortie
             *  \param const double sum : résultat de la fonction de pré-activation qui calcule la somme de tous les neurones de la couche précédente pondérée avec leur poids respectif et du biais associé au neurone
             *  \return la valeur du neurone après l'activation
             */
          double foncActivation(const double sum);
    };
};
#endif
