#ifndef INTERFACEMANUELLE_HPP
#define INTERFACEMANUELLE_HPP
#include "Interface.hpp"
#include <vector>
#include <string>
/*!
 * \file InterfaceManuelle.hpp
 * \brief Interface Manuelle permet de saisir divers paramètres du futur reseau par le futur utilisateur du reseau. 
 * \author Groupe projet A1
 * \version 0.1
 */
 /*! \namespace Interface_Manuelle
 * Classe permettant la saisie de données par l'utilisateur ou l'importation
 */

class InterfaceManuelle: public Interface {
        //Les attributs

        //Les méthodes
	public :

	void lectureParam();
        /*! \fn lectureParam()
        *   \brief Importation des paramètres par saisie de l'utilisateur dans le terminal
        *   Lecture des paramètres du futur réseau de neurone dans le terminal
        *   \return rien
        */

 };
 #endif
