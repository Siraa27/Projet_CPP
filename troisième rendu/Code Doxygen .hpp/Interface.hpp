#ifndef INTERFACE_HPP
#define INTERFACE_HPP
/*!
 * \file Interface.hpp
 * \brief Interface Utilisateur permet de saisir divers paramètres par l'utilisateur du réseau
 * \author Groupe projet A1
 * \version 0.1
 */
 /*! \namespace Interface_Saisie_des_donnees
 * Classe permettant la saisie de données par l'utilisateur ou l'importation
 */
 namespace Interface_Saisie_des_donnees
 {
    /*!  \class Interface
    * \brief Classe ou l'utilisateur saisit les paramètres, et choix des différentes options proposées pour son futur réseau
    */
    class Interface{
        //Les attributs

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
        *   \brief  Importation des paramètres par un fichier de donnée et convertion en liste
        *   Lecture des paramètre du futur réseau de neurone dans un fichier
        *   \return une liste des paramètres du futur réseau de neurone
        */
         double* lectureFichier(char nomFic[100]);
        /*! \fn lectureParam()
        *   \brief Importation des paramètres par saisie de l'utilisteur dans le terminal
        *   Lecture des paramètres du futur réseau de neurone dans le terminal
        *   \return une liste des paramètres du futur réseau de neurone
        */
         double* lectureParam();

    };
 };
 #endif
