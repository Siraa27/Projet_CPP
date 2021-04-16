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


#include "Reseau.hpp"


using namespace CppUnit;
using namespace std;

// La classe qui va faire le test 
class TestReseau : public CppUnit::TestFixture{

// Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestReseau);
    CPPUNIT_TEST(testConstructeurReseau);
    CPPUNIT_TEST(testbackPropagation);
    CPPUNIT_TEST_SUITE_END();

public:
// Pour initialiser les variables et allouer de la mémoire
	void setUp(void);
// Pour supprimer une variable et désallouer la mémoire
	void tearDown(void);
protected:
	void testConstructeurReseau(void));
    void testbackPropagation(void);
    
private:
	Reseau *R1, *R2; 
};

// Les tests----------------------------------------------------------------------------------

void TestReseau::testConstructeurReseau(void)
{
    // CPPUNIT_ASSERT() ==> bool
    //1 pour type Forwarded, 1 pour classification, 3 pour couche cachée, 2 pour neurone par couche, 0 pour init aléatoire des poids init
   CPPUNIT_ASSERT({1}==int(Reseau(listeParametres[0])) && {1}==int(Reseau(listeParametres[1])) && {3}==int(Reseau(listeParametres[2])) &&){2}==int(Reseau(listeParametres[3])) && abs( float(Reseau(listeParametres[4])) - 0 ) < O.00OO1)
   CPPUNIT_ASSERT({1}==int(Reseau(listeParametres[0])) && {2}==int(Reseau(listeParametres[1])) && {1}==int(Reseau(listeParametres[2])) &&){4}==int(Reseau(listeParametres[3])) && abs( float(Reseau(listeParametres[4])) - 0.5 ) < O.00OO1) //permet de tester un égalité entre flottants à epsilon près
   
}  
   void TestReseau::testbackPropagation(void)
{
    // CPPUNIT_ASSERT() ==> bool
   CPPUNIT_ASSERT( taille(x)==taille(y));
    

}

void TestReseau::setUp(void)
{
// à l'aide du constructeur 
	R1 = new Reseau('listeParam_Pour_ReseauForwarded_pour_classification_A_3_couches_2_neurones_par_couche_Et_Poids_Init_Aleatoirement');
    R2 = new Reseau('listeParam_Pour_ReseauForwarded_pour_prediction__A_1_couches_4_neurones_par_couche_Et_Poids_Fixés_par_utilisateur');


}
void TestReseau::tearDown(void)
{
	delete R1;
	delete R2;


}
//-------------------------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestReseau );
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
	ofstream xmlFileOut("cppTestReseau.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}