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

// La classe qui va faire le test 
class TestMatrice : public CppUnit::TestFixture{

// Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestMatrice); 
    CPPUNIT_TEST(testProduit);
    CPPUNIT_TEST_SUITE_END();

public:
// Pour initialiser les variables et allouer de la mémoire
	void setUp(void);
// Pour supprimer une variable et désallouer la mémoire
	void tearDown(void);
protected:
	void testProduit(void);
private:
	Matrice *M1, *M2, *M3, *M4, *M5, *M6, *M7; 
}
// Les tests----------------------------------------------------------------------------------

void TestMatrice::testProduit(void)
{
    //test matrices carrées :
   for (i=0; i<=2; i=i+1) //le 2 correspond aux indices ligne pour la matrice résultat M6 à 3 lignes
		for (j=0; j<=2; j=j+1) //le 2 correspond aux indices colonnes pour la matrice résultat M6 à 3 colonnes
   			CPPUNIT_ASSERT( M6[i][j] == M1->produit(M2)[i][j]);
			   
	//test mauvais format de matrices 
   CPPUNIT_ASSERT ( {-1} == M1-> produit(M3) ); //la fonction produit renvoie -1 si on a une erreur de format : M1(nxp)*M2(pxq) == M(nxq)

   //test matrices non carrées mais bon format:  M1(nxp)*M2(pxq) == M(nxq)
   for (i=0; i<=0; i=i+1) //le zero correspond à l'unique indice ligne pour la matrice résultat M7 à 1 ligne
		for (j=0; j<=2; j=j+1) //le 2 correspond aux indices colonnes pour la matrice résultat M7 à 3 colonnes
   			CPPUNIT_ASSERT( M7[i][j] == M4->produit(M5)); 

}

void TestMatrice::setUp(void)
{
// à l'aide du constructeur Matrice
	M1 = new Matrice({{1, 2, 3} , {4, 5, 6}, {7, 8, 9}});
    M2 = new Matrice({{1, 2, 3} , {4, 5, 6}, {7, 8, 9}});
    M3 = new Matrice({{1, 1} , {1, 1}}); //Création d'une matrice pour le test sur le mauvais format 
    M4 = new Matrice({{3, 1}}); //les matrices M4 et M5 servent pour le 3e test, celui avec des matrices non carrées
    M5 = new Matrice({{1, 8, 4} , {7, 1, 6}});
	M6 = new Matrice({{30, 36, 42} , {66, 81, 96}, {102, 126, 150}}) //Matrice résultat du produit de matrices M1*M2
	M7=new Matrice({22, 11, 22}); //Matrice résultat du produit de matrices M4*M5
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