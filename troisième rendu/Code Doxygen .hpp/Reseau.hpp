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
             *  Constructeurs de la classe Reseau
             *
             */
          Reseau();
             /*! 
             *
             *  \param listeParametres : liste introduite par le biais de la classe InterfaceUtilisateur fournissant les parametres nécessaires à la construction du réseau
             */
          Reseau(Liste listeParametres); /*!< Constructeur prenant en compte les paramètres fourni par l'utilisateur via un fichier ou non */
             /*!
             *  \brief Destructeur de Reseau
             */
          ~Reseau();
          
              /*!
             *  \fn ajouterCouche(Couche c, int numCouche)
             *  \brief La fonction ajoute une couche au réseau 
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
             *  \fn Apprentissage(Fichier Données);
             *  \brief La fonction permet l'apprentissage du réseau de neurone en prenant en argument les données fournis en entrée
             *
             *  Méthode permettant d'obtenir un réseau efficace à partir d'un fichier donné
             *
             *  \return Rien mais modifie le réseau
             * 
             */
	      void Apprentissage(Fichier Données);
          
            /*!
             *  \fn backPropagation(Liste Entrées x, Liste Sorties y);
             *  \brief applique la méthode essentielle de la backPropagation
             *
             *
             *  \return Rien mais modifie le réseau
             * 
             */
	  void backPropagation(Liste Entrées x, Liste Sorties y);
	  /*!
             *  \fn CalcGradC(Sorties sAttendues, Sorties sCalculées);
             *  \brief La fonction est celle de descente du gradient.
             *
             *
             *  \return le vecteur correspondant au gradient de l'erreur par rapport à tous les poids et les biais à l'étape p+1
             * 
             */
	  tableau CalcGradC(Sorties sAttendues, Sorties sCalculées);
	}; 

	  
};
#endif
