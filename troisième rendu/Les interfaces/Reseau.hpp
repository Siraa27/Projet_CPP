#include <iostream>
#include <string>
#include <list>

#ifndef FICHIER_HPP
#define FICHIER_HPP

using namespace std;

class Reseau {

	// Les attributs
	private:
		double solde;
		static int nbC;
		int numero;
		list<string> titulaires;
	
	// Les constructeurs
	public: 
		Compte();
		Compte(double s);
		
	// Les methodes
	public: 
		void deposer(double const x);
		void retirer(double const x);
		double getSolde() const;	// Cette methode n'a pas le droit de modifier les attributs
		static int nbComptes();
		int getNumero() const;
		void ajouterTitulaire(string nom);
		bool retirerTitulaire(int i);
		string operator [] (int i) const;
		friend std::ostream& operator<< (std::ostream& flux, Compte const& compte);
	private: 
		void setSolde(double const x);
		void afficher();
	
};

std::ostream& operator<< (std::ostream& flux, Compte const& compte);

#endif
