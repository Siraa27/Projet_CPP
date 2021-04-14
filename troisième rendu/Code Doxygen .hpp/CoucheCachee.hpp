#ifndef COUCHE_CACHEE_HPP
#define COUCHE_CACHEE_HPP
#include "Couche.hpp"

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
    };
};

#endif
