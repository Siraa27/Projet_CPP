#include <iostream>
#include <string>
#include <list>
#include <cmath>

#include "Couche.hpp"
#include "CoucheSorties.hpp"

int main(int argc, char* argv[])
{
    Neurone n = Neurone();
    n.setSortie(8);
    std::cout << "testNeuroneSansPasséParCouche" << n.getSortie() << std::endl ;

    CoucheSorties CS(3,2);
    CS.getLiaisonEntrees().setCoefMatrice( 0, 0, 0.3 );
	CS.getLiaisonEntrees().setCoefMatrice( 0, 1, 0.2 );
	// Ligne II
	CS.getLiaisonEntrees().setCoefMatrice( 1, 0, 0.5 );
	CS.getLiaisonEntrees().setCoefMatrice( 1, 1, 0.4 );
	// Ligne III
	CS.getLiaisonEntrees().setCoefMatrice( 2, 0, 0.7);
	CS.getLiaisonEntrees().setCoefMatrice( 2, 1, 0.6 );

    CS.getBiais().setCoefMatrice( 0, 0, 0 );
	CS.getBiais().setCoefMatrice( 1, 0, 0 );
	CS.getBiais().setCoefMatrice( 2, 0, 0 );

    Couche C0(2);
    C0.modifNeurone(0,0.001);
	C0.modifNeurone(1,0.0001258869);

    std::cout << "neuroneCoucheprecMain" << C0.recupSortiesNeurones().getCoefMatrice(0,0) << std::endl; // Recup sortie ne marche pas
	std::cout << "neuroneCoucheprecMain" << C0.recupSortiesNeurones().getCoefMatrice(1,0) << std::endl;

    std::cout << "neuroneCoucheprecMainSansrecup" << C0.getNeurone(0).getSortie() << std::endl;
	std::cout << "neuroneCoucheprecMainSansrecup" << C0.getNeurone(1).getSortie() << std::endl;

    Matrice Resultat = Matrice(3,1);
    Resultat = CS.preActivation(C0);
    for (int i = 0 ; i < 3; i++) std::cout << "res" << Resultat.getCoefMatrice(i,0) << std::endl ;


    


}