#ifndef RESEAUFORWARDED_HPP
#define RESEAUFORWARDED_HPP
#include "Reseau.hpp"

/*!
 * \file ReseauForwarded.hpp
 * \brief C'est un classe qui permet de spécifier le type de réseau désiré, ici : type feed-forwarded, permet donc de préciser les arguments (forme du réseau)
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_types_de_reseaux
 * Classe qui permet de créer un certain type de réseau
 */

namespace Les_types_de_reseaux 
{
   /*! \class ReseauForwarded
   * \brief Classe permettant de représenter un réseau forwarded. 
   */
   class ReseauForwarded: public Reseau
	{
	//Attributs
	private : 
	    int* nbNeuronesLiés;  /*!< détermine la structure du réseau en donner le nombre de neurones qui doivent être liés */
		
	//Constructeurs
	public :
		ReseauForwarded();
	
	};
};

#endif
