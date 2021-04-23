#ifndef COUCHE_CACHEE_HPP
#define COUCHE_CACHEE_HPP
#include "Couche.hpp"
#include "Matrice.hpp"

/*!
 * \file CoucheCachee.hpp
 * \brief C'est un classe qui permet de créer les couches cachées du réseau, ainsi que de définir leur biais
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_reseau
 */

namespace Les_couches_du_reseau 
{
   /*! \class CoucheCachee
   * \brief Classe représentant une couche cachée
   *
   */
    class CoucheCachee : public Couche{
        // Les attributs 
            private : 
            Matrice biais[] ; /*!< Le biais qui va être optimisé lorsque le programme va tourner pour */
            Matrice LiaisonsEntrees; /*!< Matrice des poids initialisée en entrée via l'InterfaceUtilisateur */
        
        //Les méthodes
        public :
             /*!
             *  \brief Constructeur de la classe CoucheCachee
             *  \param nbNeurones : nombre de neurones par couche, fixe d'où le "const"
             */
		  CoucheCachee (const int nbNeurones); /*!<  Le nombre de neurones d'une couche ne change pas au cours du programme une fois fixé  */
             
             /*!
             *  \brief Destructeur de la classe CoucheCachee
             */
          virtual ~CoucheCachee();
        
             /*! \fn calculSortie
             *  \brief Elle retourne la valeur en sortie de la couche après la pré-activation et l'activation
             *  \param La couche en entrée
             *  \return la valeur en sortie d'une couche 
             */
          void calculSortie(Couche Entrees);
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
