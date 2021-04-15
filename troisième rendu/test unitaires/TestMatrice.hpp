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
	Matrice *M1, *M2, *M3, *M4, *M5; //jsp si y a besoin de l'*
};

// Les tests----------------------------------------------------------------------------------

void TestMatrice::testProduit(void)
{
    // CPPUNIT_ASSERT() ==> bool
   CPPUNIT_ASSERT( {{30, 36, 42} , {66, 81, 96}, {102, 126, 150}} == M1->produit(M2));
   CPPUNIT_ASSERT ( {-1} == M1-> produit(M3) ); //la fonction produit renvoie -1 si on a une erreur de format : M1(nxp)*M2(pxq) == M(nxq)
   CPPUNIT_ASSERT( {{22, 11, 22}} == M4->produit(M5)); 

}

void TestMatrice::setUp(void)
{
// à l'aide du constructeur Couche(int nbNeurone, double ValeurEntree[nbNeurone], double biais[], double MatriceLiaison [][])
	M1 = new Matrice({{1, 2, 3} , {4, 5, 6}, {7, 8, 9}});
    M2 = new Matrice({{1, 2, 3} , {4, 5, 6}, {7, 8, 9}});
    M3 = new Matrice({{1, 1} , {1, 1}}); //Création d'une matrice pour le test sur le mauvais format 
    M4 = new Matrice({{3, 1}}); //les matrices M4 et M5 servent pour le 3e test, celui avec des matrices non carrées
    M5 = new Matrice({{1, 8, 4} , {7, 1, 6}});
}
void TestMatrice::tearDown(void)
{
	delete M1;
    delete M2;
    delete M3;
    delete M4;
    delete M5;

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