#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include <string>
/*!
 * \file Interface.hpp
 * \brief Interface Utilisateur permet d'importer les parametres du futur reseau de neurones par divers moyens
 * \author Groupe projet A1
 * \version 0.1
 */

    /*!  \class Interface
    * \brief Importation des parametres et differentes options du futur reseau
    */
    class Interface{
        //Les attributs
	protected : //accés aussi pour les classes filles
	int nbCouchesCachees;
	int nbNeuronesEntree;
	int nbNeuronesSortie;
	std::vector<int>nbNeuronesParCouches;
	double choixPoid;
	int typeReseau;
	int casUtilisation;

        //Les méthodes
	public :
        /*!
        *   \brief Constructeur
        *
        *   Constructeur de l'interface 
        *
        */
	Interface();
        /*! \fn lectureFichier(Fichier f)
        *   \brief  Importation des paramètres par un fichier de données et convertion en liste et lecture des paramètre du futur réseau de neurone dans un fichier  
        *   \return une liste des paramètres du futur réseau de neurone
        */

	//Getters
	int getnbCouchesCachees();
	double getchoixPoid();	
	int gettypeReseau();
	int getcasUtilisation();
	std::vector<int> getnbNeuronesCouches(); 
	int getnbNeuronesParCouches(int ind);
	int getnbNeuronesEntree();
	int getnbNeuronesSortie();

	//Setters
	void setnbCouchesCachees(const int nbCouchesCachees);
	void setchoixPoid(const double choixPoid);	
	void settypeReseau(const int typeReseau);
	void setcasUtilisation(const int casUtilisation);
	void setnbNeuronesParCouches(const int nbNeuronesParCouches,const int ind);
	void setnbNeuronesEntree(const int nbNeuronesEntree);
	void setnbNeuronesSortie(const int nbNeuronesSortie);
	//
	int validationReseau();
//    };
 };
 #endif
