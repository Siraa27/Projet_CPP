#ifndef COUCHE_HPP
#define COUCHE_HPP
#include "Neurone.hpp"
#include "Matrice.hpp"
#include <ostream> 
#include <vector>

/*!
 * \file Couche.hpp
 * \brief Les propriétés d'une couche : son nombre de neurones ainsi que sa fonction d'activation
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_reseau
 * Ensemble de classes représentant toutes les couches du réseau
 */

/*! \class Couche
* \brief Classe représentant une couche
*/
class Couche{
   //Les attributs
   private : 
      int nbNeurones; /*!< Le nombre de neurones d'une couche*/
      std::vector<Neurone> Neurones; /*!< Le tableau qui contient tous les neurones d'une couche*/
   
   //Les méthodes
   public :
      /*!
      *  \brief Constructeur de la classe Couche
      *  \param const int nbNeurones : entier représentant le nombre de neurones d'une couche ne change pas une fois choisi au cours du programme
      */
	   Couche (const int nbN); 
      
      /*!
      *  \brief Constructeur par recopie
      */
      Couche(Couche &c);

      /*!
      *  \brief Destructeur de la classe Couche 
      */
      virtual ~Couche();
 
      /*! \fn getNbNeurones
      *  \brief 
	   *  Renvoie nombre total de neurones
		*/
		int getNbNeurones() const;    
		
      /*! \fn getNeurone
      *  \brief 
		*  Retourne le ieme neurone
		*/
		Neurone getNeurone(int i) const;
     
      /*! \fn recupSortiesNeurones
      *  \brief 
		*  recupere la sorties de tous les neurones d'une couche
		*/
		Matrice recupSortiesNeurones() const;

      /*! \fn modifNeurones
      *  \brief 
		*  modifie le neurone i de la couche 
		*/
      void modifNeurone(int i, double s);

      friend std::ostream & operator <<(std::ostream & flux, const Couche& C);
};
#endif
