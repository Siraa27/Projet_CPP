#ifndef Matrice_HPP
#define Matrice_HPP

#include <iostream>
#include <string>
#include <list>

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>


#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>


#include "Matrice.hpp"


using namespace CppUnit;
using namespace std;
/*!
 * \file TestMatrice.hpp
 * \brief Classe test pour la classe Matrice : permet de réaliser les tests unitaires
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_tests_unitaires
 * Classe pour tester les fonctions sur les Matrices
 */

//namespace Les_tests_unitaires
//{
   /*! \class TestMatrice
   */
    class TestMatrice : public CppUnit::TestFixture{
        
        //Les attributs 
        private:
	        Matrice *M1, *M2, *M3, *M4, *M5, *M6, *M7;

// Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestMatrice);
    CPPUNIT_TEST(testProduit);
    CPPUNIT_TEST_SUITE_END();

            public :
             /*!
             * \fn setUp(void)
             *  \brief Pour initialiser les variables et allouer de la mémoire
             */
		    void setUp(void);
          
             /*!
             *\fn tearDown(void)
             *  \brief Pour supprimer une variable et désallouer la mémoire
             */
            void tearDown(void);

            protected:
            /*!
             * \fn testProduit(void)
             *  \brief Pour tester le produit matriciel de la classe Matrice
             */
	        void testProduit(void);


          
          /*!
          *  \fn initAleatoire()
          *  \brief Pour initialiser les poids de manière aléatoire entre 0 et 1
          */
          void initAleatoire();

          /*!
          *  \fn operator * (Matrice m)
          *  \brief surcharge l'opérateur * pour nos Matrices
          *
          */
          Matrice operator *(const Matrice &); 
          
          /*!
          *  \fn operator + (Matrice m)
          *  \brief surcharge l'opérateur + pour nos Matrices
          *
          */
          Matrice operator +(const Matrice &); 

          /*!
          *  \fn operator - (Matrice m)
          *  \brief surcharge l'opérateur - pour nos Matrices
          *
          */
          Matrice operator -(const Matrice &); 

          /*!
          *  \fn getMatrice
          *  \brief retourne matrice**
          *
          */
          double** getMatrice();
    };
//};
#endif
