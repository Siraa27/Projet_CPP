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
            R.calcSorties(E);
            R.afficherResultat();
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
            interfaceFic.lectureFichier(nomFic);
        }while(interfaceFic.validationReseau()==0 && nomFic.compare("0"));
        Reseau reseau(interfaceFic.getnbCouchesCachees(), interfaceFic.getnbNeuronesCouches(), interfaceFic.getchoixPoid(), interfaceFic.getnbNeuronesSortie(), interfaceFic.getnbNeuronesEntree());
        manipReseau(reseau);
    }

}