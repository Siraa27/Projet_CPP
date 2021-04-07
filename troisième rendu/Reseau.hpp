#include <iostream>
#include <string>
#include <list>

#ifndef RESEAU_HPP
#define RESEAU_HPP

using namespace std;

// Classe abstraite JE CROIS PAS QUE CE SOIT UNE CLASSE ABSTRAITE EN FAIT OMG




#endif

#ifndef RESEAU_HPP
#define RESEAU_HPP
#include "Reseau.hpp"
/*!
 * \file Reseau.hpp
 * \brief Les propriétés d'un réseau : le nombre de couches qui le compose, ses couches, et sa matrice de liaison
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_types_de_réseaux
 * une classe qui permet de créer un certain type de réseau
 */
namespace Les_types_de_réseaux 
{
   /*! \class Reseau
   * \brief classe representant un réseau
   *
   *  La classe génère le réseau
   */
  class Reseau { 
 

	// Les attributs
	protected:  /*!< Pour que les classes filles aient également accès à ces attributs */
		static Couche Couches[];
		static int nbC;	 //nombre de couches 
		static double MatriceLiaisons[][];

	
	// Les constructeurs
	/*!
             *  \brief Constructeurs
             *
             *  Constructeurs de la classe Couche
             *
             *	\param :
             */
          Reseau();
             /*! 
             *
             *  \param nbC : le nombre de couches qui est fixe d'où le "const"
             */
          Reseau(const int nbC); /*!< Constructeur pour le cas ou l'utilisateur décide du nombre de couches */
             /*!
             *  \brief Destructeur
             *
             *  Destructeur de la classe Reseau
             */
          ~Reseau();
             /*!
	
	// Les methodes
	public: 
		void ajouterCouche(Couche c, int numCouche);
		double erreur(Fichier SortiesAttendues)
		void ApprentissageSupervisé(Fichier Données);
		void ApprentissageNonSupervisé(Fichier Données);
		
	
}; 
   
   /*!
             *  \fn ajouterCouche(Couche c, int numCouche)
             *  \brief La fonction qui ajoute une couche au réseau 
             *
             *  Methode qui permet d'ajouter autant de couches que l'on veut ou qu'il est mentionné
             *
             *  \return rien mais modifie le réseau
             * 
             */
          void ajouterCouche(Couche c, int numCouche);
             
              /*!
             *  \fn double erreur(Fichier SortiesAttendues)
             *  \brief La fonction qui calcule l'erreur commise par le réseau donc qui indique sa précision
             *
             *  Methode qui permet de calculer l'erreur commise par le réseau donc d'indiquer sa précision
             *
             *  \return la valeur de la mesure de l'erreur à l'instant t
             * 
             */
	  double erreur(Fichier SortiesAttendues)
          
             /*!
             *  \fn ApprentissageSupervisé(Fichier Données);
             *  \brief La fonction qui dirige le réseau vers un apprentissage supervisé en prenant en argument les données fournis en entrée
             *
             *  Methode qui permet d'obtenir un réseau pour l'apprentissage supervisé à partir d'un fichier donné
             *
             *  \return rien mais modifie le réseau
             * 
             */
	  void ApprentissageSupervisé(Fichier Données);
          
            /*!
             *  \fn ApprentissageNonSupervisé(Fichier Données);
             *  \brief La fonction qui dirige le réseau vers un apprentissage non supervisé en prenant en argument les données fournis en entrée
             *
             *  Methode qui permet d'obtenir un réseau pour l'apprentissage non supervisé à partir d'un fichier donné
             *
             *  \return rien mais modifie le réseau
             * 
             */
	  void ApprentissageNonSupervisé(Fichier Données);
