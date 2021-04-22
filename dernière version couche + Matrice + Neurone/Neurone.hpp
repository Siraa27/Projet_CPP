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
//namespace Les_couches_du_reseau 
//{
    /*! \class Neurone
   * \brief Classe représentant un neurone
   */
    class Neurone{
         //Les attributs
        private : 
         static int nbNeuronesTotal; /*!< Nombre total de neurones dans le réseau */
         int indice ; /*!< Une couche peut contenir plusieurs neurones. Pour isoler un neurone, on lui assigne un indice */
         double sortie ; /*!< Valeur que contient le neurone en sortie (donc après avoir appliqué la pré-activation et l'activation) */
        // Les méthodes
        public : 
         /*!
         *  \brief Constructeur classe Neurone
         *  \param indice : le libellé d'un neurone dans une couche 
         */
        Neurone (double out=0); // le libellé d'un neurone dans une couche ne change pas une fois choisi au cours du programme
         /*! \fn setSortie
         *  \brief 
         *  elle modifie la valeur du neurone après application des fonctions de pré-activation et d'activation (présentes dans la fonction calculSortie() de la classe CoucheCachée)
         */
        void setSortie(double S);
         /*! \fn getSortie
         *  \brief 
         *  Renvoie la sortie du neurone
         */
        double getSortie() const;
         /*! \fn getIndice
         *  \brief 
         *  Renvoie l'indice du neurone
         */
        int getIndice() const;
    };
    
//};
#endif 
