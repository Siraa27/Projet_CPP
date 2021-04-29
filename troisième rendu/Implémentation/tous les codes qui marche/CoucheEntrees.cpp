#include "CoucheEntrees.hpp"
#include "Couche.hpp"
#include "Neurone.hpp"
#include <string> 
#include <fstream>  

//Constructeur

CoucheEntrees::CoucheEntrees(const CoucheEntrees& C) : Couche::Couche(C.getNbNeurones())
{}

//NomFic est le nom du fichier contenant les sorties des neurones de la couche d'entree
CoucheEntrees::CoucheEntrees (const int nbNeurones, std::string nomFic) : Couche::Couche(nbNeurones)
{
    constructionSortie(nomFic);
}

//Destructeur
CoucheEntrees::~CoucheEntrees(){}


//-----------------------------------Les Méthodes-----------------------------------
//-----------------------------------------------------------------------------------

//On initialise les sorties des neurones de la couche d'entree avec le fichier nomFic
void CoucheEntrees::constructionSortie(std::string nomFic)
{ 
    std::ifstream fichier(nomFic); //Ouverture en lecture

    if ( fichier ) 
    { 
        std::string ligne; // variable contenant chaque ligne lue 
        double buffer; 
        int i =0;

        while ( std::getline( fichier, ligne ) && (i<getNbNeurones())) 
        { 
            buffer = std::stod(ligne);
            modifNeurone(i,buffer); //On set la sortie du neurone
            i++;
        } 
    } 
}
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------