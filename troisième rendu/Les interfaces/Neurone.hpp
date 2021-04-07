#ifndef NEURONE_HPP
#define NEURONE_HPP
/*!
 * \file Neurone.hpp
 * \brief Les propritées d'un neurone : son indice et so valeur
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_réseau
 * une classe qui permets de créer des neurones
 */
namespace Les_couches_du_réseau 
{
    /*! \class Neurone
   * \brief classe representant un neurone
   *
   *  La classe génère les neurones d'une couche
   */
    class Neurone{
         //Les attributs
        private : 
         int indice ; /*!< Une couche peut contenir plusieurs Neurones pour isoler un neurone on lui accorde un indice */
         double sortie ; 
        // Les méthodes
        public : 
         /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Neurone
         *
         *  \param indice : le libelé d'un neurone dans une couche 
         */
        Neurone (const int indice); // le libelé d'un neurone dans une couche ne change pas une fois choisit au cours du programmes
         /*! \fn calculSortie
         *  \brief 
         *  elle s'occupe de la pré-activation et de l'activation du neuronne 
         *  \return la valeur en sortie d'un neurone
         */
        double calculSortie(int entree);
    };
};
#endif 
