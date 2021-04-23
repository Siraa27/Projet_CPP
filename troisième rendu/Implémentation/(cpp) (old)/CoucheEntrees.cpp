#include "CoucheEntrees.hpp"
#include "Couche.hpp"
#include "Neurone.hpp"
#include <string> 
#include <fstream>  


CoucheEntrees::CoucheEntrees (const int nbNeurones) : Couche::Couche(nbNeurones)
{
}

CoucheEntrees::~CoucheEntrees(){}

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
            Couche::getNeurone(i).setSortie(buffer);
            i++;
        } 
    } 
}