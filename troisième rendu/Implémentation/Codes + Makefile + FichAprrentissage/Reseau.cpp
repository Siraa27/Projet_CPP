#include "Reseau.hpp"
#include "CoucheCachee.hpp"
#include "CoucheEntrees.hpp"
#include "CoucheSorties.hpp"
#include "Matrice.hpp"
#include "Neurone.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

//Constructeur
Reseau::Reseau(int nbCouchesCach, vector<int> nbNeuronesParCouches, double choixPoids, int nbNeuronesSorties, int nbNeuroneEntrees) : entrees(nbNeuroneEntrees), sorties(nbNeuronesSorties, nbNeuronesParCouches[nbCouchesCach-1])
{
  couches.push_back(CoucheCachee(nbNeuronesParCouches[0], nbNeuroneEntrees));
  couches[0].getLiaisonEntrees().initAleatoire();
  couches[0].getBiais().initAleatoire();
  nbCouchesCachees = nbCouchesCach;

  //Poids initialiser aleatoirement
  if(abs(choixPoids)<= 0.0001 ){
    for(int i=1;i<nbCouchesCachees;i++){
      couches.push_back(CoucheCachee(nbNeuronesParCouches[i], nbNeuronesParCouches[i-1]));
      couches[i].getLiaisonEntrees().initAleatoire();
      couches[i].getBiais().initAleatoire();
    }
  }else{
    for(int i=0;i<nbCouchesCachees;i++){
      couches.push_back(CoucheCachee(nbNeuronesParCouches[i], nbNeuronesParCouches[i-1]));
      couches[i].getLiaisonEntrees().setCoefs(choixPoids);
      couches[i].getBiais().initAleatoire();
    }
  }

  gradientErr.push_back(Matrice(couches[0].getNbNeurones(), entrees.getNbNeurones()));
  gradientErr.push_back(Matrice(couches[0].getNbNeurones(), 1));
  for(int i=1;i<nbCouchesCachees;i++){
    gradientErr.push_back(Matrice(couches[i].getNbNeurones(), couches[i-1].getNbNeurones()));
    gradientErr.push_back(Matrice(couches[i].getNbNeurones(), 1));
  }
}

Reseau::~Reseau(){
  couches.clear();
  gradientErr.clear();
  nbCouchesCachees=0;
}

CoucheSorties Reseau::getSorties()
{
  return sorties;
}

//Retourne la norme au carre de l'erreur sur un seul exemple
double Reseau::erreur(int classeSolution){
  CoucheSorties sAttendues(sorties.getNbNeurones(), couches[nbCouchesCachees-1].getNbNeurones());
  double res = 0;

  for (int i = 0; i < sAttendues.getNbNeurones(); i++)
  {
    if (classeSolution==i)
      sAttendues.modifNeurone(i,1);
    else
      sAttendues.modifNeurone(i,0);
  }

  int nbrNeurones = sorties.getNbNeurones();
  if(nbrNeurones==sAttendues.getNbNeurones()){
    for(int i=0;i<nbrNeurones;i++){
      res = res + (sorties.getNeurone(i).getSortie() - sAttendues.getNeurone(i).getSortie()) * (sorties.getNeurone(i).getSortie() - sAttendues.getNeurone(i).getSortie());
    }
    return res;
  }else{
    cout << "erreur : les nombres de neurones de la couche de sortie du reseau et du fichier sont differents\n";
    return 0;
  }
}

