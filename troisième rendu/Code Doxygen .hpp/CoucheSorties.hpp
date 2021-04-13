#ifndef COUCHESORTIES_HPP
#define COUCHESORTIES_HPP
#include "Couche.hpp"

/*!
 * \file CoucheSorties.hpp
 * \brief C'est un classe qui permet de créer la couche de sorties du réseau, ainsi que de définir leur biais
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_reseau
 * Classe qui permet de créer des couches du réseau
 */

namespace Les_couches_du_reseau 
{
  /*! \class CoucheSorties
   * \brief Classe représentant la couche de sorties 
   *
   */
    class CoucheSorties: public Couche{
        //Les attributs
        private :   
		 double biais ; /*!< Le biais qui va être optimisé lorsque le programme va tourner pour */

        //Les méthodes
        public :
             /*!
             *  \brief Constructeur de la classe CoucheSorties
             */
		  CoucheSorties(); /*!<  nb de Neurones d'une couche ne change pas une fois choisi au cours du programme */
             
             /*!
             *  \brief Destructeur de la classe CoucheSorties
             */
          virtual ~CoucheSorties();
          
            /*! \fn constructionSorties 
             *  \brief La fonction calcule la sortie du réseau
             *  \return résultat du reseau
             */
         void constructionSorties();
    };
};

#endif
