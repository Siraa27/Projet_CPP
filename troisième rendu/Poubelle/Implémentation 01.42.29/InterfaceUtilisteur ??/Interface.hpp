#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include <string>
/*!
 * \file Interface.hpp
 * \brief Interface Utilisateur permet de saisir divers paramètres par l'utilisateur du réseau
 * \author Groupe projet A1
 * \version 0.1
 */
 /*! \namespace Interface_Saisie_des_donnees
 * Classe permettant la saisie de données par l'utilisateur ou l'importation
 */
 //namespace Interface_Saisie_des_donnees
// {
    /*!  \class Interface
    * \brief Classe où l'utilisateur saisit les paramètres et choix des différentes options proposées pour son futur réseau
    */
    class Interface{
        //Les attributs
	protected : //accés aussi pour les classes filles
	int nbCouchesCachees;
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
	void lectureParam();
	void lectureFichier(std::string nomFic);
	//Getters
	int getnbCouchesCachees();
	double getchoixPoid();	
	int gettypeReseau();
	int getcasUtilisation();
	int getnbNeuronesParCouches(int ind);
	//Setters
	void setnbCouchesCachees(int nbCouchesCachees);
	void setchoixPoid(double choixPoid);	
	void settypeReseau(int typeReseau);
	void setcasUtilisation(int casUtilisation);
	void setnbNeuronesParCouches(int nbNeuronesParCouches, int ind);


//    };
 };
 #endif