void Reseau::calcGradErr(CoucheSorties sAttendues){
  int i, j;
  vector<Matrice> tempDerivErr; //Variable tampon qui va servir a sotcker les derivees partielles de la fonction erreur par rapport aux sorties des neurones
  for(int i=0;i<nbCouchesCachees;i++){
    tempDerivErr.push_back(Matrice(couches[i].getNbNeurones(), 1));
  }
  //Calcul des composantes de gradErr associees a la derniere couche cachee / Initialisation de la BP
  for(i=0;i<sorties.getNbNeurones();i++){
    for(j=0;j<couches[nbCouchesCachees-1].getNbNeurones();j++){
      gradientErr[2*nbCouchesCachees-2].setCoefMatrice(i,j, 2 * couches[nbCouchesCachees-1].getNeurone(j).getSortie() * couches[nbCouchesCachees-1].derivFoncActivation(couches[nbCouchesCachees-1].preActivation(couches[nbCouchesCachees-2]).getCoefMatrice(i,0)) * (couches[nbCouchesCachees-1].getNeurone(i).getSortie() - sAttendues.getNeurone(i).getSortie()));
    }
    tempDerivErr[nbCouchesCachees-1].setCoefMatrice(i,0, 2 * (couches[nbCouchesCachees-1].getNeurone(i).getSortie() - sAttendues.getNeurone(i).getSortie()));
    gradientErr[2 * nbCouchesCachees -1].setCoefMatrice(i,0, 2 * couches[nbCouchesCachees-1].derivFoncActivation(couches[nbCouchesCachees-1].preActivation(couches[nbCouchesCachees-2]).getCoefMatrice(i,0)) * (couches[nbCouchesCachees-1].getNeurone(i).getSortie() - sAttendues.getNeurone(i).getSortie()));
  }

  //Calcul des autres composantes de gradErr
  for(int k=nbCouchesCachees-2;k>0;k--){
    Matrice tempk = couches[k].preActivation(couches[k-1]);
    Matrice tempkp1 = couches[k+1].preActivation(couches[k]);
    //Initialisation
    for (i = 0; i < couches[k].getNbNeurones(); i++){
      tempDerivErr[k].setCoefMatrice(i,0,0);
    }
    //Calcul des derivees partielles par rapport aux sorties des neurones
    for (i = 0; i < couches[k].getNbNeurones(); i++){
      for (j = 0; j < couches[k+1].getNbNeurones(); j++) {
        tempDerivErr[k].setCoefMatrice(i,0, tempDerivErr[k].getCoefMatrice(i,0) + couches[k+1].getLiaisonEntrees().getCoefMatrice(i,j) * couches[k+1].derivFoncActivation(tempkp1.getCoefMatrice(j,0)) * tempDerivErr[k+1].getCoefMatrice(j,0));
      }
    }
    for(i=0;i<couches[k].getNbNeurones();i++){
      for(j=0;j<couches[k-1].getNbNeurones();j++){
        gradientErr[2*k].setCoefMatrice(i,j, couches[k-1].getNeurone(j).getSortie() * couches[k-1].derivFoncActivation(tempk.getCoefMatrice(i,0)) * tempDerivErr[k].getCoefMatrice(i,0));
      }
      gradientErr[2*k+1].setCoefMatrice(i,0, couches[k-1].derivFoncActivation(tempk.getCoefMatrice(i,0)) * tempDerivErr[k].getCoefMatrice(i,0));
    }
  }

  Matrice tempk = couches[0].preActivation(entrees);
  Matrice tempkp1 = couches[1].preActivation(couches[0]);
  //Initialisation
  cout<<"7\n";
  for (i = 0; i < couches[0].getNbNeurones(); i++){
    tempDerivErr[0].setCoefMatrice(i,0,0);
  }
  //Calcul des derivees partielles par rapport aux sorties des neurones
  for (i = 0; i < couches[0].getNbNeurones(); i++){
    for (j = 0; j < couches[1].getNbNeurones(); j++) {
      tempDerivErr[0].setCoefMatrice(i,0, tempDerivErr[0].getCoefMatrice(i,0) + couches[1].getLiaisonEntrees().getCoefMatrice(i,j) * couches[1].derivFoncActivation(tempkp1.getCoefMatrice(j,0)) * tempDerivErr[1].getCoefMatrice(j,0));
    }
  }
  cout<<"8\n";
  for(i=0;i<couches[0].getNbNeurones();i++){
    for(j=0;j<entrees.getNbNeurones();j++){
      gradientErr[0].setCoefMatrice(i,j, entrees.getNeurone(j).getSortie() * (tempk.getCoefMatrice(i,0)) * tempDerivErr[0].getCoefMatrice(i,0));
    }
    gradientErr[1].setCoefMatrice(i,0, (tempk.getCoefMatrice(i,0)) * tempDerivErr[0].getCoefMatrice(i,0));
  }
}

