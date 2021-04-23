#ifndef RESEAU_HPP
#define RESEAU_HPP

#include "Couche.hpp"
#include "CoucheCachee.hpp"
#include "CoucheEntrees.hpp"
#include "CoucheSorties.hpp"
#include "Matrice.hpp"
#include "Neurone.hpp"

#include <iostream>
#include <stdlib.h>
#include <vector>

{

  class Reseau {
    // Les attributs
    protected:
      CoucheEntrees entrees;
      CoucheSorties sorties;
      std::vector<CoucheCachee> couches; //ATTENTION : j'ai enlevé un static => faire pareil dans le hpp
      int nbCouchesCachees;
      std::vector<Matrice> gradientErr;  //Contient une matrice deltaw et une matrice deltab pour chaque couche
                              //Avec deltaw et deltab les composantes de grad(C) concernant respectivement les poids et les biais

    //Constructeur plus adapté
    Reseau::Reseau(int nbCouchesCachees, int nbNeuronesParCouches[], int choixPoids, String nomFichEntrees, int nbNeuronesSorties){
      entrees = new CoucheEntrees(nomFichEntrees);
      sorties = new CoucheSorties(nbNeuronesSorties);
      nbCouchesCachees = nbCouchesCachees;
      gradientErr = new Matrice[2 * nbCouchesCachees];

      //Poids initialiser aléatoirement
      if(choixPoids==0){
        for(int i=0;i<nbCouchesCachees;i++){
          couches.push_back(new CoucheCachee(nbNeuronesParCouches[i]));
          couches[i].liaisonsEntrees.initAleatoire();
          couches[i].biais.initAleatoire();
        }
      }else{
        for(int i=0;i<nbCouchesCachees;i++){
          couches.push_back(new CoucheCachee(nbNeuronesParCouches[i]));
        }
      }
      gradientErr.push_back(new Matrice(couches[0].nbNeurones, entrees.nbNeurones));
      gradientErr.push_back(new Matrice(couches[0].nbNeurones, 1));
      for(int i=1;i<nbCouchesCachees;i++){
        gradientErr.push_back(new Matrice(couches[i].nbNeurones, couches[i-1].nbNeurones));
        gradientErr.push_back(new Matrice(couches[i].nbNeurones, 1));
      }

    };

    //Reseau::Reseau(const int nbC);  //ATTENTION : à retirer du hpp

    Reseau::~Reseau();


    void ajouterCouche(Couche c, int numCouche); //pas utile ?

    //Retourne la norme au carré de l'erreur sur un seul exemple
    double erreur(String nomFichSorties){  //ATTENTION : je suppose que le constructeur Sortie(String nomFich) existe
      CoucheSorties sAttendues = new CoucheSorties(nomFichSorties);
      double res = 0;
      int nbrNeurones = sorties.nbNeurones;
      if(nbrNeurones==sAttendues.nbNeurones){
        for(int i=0;i<nbrNeurones;i++){
          res = res + (sorties.Neurones[i] - sAttendues.sorties.nbNeurones[i]) * (sorties.Neurones[i] - sAttendues.sorties.nbNeurones[i]);
        }
        return res;
      }else{
        std::cout << "erreur : les nombres de neurones de la couche de sortie du réseau et du fichier sont différents\n";
      }
    };

    //calcul les composantes de gradientErr correspondant à la ieme couche
    void backPropSimple(int indCouche){
      //Calcul des dérivées partielles suivantes
      for(int i=0;i<couches[indCouche].nbNeurones;i++){
        tempDerivErr.coefficients[i][1] = 0;
        for(int j=0;j<couches[indCouche+1].nbNeurones){
          //A CORRIGER / FINIR
          // !!!!!!!! // tempDerivErr.coefficients[i][1] += couches[indCouche+1].liaisonsEntrees.coefficients[i][j] * couches[indCouche].derivFoncActivation(couches[indCouche].preActivation());
        }
      }
      for(int i=0;i<couches[indCouche].nbNeurones;i++){
        for(int j=0;j<couches[indCouche-1].nbNeurones;j++){
          for(int k=0)
          //ATTENTION : j'ai utiliser une fonction derivFoncActivation qui n'existe pas encore
          //ATTENTION : est ce que j'ai accès à m.coefficients depuis la classe Réseau ?
          //utiliser un geter pour coefficients
          gradientErr[2*indCouche].coefficients[i][j] = 2 * couches[nbCouchesCachees-1].Neurones[j].sortie * couches[nbCouchesCachees-1].derivFoncActivation(couches[nbCouchesCachees-1].preActivation()) * (couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
        }
        gradientErr[2 * indCouche+1].coefficients[i][1] = 2 * couches[nbCouchesCachees-1].derivFoncActivation(couches[nbCouchesCachees-1].preActivation()) * (couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
      }
    };

    void backPropBiais(int indCouche){
    };


    void calcGradErr(Sorties sAttendues){
      int i, j;
      std::vector<Matrice> tempDerivErr; //Variable tampon qui va servir à sotcker les dérivées partielles de la fonction erreur par rapport aux sorties des neurones
      for(int i=0;i<nbCouchesCachees;i++){
        tempDerivErr.push_back(new Matrice(couches[i].nbNeurones, 1));
      }
      //Calcul des composantes de gradErr associées à la derniere couche cachée / Initialisation de la BP
      for(i=0;i<sorties.nbNeurones;i++){
        for(j=0;j<couches[nbCouchesCachees-1].nbNeurones;j++){
          //ATTENTION : j'ai utiliser une fonction derivFoncActivation qui n'existe pas encore
          //ATTENTION : est ce que j'ai accès à m.coefficients depuis la classe Réseau ?
          gradientErr[2*nbCouchesCachees-2].coefficients[i][j] = 2 * couches[nbCouchesCachees-1].Neurones[j].sortie * couches[nbCouchesCachees-1].derivFoncActivation(couches[nbCouchesCachees-1].preActivation()) * (couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
        }
        tempDerivErr[nbCouchesCachees-1].coefficients[i][1] = 2 * (couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
        gradientErr[2 * nbCouchesCachees -1].coefficients[i][1] = 2 * couches[nbCouchesCachees-1].derivFoncActivation(couches[nbCouchesCachees-1].preActivation()) * (couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
      }

      //Calcul des autres composantes de gradErr
      for(int k=nbCouchesCachees-2;k>=0;k--){
        std::vector<double> tempk = couches[k].preActivation();
        std::vector<double> tempkp1 = couches[k+1].preActivation();
        //Initialisation
        for (i = 0; i < couches[k].nbNeurones; i++){
          tempDerivErr[k].coefficients[i][1] = 0;
        }
        //Calcul des dérivées partielles par rapport aux sorties des neurones
        for (i = 0; i < couches[k].nbNeurones; i++){
          for (j = 0; j < couches[k+1].nbNeurones; j++) {
            tempDerivErr[k].coefficients[i][1] += couches[k+1].liaisonsEntrees.coefficients[i][j] * couches[k+1].derivFoncActivation(tempkp1[j]) * tempDerivErr[k+1].coefficients[j][1];
          }
        }
        for(i=0;i<couches[k].nbNeurones;i++){
          for(j=0;j<couches[k-1].nbNeurones;j++){
            gradientErr[2*nbCouchesCachees-2].coefficients[i][j] = 2 * couches[nbCouchesCachees-1].Neurones[j].sortie * couches[nbCouchesCachees-1].derivFoncActivation(couches[nbCouchesCachees-1].preActivation()) * (couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
          }
          tempDerivErr[k].coefficients[i][1] = 2 * (couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
          gradientErr[2 * nbCouchesCachees -1].coefficients[i][1] = 2 * couches[nbCouchesCachees-1].derivFoncActivation(couches[nbCouchesCachees-1].preActivation()[i]) * (couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
        }
        backPropSimple(i):
      }
    };

    void calcSorties(Entrees e){
    }

    //(x,y) est un sous-echantillon de l'echantillon d'apprentissage,
    void BackPropagation(std::vector<CoucheEntrees> x, std::vector<CoucheSorties> y)
    {
      Matrice moyenne = new Matrice(size(x), 1, 0);
      for (int i=0; i<size(x); i++)
      {
        calcSorties(x[i]); 
        calcGradErr(y[i]);
      }
      
    }
    moyenne[i] =  gradErr[i] + moyenne[i];

    moyenne = moyenne/taille
    couche[i] = couches[i] - moyenne[i]

    //construit l'echantillon d'apprentissage, elle divise en sous-echantillon et elle appelle la methode BackPropagation sur chaque sous-echantillon
    void Apprentissage(Fichier Donnees);
    C1 C2 C3 C4 V


    //void ApprentissageNonSupervise(Fichier Donnees); //ATTENTION : enlever le é dans le hpp
	};

};
#endif
