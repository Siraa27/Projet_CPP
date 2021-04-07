#include <iostream>
#include <string>
#include <list>

#ifndef RESEAU_HPP
#define RESEAU_HPP

using namespace std;

// Classe abstraite JE CROIS PAS QUE CE SOIT UNE CLASSE ABSTRAITE EN FAIT OMG
class Reseau { 
 

	// Les attributs
	protected: 		//pour que les classes filles aient également accès à ces attributs
		static Couche Couches[];
		static int nbC;	 //nombre de couches 
		static double MatriceLiaisons[][];

	
	// Les constructeurs
	public: 
		Reseau();
		Reseau(const int nbC); //Constructeur pour le cas ou l'utilisateur décide du nombre de couches
		
	// Les methodes
	public: 
		void ajouterCouche(Couche c, int numCouche);
		double erreur(Fichier SortiesAttendues)
		void ApprentissageSupervisé(Fichier Données);
		void ApprentissageNonSupervisé(Fichier Données);
		
	
};



#endif
