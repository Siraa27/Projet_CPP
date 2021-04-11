#ifndef COUCHEENTREES_HPP
#define COUCHEENTREES_HPP
#include "Couche.hpp"

/*!
 * \file CoucheEntrees.hpp
 * \brief la couche entrée permet de convertir nos données et d'initialiser les entrées de notre réseau
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_reseau
 * Classe qui permet de créer des couches du réseau
 */

namespace Les_couches_du_reseau 
{
   /*! \class CoucheEntrees
   * \brief Classe representant une couche
   *
   *  C'est la classe qui génère les couches du réseau
   */
    class CoucheEntrees : public Couche{
        
        //Les méthodes
        public :
             /*!
             *  \brief Constructeur de la classe CoucheEntrees
             *  \param nbNeurones : nombre de neurones par couche, fixe d'où le "const"
             */
		  CoucheEntrees (const int nbNeurones); /*!<  nb de Neurones d'une couche ne change pas une fois choisi au cours du programme */
             
             /*!
             *  \brief Destructeur de la classe CoucheEntrees
             */
          virtual ~CoucheEntrees();
        
            /*! \fn constructionSortie 
             *  \brief 
             *  initialise les données
             *  \return Les entrées du réseau
             */
          void constructionSortie();
    };
};

#endif
