#include <iostream>
#include <string>
#include <list>
#include <cmath>


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
	Matrice *M1, *M2, *M4, *M5, *M6, *M7;

};

// Les tests----------------------------------------------------------------------------------

void TestMatrice::setUp(void)
{
// à l'aide du constructeur Matrice
    //les matrices M1, M2 et M6 servent pour le premier test
    M1 = new Matrice(3, 3);
    M2 = new Matrice(3, 3); //on choisit de ne creer que des matrices particulieres pour simplifier la comprehension
    M6 = new Matrice(3, 3); //Matrice résultat du produit de matrices M1*M2 : M6={{6,9,12},{6,9,12},{6,9,12}}
    M4 = new Matrice(1,2);  // M4= {{3, 1}}
    M5 = new Matrice(2, 3); // M5={{1, 8, 4} , {7, 1, 6}}
    M7 = new Matrice(1, 3); //Matrice résultat du produit de matrices M4*M5 : M7={22, 11, 22}


}

void TestMatrice::tearDown(void)
{
	delete M1;
    delete M2;
    delete M4;
    delete M5;
    delete M6;
    delete M7;

}
void TestMatrice::testProduit(void)
{
    for (int i=0; i<3 ; i++)
    {
        for (int j=0; j<3 ; j++)
        {
            M1->setCoefMatrice(i,j,1); //Matrice ou tous les coeff =1
            M2->setCoefMatrice(i,j,i+j+1); //M2={{1,2,3},{2,3,4},{3,4,5}}
            
        }
    }
    M6->setCoefMatrice(0,0,6);
    M6->setCoefMatrice(1,0,6);
    M6->setCoefMatrice(2,0,6);
    M6->setCoefMatrice(0,1,9);
    M6->setCoefMatrice(1,1,9);
    M6->setCoefMatrice(2,1,9);
    M6->setCoefMatrice(0,2,12);
    M6->setCoefMatrice(1,2,12);
    M6->setCoefMatrice(2,2,12);

    
    //les matrices M4, M5 et M7 servent pour le 3e test, celui avec des matrices non carrées
    
    //On initialise les coefficients manuellement
    M4->setCoefMatrice(0,0,3);
    M4->setCoefMatrice(0,1,1);
    M5->setCoefMatrice(0,0,1);
    M5->setCoefMatrice(0,1,8);
    M5->setCoefMatrice(0,2,4);
    M5->setCoefMatrice(1,0,7);
    M5->setCoefMatrice(1,1,1);
    M5->setCoefMatrice(1,2,6);
    M7->setCoefMatrice(0,0,10);
    M7->setCoefMatrice(0,1,25);
    M7->setCoefMatrice(0,2,18);
    

    Matrice *test2 ;
    test2 = new Matrice(3,3);
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
    //(10,25,18)
                test2->setCoefMatrice(i,j, M1->operator *(*M2).getCoefMatrice(i,j));
               //std::cout << "test2 " << j << " " << test2->getMatrice()[i][j] << std::endl ;
        }
    }
    //test matrices carrées :
  for (int i=0; i<=2; i++) {//le 2 correspond aux indices ligne pour la matrice résultat M6 à 3 lignes
		for (int j=0; j<=2; j++){ //le 2 correspond aux indices colonnes pour la matrice résultat M6 à 3 colonnes
   			CPPUNIT_ASSERT( fabs( M6->getMatrice()[i][j] - test2->getMatrice()[i][j])<0.01);
   		}
  }


   //test matrices non carrées mais bon format:  M1(nxp)*M2(pxq) == M(nxq)
    Matrice *test ;
    test = new Matrice(1,3);

    for (int j=0; j<3; j++){
    //(10,25,18)
    test->setCoefMatrice(0,j, M4->operator *(*M5).getCoefMatrice(0,j));
    //std::cout << "test " << j << " " << test->getMatrice()[0][j] << std::endl ;
    
    }
   
		for (int j=0; j<3; j++) {
		       
   			CPPUNIT_ASSERT(fabs( M7->getMatrice()[0][j] - test->getMatrice()[0][j])<0.01); 
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
