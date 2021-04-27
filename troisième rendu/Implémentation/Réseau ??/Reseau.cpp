#ifndef RESEAU_HPP
#define RESEAU_HPP

#include "Couche.hpp"
#include "CoucheCachee.hpp"
#include "CoucheEntrees.hpp"
#include "CoucheSorties.hpp"
#include "Matrice.hpp"

#include <iostream>
#include <stdlib.h>
#include <vector>

{

  class Reseau {
    // Les attributs
    protected:
      //ATTENTION : a mettre dans le hpp
      CoucheEntrees entrees;
      CoucheSorties sorties;
      std::vector<CoucheCachee> couches; //ATTENTION : j'ai enlevé un static => faire pareil dans le hpp
      int nbCouchesCachees;
      std::vector<Matrice> gradientErr;  //Contient une matrice deltaw et une matrice deltab pour chaque couche
                                        //Avec deltaw et deltab les composantes de grad(C) concernant respectivement les poids et les biais

    //Constructeur plus adapté
    Reseau::Reseau(int nbCouchesCach, vector<int> nbNeuronesParCouches, int choixPoids, String nomFichEntrees, int nbNeuronesSorties){
      entrees = new CoucheEntrees(nomFichEntrees);
      sorties = new CoucheSorties(nbNeuronesSorties, nbNeuronesParCouches[nbCouchesCachees-1]);
      nbCouchesCachees = nbCouchesCach;
      gradientErr = new Matrice[2 * nbCouchesCachees];

      //Poids initialiser aléatoirement
      if(choixPoids==0){
        for(int i=0;i<nbCouchesCachees;i++){
          couches.push_back(new CoucheCachee(nbNeuronesParCouches[i]));
          couches[i].getLiaisonsEntrees().initAleatoire();
          couches[i].getBiais().initAleatoire();
        }
      }else{
        for(int i=0;i<nbCouchesCachees;i++){
          couches.push_back(new CoucheCachee(nbNeuronesParCouches[i]));
        }
      }
      gradientErr.push_back(new Matrice(couches[0].getNbNeurones(), entrees.getNbNeurones()));
      gradientErr.push_back(new Matrice(couches[0].getNbNeurones(), 1));
      for(int i=1;i<nbCouchesCachees;i++){
        gradientErr.push_back(new Matrice(couches[i].getNbNeurones(), couches[i-1].getNbNeurones()));
        gradientErr.push_back(new Matrice(couches[i].getNbNeurones(), 1));
      }

    };

    //Reseau::Reseau(const int nbC);  //ATTENTION : à retirer du hpp

    Reseau::~Reseau(){
      couches.clear();
      gradientErr.clear();
      nbCouchesCachees=0;
    };


    void ajouterCouche(Couche c, int numCouche); //pas utile ?

    //Retourne la norme au carré de l'erreur sur un seul exemple
    double erreur(String nomFichSorties){  //ATTENTION : je suppose que le constructeur Sortie(String nomFich) existe
      CoucheSorties sAttendues = new CoucheSorties(nomFichSorties);
      double res = 0;
      int nbrNeurones = sorties.getNbNeurones();
      if(nbrNeurones==sAttendues.getNbNeurones()){
        for(int i=0;i<nbrNeurones;i++){
          res = res + (sorties.getNeurones(i).getSortie() - sAttendues.getNeurones(i).getSortie()) * (sorties.getNeurones(i).getSortie() - sAttendues.getNeurones(i).getSortie());
        }
        return res;
      }else{
        std::cout << "erreur : les nombres de neurones de la couche de sortie du réseau et du fichier sont différents\n";
      }
    };

    void calcGradErr(CoucheSorties sAttendues){
      int i, j;
      std::vector<Matrice> tempDerivErr; //Variable tampon qui va servir à sotcker les dérivées partielles de la fonction erreur par rapport aux sorties des neurones
      for(int i=0;i<nbCouchesCachees;i++){
        tempDerivErr.push_back(new Matrice(couches[i].getNbNeurones(), 1));
      }
      //Calcul des composantes de gradErr associées à la derniere couche cachée / Initialisation de la BP
      for(i=0;i<sorties.getNbNeurones();i++){
        for(j=0;j<couches[nbCouchesCachees-1].getNbNeurones();j++){
          //ATTENTION : j'ai utiliser une fonction derivFoncActivation qui n'existe pas encore
          //ATTENTION : est ce que j'ai accès à m.coefficients depuis la classe Réseau ?
          gradientErr[2*nbCouchesCachees-2].setCoefMatrice(i,j, 2 * couches[nbCouchesCachees-1].getNeurones(j).getSortie() * couches[nbCouchesCachees-1].derivFoncActivation(couches[nbCouchesCachees-1].preActivation()) * (couches[nbCouchesCachees].getNeurones(i).getSortie() - sAttendues.getNeurones(i).getSortie()));
        }
        tempDerivErr[nbCouchesCachees-1].setCoefMatrice(i,1, 2 * (couches[nbCouchesCachees].getNeurones(i).getSortie() - sAttendues.getNeurones(i).getSortie()));
        gradientErr[2 * nbCouchesCachees -1].setCoefMatrice(i,1, 2 * couches[nbCouchesCachees-1].derivFoncActivation(couches[nbCouchesCachees-1].preActivation()) * (couches[nbCouchesCachees].getNeurones(i).getSortie() - sAttendues.getNeurones(i).getSortie()));
      }

      //Calcul des autres composantes de gradErr
      for(int k=nbCouchesCachees-2;k>=0;k--){
        std::vector<double> tempk = couches[k].preActivation();
        std::vector<double> tempkp1 = couches[k+1].preActivation();
        //Initialisation
        for (i = 0; i < couches[k].getNbNeurones(); i++){
          tempDerivErr[k].setCoefMatrice(i,1,0);
        }
        //Calcul des dérivées partielles par rapport aux sorties des neurones
        for (i = 0; i < couches[k].getNbNeurones(); i++){
          for (j = 0; j < couches[k+1].getNbNeurones(); j++) {
            tempDerivErr[k].setCoefMatrice(i,1, tempDerivErr[k].getCoefMatrice(i,1) + couches[k+1].getLiaisonsEntrees().getCoefMatrice(i,j) * couches[k+1].derivFoncActivation(tempkp1[j]) * tempDerivErr[k+1].getCoefMatrice(j,1));
          }
        }
        for(i=0;i<couches[k].getNbNeurones();i++){
          for(j=0;j<couches[k-1].getNbNeurones();j++){
            gradientErr[2*k].setCoefMatrice(i,j, couches[k-1].getNeurones(j).getSortie() * couches[k-1].derivFoncActivation(tempk[i]) * tempDerivErr[k].getCoefMatrice(i,1));
          }
          gradientErr[2*k+1].setCoefMatrice(i,1, couches[k-1].derivFoncActivation(tempk[i]) * tempDerivErr[k].getCoefMatrice(i,1));
        }
      }
    };

    void calcSorties(CoucheEntrees e){
      entrees = e;
      couches[0].foncActivation(couches[0].preActivation(e));
      for(int k=1;k<nbCouchesCachees;k++){
        couches[k].foncActivation(couches[k].preActivation(couches[k-1]));
      }
      sorties.foncActivation(sorties.preActivation(couches[nbCouchesCachees-1]));
    }

    //(x,y) est un sous-echantillon de l'echantillon d'apprentissage,
    void BackPropagation(std::vector<CoucheEntrees> x, std::vector<CoucheSorties> y){
      if(x.size() != y.size()){
        std::cout << "erreur : le nombre d''entrées et de sorties du sous-échantillon sont différents\n";
      }else{
        //Calcul du gradient de l'erreur moyen sur le sous-echantillon (x,y)
        std::vector<Matrice> moyenne;
        moyenne.push_back(new Matrice(couches[0].getNbNeurones(), entrees.getNbNeurones()));
        moyenne.push_back(new Matrice(couches[0].getNbNeurones(), 1));
        moyenne[0].setCoefs(0);
        moyenne[1].setCoefs(0);
        for(int i=1;i<nbCouchesCachees;i++){
          moyenne.push_back(new Matrice(couches[i].getNbNeurones(), couches[i-1].getNbNeurones()));
          moyenne.push_back(new Matrice(couches[i].getNbNeurones(), 1));
          moyenne[2*i].setCoefs(0);
          moyenne[2*i+1].setCoefs(0);
        }
        for(int i=0;i<x.size();i++){
          calcSorties(x[i]);
          calcGradErr(y[i]);
          for(int j=0;j<moyenne.size();j++){
            moyenne[j] = moyenne[j] + gradErr[j];
          }
        }
        for(int j=0;j<moyenne.size();j++){
          moyenne[j] = moyenne[j]/x.size();
        }
        //Modification des poids et des biais
        for(int j=0;j<nbCouchesCachees;j++){
          couches[j].getLiaisonsEntrees() = couches[j].getLiaisonsEntrees() - moyenne[2*j];
          couches[j].getBiais() = couches[j].getBiais() - moyenne[2*j+1];
        }
      }
    }

    void Reseau::Remplissage(std::vector<CoucheEntrees> x, std::vector<CoucheSorties> y, std::string nomFic)
    {
        std::ifstream fichier( nomFic ); //Ouverture en lecture

        if ( fichier )
        {
            std::string ligne; // variable contenant chaque ligne lue
            double buffer;

    		std::getline( fichier, ligne ); //Recupere la 1ere ligne contenant differentes infos
      		std::vector<std::string> result;
      		std::istringstream iss(ligne); // créer un flux a partir de la chaîne donnee
      		std::string str;
      		while (std::getline(iss, str, ' ')) //Le separateur est un espace
        		result.push_back(str); //On stock les elements de chaque ligne dans un vector result

    		//Premiere ligne : nbLignes, nbColonnes, et nbNeurones d'entree
    		int nbLignes = result[0];
    		int nbColonnes = result[1];
            int nbNeurones = result[2];

    		int ind = 0; //indice des individus

            while ( std::getline( fichier, ligne ) && (i<nbLignes)
            {
    			result.clear();
      			iss(ligne); //// créer un flux a partir de la chaîne donnee
      			while (std::getline(iss, str, ' '))
        			result.push_back(str);

    			//Set les entrees
    			for(int i=0; i<nbColonnes-2; i++)
    			{
    				buffer = std::stod(result[i]);
                	x[ind].getNeurone(i).setSortie(buffer); //On set la sortie du neurone
    			}
    			//Set les sorties
    			for (int i = 0; i < y[ind].getNbNeurones(); i++)
    			{
    				buffer = std::stod(result[nbColonnes-1]);
    				if (buffer==i)
    					y[ind].getNeurone(i).setSortie(1);
    				else
    					y[ind].getNeurone(i).setSortie(0);
    			}
    			ind++;
            }
        }
    }

    //construit l'echantillon d'apprentissage, elle divise en sous-echantillon et elle appelle la methode BackPropagation sur chaque sous-echantillon
    void Apprentissage(std::string Donnees);{
      //construction des vecteurs entrées/sorties à partir du fichier Donnees
      //help je sais pas comment faire
      std::vector<CoucheEntrees> lesEntrees;
      std::vector<CoucheSorties> lesSorties;
      Remplissage(lesEntrees, lesSorties, Donnees);

      if(lesEntrees.size() != lesSorties.size()){
        std::cout << "erreur : le nombre d''entrées et de sortie de l''échantillon d''apprentissage sont différents" << '\n';
      }else{
        //On construit des sous-échantillon d'apprentissage (xi,yi)
        int tailleSousEchantllons = 5; //choix arbitraire
        int nbEchantillon = (int) lesEntrees.size() / tailleSousEchantllons:
        for (int i = 0; i < nbEchantillon; i++) {
          std::vector<CoucheEntrees> EntreesSousEchan;
          std::vector<CoucheSorties> SortiesSousEchan;
          for (int j = 0; j < tailleSousEchantllons; j++) {
            EntreesSousEchan.push_back(lesEntrees[i*tailleSousEchantllons+j]);
            SortiesSousEchan.push_back(lesSorties[i*tailleSousEchantllons+j]);
          }
          BackPropagation(EntreesSousEchan, SortiesSousEchan);
        }
      }
    }
	};

};
#endif