void Reseau::calcSorties(CoucheEntrees e){
  entrees = e;
  couches[0].foncActivation(couches[0].preActivation(e));
  for(int k=1;k<nbCouchesCachees;k++){
    couches[k].foncActivation(couches[k].preActivation(couches[k-1]));
  }
  sorties.foncActivation(sorties.preActivation(couches[nbCouchesCachees-1]));
}

//modifie les poids et les biais en utilisant le sous-echantillon d'apprentissage (x,y)
void Reseau::BackPropagation(vector<CoucheEntrees>& x, vector<CoucheSorties>& y){
  if(x.size() != y.size()){
    cout << "erreur : le nombre d'entrees et de sorties du sous-echantillon sont differents\n";
  }else{
    //Calcul du gradient de l'erreur moyen sur le sous-echantillon (x,y)
    vector<Matrice> moyenne;
    moyenne.push_back(Matrice(couches[0].getNbNeurones(), entrees.getNbNeurones()));
    moyenne.push_back(Matrice(couches[0].getNbNeurones(), 1));
    moyenne[0].setCoefs(0);
    moyenne[1].setCoefs(0);
    for(int i=1;i<nbCouchesCachees;i++){
      moyenne.push_back(Matrice(couches[i].getNbNeurones(), couches[i-1].getNbNeurones()));
      moyenne.push_back(Matrice(couches[i].getNbNeurones(), 1));
      moyenne[2*i].setCoefs(0);
      moyenne[2*i+1].setCoefs(0);
    }

    for(int i=0;i<x.size();i++){
      cout<<"etape "<<i<<"de la BP\n";
      calcSorties(x[i]);
      cout<<y[i].getNeurone(0).getSortie()<<" Sortie neurone 0\n";
      cout<<y[i].getNeurone(1).getSortie()<<" Sortie neurone 1\n";
      cout<<y[i].getNeurone(2).getSortie()<<" Sortie neurone 2\n";

      calcGradErr(y[i]);
      cout<<"YOOOOOOOOOO\n";
      gradientErr[2*nbCouchesCachees-1].afficheMatrice();
      for(int j=moyenne.size()-1;j>=0;j--){
        moyenne[j] = moyenne[j].operator + (gradientErr[j]);
        cout<<"tttest\n";
        moyenne[j].afficheMatrice();
      }
    }
    for(int j=0;j<moyenne.size();j++){
      moyenne[j].divMatrice(x.size());
    }
    //Modification des poids et des biais
    for(int j=0;j<nbCouchesCachees;j++){

      couches[j].getLiaisonEntrees() = couches[j].getLiaisonEntrees() - moyenne[2*j];
      couches[j].getBiais() = couches[j].getBiais() - moyenne[2*j+1];
    }
  }
}

