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
 */

   /*! \class TestMatrice
   * \brief Classe pour tester les fonctions sur les Matrices
   *
   */

 
class TestMatrice : public CppUnit::TestFixture {
// Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestMatrice); /*!< Crée une suite de tests à l'aide d'une macro*/
    CPPUNIT_TEST(testProduit);/*!< ajoute à la suite de test le test TestProduit */
    CPPUNIT_TEST_SUITE_END(); /*!< macro définissant la fin de la suite de tests à effectuer */

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

     //Les attributs 
private:
	Matrice *M1, *M2, *M3, *M4, *M5, *M6, *M7;

};

// Les tests----------------------------------------------------------------------------------

void TestMatrice::setUp(void)
{
// à l'aide du constructeur Matrice
    //les matrices M1, M2 et M6 servent pour le premier test
	M1 = new Matrice(3, 3);
    M2 = new Matrice(3, 3); //on choisit de ne creer que des matrices particulieres pour simplifier la comprehension
	M6 = new Matrice(3, 3); //Matrice résultat du produit de matrices M1*M2 : M6={{6,9,12},{6,9,12},{6,9,12}}

    for (int i=0; i<3 ; i++)
    {
        for (int j=0; j<3 ; j++)
        {
            M1->setCoefMatrice(i,j,1); //Matrice ou tous les coeff =1
            M2->setCoefMatrice(i,j,i+j+1); //M2={{1,2,3},{2,3,4},{3,4,5}}
            if (j=0){
                M6->setCoefMatrice(i,j,6);
            }
            else if (j=1){
                M6->setCoefMatrice(i,j,9);
            }
            else if (j=2){
                M6->setCoefMatrice(i,j,12);
            }
        }
    }
    //les matrices M4, M5 et M7 servent pour le 3e test, celui avec des matrices non carrées
    M4 = new Matrice(1,2);  // M4= {{3, 1}}
    M5 = new Matrice(2, 3); // M5={{1, 8, 4} , {7, 1, 6}}
	M7 = new Matrice(1, 3); //Matrice résultat du produit de matrices M4*M5 : M7={22, 11, 22}
    //On initialise les coefficients manuellement
    M4->setCoefMatrice(0,0,3);
    M4->setCoefMatrice(0,1,1);
    M5->setCoefMatrice(0,0,1);
    M5->setCoefMatrice(0,1,8);
    M5->setCoefMatrice(0,2,4);
    M5->setCoefMatrice(1,0,7);
    M5->setCoefMatrice(1,1,1);
    M5->setCoefMatrice(1,2,6);
    M7->setCoefMatrice(0,0,22);
    M7->setCoefMatrice(0,1,11);
    M7->setCoefMatrice(0,2,22);
}

void TestMatrice::tearDown(void)
{
	delete M1;
    delete M2;
    delete M3;
    delete M4;
    delete M5;
	delete M6;
    delete M7;

}
void TestMatrice::testProduit(void)
{
    //test matrices carrées :
   for (int i=0; i<=2; i++) //le 2 correspond aux indices ligne pour la matrice résultat M6 à 3 lignes
		for (int j=0; j<=2; j++) //le 2 correspond aux indices colonnes pour la matrice résultat M6 à 3 colonnes
   			CPPUNIT_ASSERT( M6->getCoefMatrice(i,j) == (M1->operator *(*M2)).getCoefMatrice(i, j));

    //EN SUSPENS 		   
	//test mauvais format de matrices 
    //CPPUNIT_ASSERT ( {-1} == M1*(M3) ); //la fonction produit renvoie -1 si on a une erreur de format : M1(nxp)*M2(pxq) == M(nxq)

   //test matrices non carrées mais bon format:  M1(nxp)*M2(pxq) == M(nxq)
   for (int i=0; i<=0; i++) {//le zero correspond à l'unique indice ligne pour la matrice résultat M7 à 1 ligne
		for (int j=0; j<=2; j++) {//le 2 correspond aux indices colonnes pour la matrice résultat M7 à 3 colonnes
   			CPPUNIT_ASSERT( M7->getCoefMatrice(i, j) == (M4->operator *(*M5).getCoefMatrice(i, j))); 
        }
   }

}


//-------------------------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestMatrice );
int main(int argc, char* argv[])
{
    // informs test-listener about testresults
	CPPUNIT_NS::TestResult testresult;
    // register listener for collecting the test-results
	CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);
    // register listener for per-test progress output
	CPPUNIT_NS::BriefTestProgressListener progress; 
	testresult.addListener (&progress); 
	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
	testrunner.run(testresult);
	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write ();
	// Output XML for Jenkins CPPunit plugin
	ofstream xmlFileOut("cppTestMatrice.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
