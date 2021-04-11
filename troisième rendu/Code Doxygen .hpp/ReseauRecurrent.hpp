#ifndef RESEAURECURRENT_HPP
#define RESEAURECURRENT_HPP
#include "Reseau.hpp"

/*!
 * \file ReseauRecurrent.hpp
 * \brief C'est un classe qui permet de spécifier le type de réseau désiré, ici : type récurrent, permet donc de préciser les arguments (forme du réseau spécifique)
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_types_de_reseaux
 * une classe qui permet de créer un certain type de réseau
 */

namespace Les_types_de_reseaux 
{
   /*! \class Reseau
   * \brief classe permettant de représenter un réseau quelconque
   *
   *  La classe génère le réseau souhaité
   */ 
   class ReseauRecurrent: public Reseau
{
	//Attributs
	private : 
		int[] nbNeuronesLiés; /*!< détermine la structure du réseau en donner le nombre de neurones qui doivent être liés */
		
	//Constructeurs
	public :
		ReseauRecurrent();
		
			
	};

};

#endif
