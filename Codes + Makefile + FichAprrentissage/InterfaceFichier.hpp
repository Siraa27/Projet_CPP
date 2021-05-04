#ifndef INTERFACEFICHIER_HPP
#define INTERFACEFICHIER_HPP

#include <vector>
#include "Interface.hpp"
/*!
 * \file InterfaceFichier.hpp
 * \brief Interface Fichier permet de recuperer les paramètres du futur reseau dans un fichier
 * \author Groupe projet A1
 * \version 0.1
 */

// {
    /*!  \class InterfaceFichier
    * \brief Classe l'importation des donnees d'un fichier csv au bon format se fait. Ce fichier contient les paramètres et choix des différentes options proposées pour le futur réseau
    */
class InterfaceFichier : public Interface{
        //Les méthodes
	public:

	void lectureFichier(std::string nomFic);
        /*! \fn lectureFichier(std::string nomFic)
        *   \brief  Importation des paramètres par un fichier de données csv et modifiction des attributs du reseau de la classe Interface. Ces attribut son les parametre du futur reseau, si les parametres sont valides.
        *   \return rien
        */


 };
 #endif
