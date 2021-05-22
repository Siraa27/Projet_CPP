#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include <string>
#include <iostream>


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
	private : //accés aussi pour les classes filles
		int nbCouchesCachees;
		int nbNeuronesEntree;
		int nbNeuronesSortie;
		std::vector<int> nbNeuronesParCouches;
		double choixPoid;
		int typeReseau;
		int casUtilisation;

    //Les méthodes
	public :
        /*!
        *   \brief Constructeur
        *   Constructeur de l'interface 
        */
		Interface();

		//Getters
		int getnbCouchesCachees() const;
		double getchoixPoid() const;	
		int gettypeReseau() const;
		int getcasUtilisation() const;
		std::vector<int> getnbNeuronesCouches() const; 
		int getnbNeuronesParCouches(const int ind) const;
		int getnbNeuronesEntree() const;
		int getnbNeuronesSortie() const;

		//Setters
		void setnbCouchesCachees(const int nbCouchesCachees);
		void setchoixPoid(const double choixPoid);	
		void settypeReseau(const int typeReseau);
		void setcasUtilisation(const int casUtilisation);
		void setnbNeuronesParCouches(const int nbNeuronesParCouches,const int ind);
		void setnbNeuronesEntree(const int nbNeuronesEntree);
		void setnbNeuronesSortie(const int nbNeuronesSortie);
		//
		int validationReseau() const;
 };
 #endif
