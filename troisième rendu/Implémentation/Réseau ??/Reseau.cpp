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
      this.entrees = new CoucheEntrees(nomFichEntrees);
      this.sorties = new CoucheSorties(nbNeuronesSorties);
      this.nbCouchesCachees = nbCouchesCachees;
      this.gradientErr = new Matrice[2 * this.nbCouchesCachees];

      //Poids initialiser aléatoirement
      if(choixPoids==0){
        for(int i=0;i<nbCouchesCachees;i++){
          this.couches.push_back(new CoucheCachee(nbNeuronesParCouches[i]));
          this.couches[i].liaisonsEntrees.initAleatoire();
          this.couches[i].biais.initAleatoire();
        }
      }else{
        for(int i=0;i<nbCouchesCachees;i++){
          this.couches.push_back(new CoucheCachee(nbNeuronesParCouches[i]));
        }
      }
      this.gradientErr.push_back(new Matrice(this.couches[0].nbNeurones, this.entrees.nbNeurones));
      this.gradientErr.push_back(new Matrice(this.couches[0].nbNeurones, 1));
      for(int i=1;i<this.nbCouchesCachees;i++){
        this.gradientErr.push_back(new Matrice(this.couches[i].nbNeurones, this.couches[i-1].nbNeurones));
        this.gradientErr.push_back(new Matrice(this.couches[i].nbNeurones, 1));
      }

    };

    //Reseau::Reseau(const int nbC);  //ATTENTION : à retirer du hpp

    Reseau::~Reseau();


    void ajouterCouche(Couche c, int numCouche); //pas utile ?

    //Retourne la norme au carré de l'erreur sur un seul exemple
    double erreur(String nomFichSorties){  //ATTENTION : je suppose que le constructeur Sortie(String nomFich) existe
      CoucheSorties sAttendues = new CoucheSorties(nomFichSorties);
      double res = 0;
      int nbrNeurones = this.sorties.nbNeurones;
      if(nbrNeurones==sAttendues.nbNeurones){
        for(int i=0;i<nbrNeurones;i++){
          res = res + (this.sorties.Neurones[i] - sAttendues.sorties.nbNeurones[i]) * (this.sorties.Neurones[i] - sAttendues.sorties.nbNeurones[i]);
        }
        return res;
      }else{
        std::cout << "erreur : les nombres de neurones de la couche de sortie du réseau et du fichier sont différents\n";
      }
    };

    //calcul les composantes de gradientErr correspondant à la ieme couche
    void backPropSimple(int indCouche){
      //Calcul des dérivées partielles suivantes
      for(int i=0;i<this.couches[indCouche].nbNeurones;i++){
        this.tempDerivErr.coefficients[i][1] = 0;
        for(int j=0;j<this.couches[indCouche+1].nbNeurones){
          //A CORRIGER / FINIR
          // !!!!!!!! // this.tempDerivErr.coefficients[i][1] += this.couches[indCouche+1].liaisonsEntrees.coefficients[i][j] * this.couches[indCouche].derivFoncActivation(this.couches[indCouche].preActivation());
        }
      }
      for(int i=0;i<this.couches[indCouche].nbNeurones;i++){
        for(int j=0;j<this.couches[indCouche-1].nbNeurones;j++){
          for(int k=0)
          //ATTENTION : j'ai utiliser une fonction derivFoncActivation qui n'existe pas encore
          //ATTENTION : est ce que j'ai accès à m.coefficients depuis la classe Réseau ?
          //utiliser un geter pour coefficients
          this.gradientErr[2*indCouche].coefficients[i][j] = 2 * this.couches[this.nbCouchesCachees-1].Neurones[j].sortie * this.couches[this.nbCouchesCachees-1].derivFoncActivation(this.couches[this.nbCouchesCachees-1].preActivation()) * (this.couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
        }
        this.gradientErr[2 * indCouche+1].coefficients[i][1] = 2 * this.couches[this.nbCouchesCachees-1].derivFoncActivation(this.couches[this.nbCouchesCachees-1].preActivation()) * (this.couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
      }
    };

    void backPropBiais(int indCouche){
    };


    void calcGradErr(Sorties sAttendues){
      int i, j;
      std::vector<Matrice> tempDerivErr; //Variable tampon qui va servir à sotcker les dérivées partielles de la fonction erreur par rapport aux sorties des neurones
      for(int i=0;i<this.nbCouchesCachees;i++){
        tempDerivErr.push_back(new Matrice(this.couches[i].nbNeurones, 1));
      }
      //Calcul des composantes de gradErr associées à la derniere couche cachée / Initialisation de la BP
      for(i=0;i<this.sorties.nbNeurones;i++){
        for(j=0;j<this.couches[this.nbCouchesCachees-1].nbNeurones;j++){
          //ATTENTION : j'ai utiliser une fonction derivFoncActivation qui n'existe pas encore
          //ATTENTION : est ce que j'ai accès à m.coefficients depuis la classe Réseau ?
          this.gradientErr[2*nbCouchesCachees-2].coefficients[i][j] = 2 * this.couches[this.nbCouchesCachees-1].Neurones[j].sortie * this.couches[this.nbCouchesCachees-1].derivFoncActivation(this.couches[this.nbCouchesCachees-1].preActivation()) * (this.couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
        }
        tempDerivErr[nbCouchesCachees-1].coefficients[i][1] = 2 * (this.couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
        this.gradientErr[2 * nbCouchesCachees -1].coefficients[i][1] = 2 * this.couches[this.nbCouchesCachees-1].derivFoncActivation(this.couches[this.nbCouchesCachees-1].preActivation()) * (this.couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
      }

      //Calcul des autres composantes de gradErr
      for(int k=nbCouchesCachees-2;k>=0;k--){
        std::vector<double> tempk = this.couches[k].preActivation();
        std::vector<double> tempkp1 = this.couches[k+1].preActivation();
        //Initialisation
        for (i = 0; i < this.couches[k].nbNeurones; i++){
          tempDerivErr[k].coefficients[i][1] = 0;
        }
        //Calcul des dérivées partielles par rapport aux sorties des neurones
        for (i = 0; i < this.couches[k].nbNeurones; i++){
          for (j = 0; j < this.couches[k+1].nbNeurones; j++) {
            tempDerivErr[k].coefficients[i][1] += this.couches[k+1].liaisonsEntrees.coefficients[i][j] * this.couches[k+1].derivFoncActivation(tempkp1[j]) * tempDerivErr[k+1].coefficients[j][1];
          }
        }
        for(i=0;i<this.couches[k].nbNeurones;i++){
          for(j=0;j<this.couches[k-1].nbNeurones;j++){
            this.gradientErr[2*nbCouchesCachees-2].coefficients[i][j] = 2 * this.couches[this.nbCouchesCachees-1].Neurones[j].sortie * this.couches[this.nbCouchesCachees-1].derivFoncActivation(this.couches[this.nbCouchesCachees-1].preActivation()) * (this.couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
          }
          tempDerivErr[k].coefficients[i][1] = 2 * (this.couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
          this.gradientErr[2 * nbCouchesCachees -1].coefficients[i][1] = 2 * this.couches[this.nbCouchesCachees-1].derivFoncActivation(this.couches[this.nbCouchesCachees-1].preActivation()[i]) * (this.couches[nbCouchesCachees].Neurones[i].sortie - sAttendues.Neurones[i].sortie);
        }
        this.backPropSimple(i):
      }
    };

    void calcSorties(Entrees e){
      
    }
    //(x,y) est un sous-echantillon de l'echantillon d'apprentissage,
    void BackPropagation(std::vector<CoucheEntrees> x, std::vector<CoucheSorties> y)
    {
      Matrice moyenne = new Matrice(size(x), 1, 0);
      for (i=0; i<size(x); i++)
      {
        this.calcSorties(x[i]);
        this.calcGradErr(y[i]);
      }
      
    }
    pour i=1 a taille x faire

      moyenne[i] =  gradErr[i] + moyenne[i];

    moyenne = moyenne/taille
    this.couche[i] = this.couches[i] - moyenne[i]

    //construit l'echantillon d'apprentissage, elle divise en sous-echantillon et elle appelle la methode BackPropagation sur chaque sous-echantillon
    void Apprentissage(Fichier Donnees);
    C1 C2 C3 C4 V


    //void ApprentissageNonSupervise(Fichier Donnees); //ATTENTION : enlever le é dans le hpp
	};

};
#endif
