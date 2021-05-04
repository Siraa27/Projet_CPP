#include <iostream>
#include <ostream> 
#include "Reseau.hpp"
#include "CoucheEntrees.hpp"
#include "CoucheSorties.hpp"
#include "Interface.hpp"
#include "InterfaceFichier.hpp"
#include "InterfaceManuelle.hpp"
#include <string.h>

void manipReseau(Reseau R)
{
    int choix;
    do
    {
        do
        {
            std::cout<<"Que voulez vous faire ?\n\t1) Apprentissage du reseau\n\t2) Tester le reseau sur un exemple\n\t3)Quitter\n";
            cin>>choix;
        }while((choix!=1) && (choix!=2) && (choix!=3));
        
        if(choix==1)
        {
            std::cout<<"Entrez le nom du fichier pour l'apprentissage\n";
            std::string nomFic;
            cin>>nomFic;
            R.Apprentissage(nomFic);
        }
        else if(choix==2)
        {
            std::cout<<"Entrez le nom du fichier contenant l'entree\n";
            std::string nomFic;
            cin>>nomFic;
            CoucheEntrees E(R.getNbNeuronesEntree(), nomFic);
            cout<<"YO\n";
            R.calcSorties(E);
            cout<<"YO2\n";
            std::cout<<R.getSorties();

            int rep;
            do
            {
                std::cout<<"Connaissiez vous votre classe attedue initialement ?\n\t1) Oui\n\t2) Non\n";
                cin>>rep;
            } while ((rep!=1) && (rep!=2) );
            if (rep==1)
            {
                std::cout<<"Entrez le numero de la classe\n";
                int classeAttendue;
                cin>>classeAttendue;
                std::cout<<R.erreur(classeAttendue);
            }   
        }
    }while(choix!=3);
}


int main(int argc, char* argv[])
{
    int choix;
    std::cout<<"Voulez-vous entrer votre reseau : \n\t 1) Manuellement \n\t2) Avec un fichier\n";
    cin>>choix;

    if(choix==1)
    {
        InterfaceManuelle interfaceMan;
        do
        {
            interfaceMan.lectureParam();
        }while(interfaceMan.validationReseau()==0 && interfaceMan.gettypeReseau()==-1);
        Reseau reseau(interfaceMan.getnbCouchesCachees(), interfaceMan.getnbNeuronesCouches(), interfaceMan.getchoixPoid(), interfaceMan.getnbNeuronesSortie(), interfaceMan.getnbNeuronesEntree());
        manipReseau(reseau);
    }
    else
    {
        InterfaceFichier interfaceFic;
        std::string nomFic;
        do
        {
            std::cout<<"Entrez le nom du fichier ou 0 pour sortir\n";
            cin>>nomFic;
            //cin.clear();
            interfaceFic.lectureFichier(nomFic);
        }while(interfaceFic.validationReseau()==0 && nomFic.compare("0"));
        Reseau reseau(interfaceFic.getnbCouchesCachees(), interfaceFic.getnbNeuronesCouches(), interfaceFic.getchoixPoid(), interfaceFic.getnbNeuronesSortie(), interfaceFic.getnbNeuronesEntree());
        manipReseau(reseau);
    }
    
}





/*
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
*/
