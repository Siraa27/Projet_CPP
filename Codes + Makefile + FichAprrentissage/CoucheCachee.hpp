#ifndef COUCHE_CACHEE_HPP
#define COUCHE_CACHEE_HPP
#include "Couche.hpp"
#include "Matrice.hpp"
#include <iostream>
#include <math.h> 

/*!
 * \file CoucheCachee.hpp
 * \brief C'est une classe qui permet de créer les couches cachées du réseau, ainsi que de définir leur biais
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_couches_du_reseau
 */

/*! \class CoucheCachee
* \brief Classe représentant une couche cachée
*
*/
class CoucheCachee : public Couche{
   
   // Les attributs 
   private : 
      Matrice biais; /*!< Le biais qui va être optimisé lorsque le programme va tourner pour */
      Matrice LiaisonsEntrees; /*!< Matrice des poids initialisée en entrée via l'InterfaceUtilisateur */
        
   //Les méthodes
   public :
      /*!
      *  \brief Constructeur par recopie de la classe CoucheCachee
      */ 
      CoucheCachee(const CoucheCachee&);
      /*!
      *  \brief Constructeur de la classe CoucheCachee
      *  \param nbNeurones : nombre de neurones par couche, fixe d'où le "const"
      * \param nbNeuronesCouchePrec : nombre de neurones de la couche précedente (ça nous sert pour faire les liaison)
      */ 
	   CoucheCachee (const int nbNeurones, const int nbNeuronesCouchePrec); /*!<  Le nombre de neurones d'une couche ne change pas au cours du programme une fois fixé  */

      /*!
      *  \fn getLiaisonEntrees()
      *  \brief Permet a acceder a la matrice LiaisonEntrees de la couche
      *  \return matrice des liaisons
      */
      Matrice& getLiaisonEntrees();
      
      /*!
      *  \fn getBiais()
      *  \brief Permet a acceder a la matrice biais de la couche
      *  \return matrice des biais
      */
      Matrice& getBiais();
      
      /*!
      *  \fn setBiais()
      *  \brief Permet de set un coef de la matrice biais de la couche
      */
      void setBiais(const int i,const int j,const double coef );

      /*!
      *  \fn preActivation()
      *  \brief La fonction de pré activation : méthode qui permet de faire la somme pondérée des entrées
      *  \return matrice des sommes pondérées des entrées pour chaque neurone
      */
      Matrice preActivation(const Couche couchePrec);
      
      /*!
      *  \fn foncActivation(Matrice sum)
      *  \brief La fonction d'activation : méthode qui permet d'activer les neurones afin d'optimiser le biais et avoir le bon résultat en sortie
      *  \param Matrice resultant de la fonction de pre activation
      *  \return Elle modifie directement la sortie des neurones
      */
      void foncActivation(Matrice sum);
       
      /*!
      *  \fn derivFoncActivation()
      *  \brief Derivee de la fonction d'activatino
      *  \return valeur de la derivee evaluee en x
      */
      double derivFoncActivation(const double x);

      void afficheMatrices() const;
};

#endif
