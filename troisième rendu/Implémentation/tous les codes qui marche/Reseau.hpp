#ifndef RESEAU_HPP
#define RESEAU_HPP
#include "Couche.hpp"
#include "CoucheCachee.hpp"
#include "CoucheEntrees.hpp"
#include "CoucheSorties.hpp"
#include "Matrice.hpp"
#include <vector>

using namespace std;
/*!
 * \file Reseau.hpp
 * \brief Les proprietes d'un reseau : le nombre de couches qui le compose, ses couches, et sa matrice de liaison
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_types_de_reseaux
 * Permet de creer un certain type de reseau
 */


 /*! \class Reseau
 * \brief Classe representant un reseau
 */
class Reseau {

    // Les attributs
    protected: 	 /*! < Pour que les classes filles aient egalement acces a ces attributs */
    CoucheSorties sorties;
    CoucheEntrees entrees;
    vector<CoucheCachee> couches;
    int nbCouchesCachees;
    vector<Matrice> gradientErr;
    /*! gradient Err contient une matrice deltaw (pour les poids) et une matrice deltab (pour les biais) pour chaque couche
    deltaw et deltab representent les quantites incrementees lors de l'apprentissage  */

    // Les constructeurs
    /*!
    *  \brief Constructeur prenant en compte les parametres fourni par l'utilisateur via un fichier ou non
    */
    public : 
    Reseau(int nbCouchesCach, vector<int> nbNeuronesParCouches, int choixPoids, const string nomFichEntrees, int nbNeuronesSorties, int nbNeuroneEntrees);

    /*!
    *  \brief Destructeur de Reseau
    */
    ~Reseau();

    /*!
    *  \fn double erreur(int classeSolution)
    *  \brief La fonction calcule la norme au carre de l'erreur commise par le reseau sur un seul exemple
    *  \param La classe solution
    *  \return valeur de la mesure de l'erreur a l'instant t
    *
    */
    double erreur(int classeSolution);

    /*!
      *  \fn CalcGradC(CoucheSorties sAttendues);
      *  \brief La fonction qui calcule les valeurs a incrementer dans les biais et les poids en utilisant le principe de la descente du gradient dans gradientErr.
      *  \param CoucheSorties sAttendues
      */
    void calcGradErr(CoucheSorties sAttendues);

    /*!
    *   \fn calcSorties(CoucheEntrees e);
    *   \brief calcule les sorties obtenues avec les entrees e
    *   \param CoucheEntrees e
    */
    void calcSorties(CoucheEntrees e);

    /*!
      *  \fn backPropagation(vector<CoucheEntrees> x, vector<CoucheSorties> y);
      *  \brief modifie les poids et les biais en utilisant le sous-echantillon d'apprentissage (x,y)
      *  \param vector<CoucheEntrees> x, vector<CoucheSorties> y
      */
    void BackPropagation(vector<CoucheEntrees> x, vector<CoucheSorties> y);

    /*!
      *  \fn Remplissage(vector<CoucheEntrees> x, vector<CoucheSorties> y, string nomFic);
      *  \brief Construit le sous-echantillon d'apprentissage a l'aide du fichier nomFich
      *  \param vector<CoucheEntrees> x, vector<CoucheSorties> y, string nomFic
      */
    void Remplissage(vector<CoucheEntrees> x, vector<CoucheSorties> y, string nomFic);

    /*!
    *  \fn Apprentissage(string Donnees);
    *  \brief Apprentissage du reseau de neurone en se basant sur l'echantillon d'apprentissage Donnees
    *  \param string Donnees
    */
    void Apprentissage(string Donnees);
};


#endif

