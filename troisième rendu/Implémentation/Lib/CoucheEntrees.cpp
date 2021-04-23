#include "CoucheEntrees.hpp"
#include "Couche.hpp"
#include "Neurone.hpp"
#include <string> 
#include <fstream>  

//Constructeur
//NomFic est le nom du fichier contenant les sorties des neurones de la couche d'entree
CoucheEntrees::CoucheEntrees (const int nbNeurones, std::string nomFic) : Couche::Couche(nbNeurones)
{
    constructionSortie(nomFic);
}

//Destructeur
CoucheEntrees::~CoucheEntrees(){}

//On initialise les sorties des neurones de la couche d'entree avec le fichier nomFic
void CoucheEntrees::constructionSortie(std::string nomFic)
{ 
    std::ifstream fichier( "nomFic.txt" ); //Ouverture en lecture

    if ( fichier ) 
    { 
        std::string ligne; // variable contenant chaque ligne lue 
        double buffer; 
        int i =0;

        while ( std::getline( fichier, ligne ) && (i<Couche::getNbNeurones())) 
        { 
            buffer = std::stod(ligne);
            Couche::getNeurone(i).setSortie(buffer); //On set la sortie du neurone
            i++;
        } 
    } 
}