void Reseau::Remplissage(vector<CoucheEntrees>& x, vector<CoucheSorties>& y, string nomFic)
{
    ifstream fichier( nomFic ); //Ouverture en lecture

    if ( fichier )
    {
        string ligne; // variable contenant chaque ligne lue
        double buffer;

    getline( fichier, ligne ); //Recupere la 1ere ligne contenant differentes infos
      vector<string> result;
      istringstream iss(ligne); // creer un flux a partir de la chaîne donnee
      string str;
      while (getline(iss, str, ' ')) //Le separateur est un espace
      {
        result.push_back(str); //On stock les elements de chaque ligne dans un vector result
      }
    //Premiere ligne : nbLignes, 1nbColonnes, et nbNeurones d'entree
    int nbLignes = stoi(result[0]);
    int nbColonnes = stoi(result[1]);
    int nbNeurones = stoi(result[2]);
    int ind = 0; //indice des individus

    //Construction de nos vectors
    for(int i=0;i<nbLignes;i++)
    {
        x.push_back(CoucheEntrees(nbNeurones));
        y.push_back(CoucheSorties(nbColonnes-nbNeurones, couches[nbCouchesCachees-1].getNbNeurones()));
    }

        while ( getline( fichier, ligne ) && (ind<nbLignes))
        {
          result.clear();
          istringstream iss(ligne); //// creer un flux a partir de la chaîne donnee
          while (getline(iss, str, ' '))
            result.push_back(str);

          //Set les entrees
          for(int i=0; i<nbNeurones; i++)
          {
            buffer = stod(result[i]);
                  x[ind].modifNeurone(i,buffer); //On set la sortie du neurone
          }
          //Set les sorties
          for (int i = 0; i < y[ind].getNbNeurones(); i++)
          {
            int buffer2 = stoi(result[nbColonnes-i-1]);
            if (buffer2==1)
            {
              y[ind].modifNeurone(i,1);
            }
            else
            {
              y[ind].modifNeurone(i,0);
            }
          }
          ind++;
        }
        cout<<"COUT\n";
        cout<<y[1].getNeurone(1).getSortie()<<"\n";
    }
}

//construit l'echantillon d'apprentissage, elle divise en sous-echantillon et elle appelle la methode BackPropagation sur chaque sous-echantillon
void Reseau::Apprentissage(string Donnees){
  //construction des vecteurs entrees/sorties a partir du fichier Donnees
  vector<CoucheEntrees> lesEntrees;
  vector<CoucheSorties> lesSorties;
  vector<CoucheEntrees> &var1 = lesEntrees;
  vector<CoucheSorties> &var2 = lesSorties;
  Remplissage(var1, var2, Donnees);

  if(lesEntrees.size() != lesSorties.size()){
    cout << "erreur : le nombre d''entrees et de sortie de l''echantillon d''apprentissage sont differents" << '\n';
  }else{
    /*
    cout<<"nb neurones entrees : "<<entrees.getNbNeurones()<<"\n";
    cout<<"Poids et biais avant apprentissage : \n";
    for (int i = 0; i < nbCouchesCachees; i++) {
      cout<<"Couche "<<i+1<<"\n";
      couches[i].afficheMatrices();
    }
    //On construit des sous-echantillon d'apprentissage (xi,yi)
    int tailleSousEchantllons = 5; //choix arbitraire
    int nbEchantillon = (int) lesEntrees.size() / tailleSousEchantllons;
    cout<<"nombre d'individus dans l'echantillon : "<<lesEntrees.size()<<"\n";
    cout<<"nombre d'echantillon : "<<nbEchantillon<<" taille des echantillon : "<<tailleSousEchantllons<<"\n";
    for (int i = 0; i < nbEchantillon; i++) {
      vector<CoucheEntrees> EntreesSousEchan;
      vector<CoucheSorties> SortiesSousEchan;
      for (int j = 0; j < tailleSousEchantllons; j++) {
        EntreesSousEchan.push_back(lesEntrees[i*tailleSousEchantllons+j]);
        SortiesSousEchan.push_back(lesSorties[i*tailleSousEchantllons+j]);
      }
        cout<<"YOOOlo\n";
  cout<<lesSorties[0].getNeurone(0).getSortie()<<"\n";
  cout<<SortiesSousEchan[0].getNeurone(0).getSortie()<<"\n";
      BackPropagation(EntreesSousEchan, SortiesSousEchan);
      cout<<"Poids et biais à l'étape "<<i+1<<" :\n";
      for (int k = 0; k < nbCouchesCachees; k++) {
        cout<<"\nCouche "<<k+1<<"\n";
        couches[k].afficheMatrices();
      }
    }
    */
  BackPropagation(lesEntrees, lesSorties);

  }
}

int Reseau::getNbNeuronesEntree()
{
  return entrees.getNbNeurones();
}
