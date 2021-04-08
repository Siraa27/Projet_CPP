#ifndef COUCHEENTREES_HPP
#define COUCHEENTREES_HPP
#include "Couche.hpp"

/*!
 * \file CoucheEntrées.hpp
 * \brief C'est un classe qui permet de créer les couches cachées du réseau, ainsi que de définir leur biais
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_réseau
 * Classe qui permet de créer des couches du réseau
 */

namespace Les_couches_du_réseau 
{
   /*! \class Couche
   * \brief Classe representant une couche
   *
   *  C'est la classe qui génère les couches du réseau
   */
    class CoucheCachee: public Couche{
        
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
