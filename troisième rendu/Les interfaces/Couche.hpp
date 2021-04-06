-#ifndef COUCHE_HPP
#define COUCHE_HPP
/*!
 * \file Couche.hpp
 * \brief Les propritées d'une couche : ses nombre de neurones ainsi que sa fonction d'activation
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_réseau
 * une classe qui permets de créer des couches du réseau
 */
namespace Les_couches_du_réseau 
{
    /*! \class Couche
   * \brief classe representant une couche
   *
   *  La classe génère les couches du réseau
   */
    class Couche{

         protected : 
          int nbNeurones; /*!< Le nombre de neurones d'une couches*/
          Neurone Neurones[]; /*!< Le tableau qui contient tous les neurones d'une couche*/
          int indice ; /*!< L'indice d'un neurone*/

         public :
             /*!
             *  \brief Constructeur
             *
             *  Constructeur de la classe Couche
             *
             *  \param nbNeurones : le nombre de neurones par couche, qui est fixe d'ou le "const"
             */
          Couche (const nbNeurones); // le nb de Neurones d'une couche ne change pas une fois choisit au cours du programmes
             /*!
             *  \brief Destructeur
             *
             *  Destructeur de la classe Couche
             */
          virtual ~Couche();
             /*!
             *  \brief La fonction d'activation 
             *
             *  Methode qui permet d'avoir la sortie d'une couche
             *
             *  \return la valeur en sortie d'une couche 
             *  pour l'exemple des iris de Fisher elle doit nous fournir un vecteur (1,0,0) si la fleur appartient à la classe 1
             */
          double foncActivation();
    };
};
#endif