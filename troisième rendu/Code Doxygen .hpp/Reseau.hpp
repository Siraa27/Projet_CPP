#ifndef RESEAU_HPP
#define RESEAU_HPP
#include "Couche.hpp"

using namespace std;
/*!
 * \file Reseau.hpp
 * \brief Les propriétés d'un réseau : le nombre de couches qui le compose, ses couches, et sa matrice de liaison
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_types_de_reseaux
 * Permet de créer un certain type de réseau
 */
namespace Les_types_de_reseaux 
{
   /*! \class Reseau
   * \brief Classe représentant un réseau
   *
   *  Elle permet de générer un réseau
   */
  class Reseau { 
 

	// Les attributs
	protected: 	 /*!< Pour que les classes filles aient également accès à ces attributs */
		Couche Couches[];
		int nbCouche;
		double MatriceLiaisons[][];
	
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
          Reseau(const int nbC); /*!< Constructeur pour le cas où l'utilisateur décide du nombre de couches */
             /*!
             *  \brief Destructeur de Couche
             */
          ~Reseau();
          
              /*!
             *  \fn ajouterCouche(Couche c, int numCouche)
             *  \brief La fonction qui ajoute une couche au réseau 
             *  Méthode permettant d'ajouter autant de couches que l'on veut ou qu'il est mentionné dans le programme. 
             */
          void ajouterCouche(Couche c, int numCouche);
             
              /*!
             *  \fn double erreur(Fichier SortiesAttendues)
             *  \brief La fonction calcule l'erreur commise par le réseau donc indique sa précision
             *
             *  Méthode permettant de calculer l'erreur commise par le réseau à l'aide de l'algorithme de descente de gradient.
             *
             *  \return valeur de la mesure de l'erreur à l'instant t
             * 
             */
	      double erreur(Fichier SortiesAttendues)
          
             /*!
             *  \fn ApprentissageSupervisé(Fichier Données);
             *  \brief La fonction dirige le réseau vers un apprentissage supervisé en prenant en argument les données fournis en entrée
             *
             *  Methode permettant d'obtenir un réseau pour l'apprentissage supervisé à partir d'un fichier donné
             *
             *  \return Rien mais modifie le réseau
             * 
             */
	      void ApprentissageSupervise(Fichier Données);
          
            /*!
             *  \fn ApprentissageNonSupervisé(Fichier Données);
             *  \brief La fonction dirige le réseau vers un apprentissage non supervisé en prenant en argument les données fournis en entrée
             *
             *  Méthode permettant d'obtenir un réseau pour l'apprentissage non supervisé à partir d'un fichier donné
             *
             *  \return Rien mais modifie le réseau
             * 
             */
	  void ApprentissageNonSupervisé(Fichier Données);
	}; 
	  
};
#endif
