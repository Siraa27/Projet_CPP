#ifndef NEURONE_HPP
#define NEURONE_HPP
/*!
 * \file Neurone.hpp
 * \brief Les propritées d'un neurone : son indice et so valeur
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_reseau
 * Classe qui permet de créer des neurones
 */
namespace Les_couches_du_reseau 
{
    /*! \class Neurone
   * \brief Classe représentant un neurone
   */
    class Neurone{
         //Les attributs
        private : 
         int indice ; /*!< Une couche peut contenir plusieurs neurones. Pour isoler un neurone, on lui assigne un indice */
         double sortie ; 
        // Les méthodes
        public : 
         /*!
         *  \brief Constructeur classe Neurone
         *  \param indice : le libellé d'un neurone dans une couche 
         */
        Neurone (const int indice); // le libellé d'un neurone dans une couche ne change pas une fois choisi au cours du programme
         /*! \fn calculSortie
         *  \brief 
         *  elle s'occupe de la pré-activation et de l'activation du neurone 
         *  \return la valeur en sortie d'un neurone
         */
        double calculSortie(double entree);
    };
    
};
#endif 
