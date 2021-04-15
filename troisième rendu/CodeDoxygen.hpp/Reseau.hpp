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
   */
  class Reseau { 
 

	// Les attributs
	protected: 	 /*! < Pour que les classes filles aient également accès à ces attributs */
		Couche Couches[];
		int nbCouche;
	
	// Les constructeurs
	/*!
             *  \brief Constructeur sans argument
             *
             *  Constructeurs de la classe Reseau
             *
             */
          Reseau();
             /*! 
             *  \brief Constructeur prenant en compte les paramètres fourni par l'utilisateur via un fichier ou non 
             *  \param listeParametres : liste introduite par le biais de la classe InterfaceUtilisateur fournissant les parametres nécessaires à la construction du réseau
             */
          Reseau(Liste listeParametres); 
             /*!
             *  \brief Destructeur de Reseau
             */
          ~Reseau();
          
              /*!
             *  \fn ajouterCouche(Couche c, int numCouche)
             *  \brief La fonction permet d'ajouter une couche au réseau.
             *  \param Couche c : Objet de la classe Couche
             *  \param int numCouche : entier indiquant l'indice de la couche c.
             *  \return Rien mais modifie le réseau
             */
          void ajouterCouche(Couche c,int numCouche);
             
             /*!
             *  \fn double erreur(Fichier SortiesAttendues)
             *  \brief La fonction calcule l'erreur commise par le réseau à l'aide de l'algorithme de descente de gradient et donc indique sa précision.
             *  \param Fichier SortiesAttendues
             *  \return valeur de la mesure de l'erreur à l'instant t
             * 
             */
	      double erreur(Fichier SortiesAttendues)
          
             /*!
             *  \fn Apprentissage(Fichier Données);
             *  \brief La fonction permet l'apprentissage du réseau de neurone en prenant en argument les données fournis en entrée
             *  \param Fichier Données
             *
             *  \return Rien mais modifie le réseau
             * 
             */
	      void Apprentissage(Fichier Données);
          
            /*!
             *  \fn backPropagation(Liste Entrées x, Liste Sorties y);
             *  \brief applique la méthode essentielle de la backPropagation
             *  \param Liste Entrées x, Liste Sorties y
             *
             *  \return Rien mais modifie le réseau
             * 
             */
	  void backPropagation(Liste Entrées x, Liste Sorties y);
	  /*!
             *  \fn CalcGradC(Sorties sAttendues, Sorties sCalculées);
             *  \brief La fonction est celle de descente du gradient.
             *  \param Sorties sAttendues, Sorties sCalculées
             *
             *  \return le vecteur correspondant au gradient de l'erreur par rapport à tous les poids et les biais à l'étape p+1
             * 
             */
	  tableau CalcGradC(Sorties sAttendues, Sorties sCalculées);
	}; 

	  
};
#endif
