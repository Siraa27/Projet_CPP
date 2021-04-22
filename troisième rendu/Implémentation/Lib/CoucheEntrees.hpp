#ifndef COUCHEENTREES_HPP
#define COUCHEENTREES_HPP
#include "Couche.hpp"
#include <string> 

/*!
 * \file CoucheEntrees.hpp
 * \brief la couche entrée permet de convertir nos données et d'initialiser les entrées de notre réseau
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_reseau
 * Classe qui permet de créer des couches du réseau
 */

//namespace Les_couches_du_reseau 
//{
   /*! \class CoucheEntrees
   * \brief Classe représentant la couche d'entrée
   *
   */
    class CoucheEntrees : public Couche{
        
        //Les méthodes
        public :
             /*!
             *  \brief Constructeur de la classe CoucheEntrees
             *  \param nbNeurones : nombre de neurones par couche, NomFic : nom du fichier pour initialiser
             */
		    CoucheEntrees (const int nbNeurones, std::string nomFic); /*!<  Le nombre de neurones d'une couche ne change pas au cours du programme une fois fixé  */
             
             /*!
             *  \brief Destructeur de la classe CoucheEntrees
             */
          ~CoucheEntrees();
        
            /*! \fn constructionSortie 
             *  \brief La fonction initialise les données en entrée
             *  \return Les entrées du réseau
             */
          void constructionSortie(std::string nomFic);
    };
//};

#endif
