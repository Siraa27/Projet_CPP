#include "InterfaceManuelle.hpp"

using namespace std;

void InterfaceManuelle::lectureParam(){//fournir le chemin absolu ou 
	cout<<"Saisir l'entier correspondant au type de reseau souhaite\n";
	cout<<"1: reseau forwarded\n";
	cout<<"2: reseau recurent\n";
	cout<<"0:quitter\n";
	int choix;
	cin>> choix;
	if (choix!=1 && choix!=0)//Nous avons implémenté que réseau Forwarded
	{	
		settypeReseau(-1);
		cout<<"ERREUR: Type reseau non disponible ou non conforme\n";
	}else{
		settypeReseau(choix);
	}

	cout<<"Saisir l'entier correspondant au cas d'utilisation souhaite\n";
	cout<<"1: classification\n";
	cout<<"2: prediction\n";
	cin>> choix;
	if (choix!=2)//Nous avons implémenté que la prediction
	{	
		setcasUtilisation(-1);
		cout<<"ERREUR: Cas d'utilisation non disponible ou non conforme\n";
	}else{
		setcasUtilisation(choix);
	}

	cout<<"Saisir l'entier correspondant au nombre de couches cachees du reseau\n";
	cin>> choix;
	if (choix<0)
	{	
		setnbCouchesCachees(-1);
		cout<<"ERREUR: Nombre de couches cachees negatif\n";
	}else{
		setnbCouchesCachees(choix);
	}

	cout<<"Saisir le nombre d'entrees\n";
	cin>> choix;
	if (choix<0)
	{	
		setnbCouchesCachees(-1);
		cout<<"ERREUR: Nombre de couches cachees negatif\n";
	}else{
		setnbNeuronesEntree(choix);
	}

	cout<<"Saisir un a un le nombre de neurones dans chaques couches cachees\n";
	for (int i=0;i<getnbCouchesCachees();i++){ 
		cin>>choix;
		if (choix<=0)//Nombre de neurone dans une couche est superieure a 0
		{	
			choix=0;
			cout<<"ERREUR: Nombre de neurones en sortie négatif\n";
		}
		setnbNeuronesParCouches(choix, i);
	}

	cout<<"Comment voulez vous intisaliser votre matrice de poid ?\n";	
	cout<<"0: aleatoirement\n";
	cout<<"x un double: tous à x\n";
	cin>>choix;
	if (choix<0)//Poid non négatif
	{	
		setchoixPoid(-1);
		cout<<"ERREUR: Initialisation de la matrice de Poid avec des valeurs negatives\n";
	}else{
		setchoixPoid(choix);
	}
}
	
