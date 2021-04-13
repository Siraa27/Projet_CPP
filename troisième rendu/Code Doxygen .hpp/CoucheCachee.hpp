#ifndef COUCHECACHEE_HPP
#define COUCHECACHEE_HPP
#include "Couche.hpp"

/*!
 * \file CoucheCachee.hpp
 * \brief C'est un classe qui permet de créer les couches cachées du réseau, ainsi que de définir leur biais
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_reseau
 * Classe qui permet de créer des couches du réseau
 */


namespace Les_couches_du_reseau 
{
   /*! \class CoucheCachees
   * \brief Classe représentant une couche cachée
   *
   */
    class CoucheCachee: public Couche{
        //Les attributs
        private :   double biais ; /*!< Le biais qui va être optimisé lorsque le programme va tourner pour */

        //Les méthodes
        public :
             /*!
             *  \brief Constructeur de la classe CoucheCachée
             *  \param nbNeurones : nombre de neurones par couche, fixe d'où le "const"
             */
		  CoucheCachee (const int nbNeurones); /*!<  nb de Neurones d'une couche ne change pas une fois choisi au cours du programme */
             
             /*!
             *  \brief Destructeur de la classe Couche
             */
          virtual ~CoucheCachee(Couche Entrées);
          
            /*! \fn calculSortie 
             *  \brief Elle retourne la valeur en sortie de la couche après la pré-activation et l'activation 
             *  \param La couche en entrée
             *  \return la valeur en sortie d'une couche 
             */
         void calculSortie();
    };
};

#endif
