#ifndef COUCHESORTIES_HPP
#define COUCHESORTIES_HPP
#include "Couche.hpp"

/*!
 * \file CoucheSorties.hpp
 * \brief C'est un classe qui permet de créer la couche de sorties du réseau, ainsi que de définir leur biais
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_réseau
 * une classe qui permet de créer des couches du réseau
 */

namespace Les_couches_du_réseau 
{
   /*! \class Couche
   * \brief classe representant une couche
   *
   *  La classe génère les couches du réseau
   */
    class CoucheSorties: public Couche{
        //Les attributs
        private :   double biais ; /*!< Le biais qui va être optimisé lorsque le programme va tourner pour */

        //Les méthodes
        public :
            /*! \fn sortie 
             *  \brief 
             *  ELle retourne la valeur en sortie de la couche après l'activation 
             *  \return la valeur en sortie d'une couche 
             */
         void sortie();
    };
};

#endif
