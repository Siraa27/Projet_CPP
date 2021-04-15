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


#include "Couche.hpp"
#include "CoucheEntrees.hpp"


using namespace CppUnit;
using namespace std;

// La classe qui va faire le test 
class TestCoucheEntrees : public CppUnit::TestFixture{
    // Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestCouche);
    CPPUNIT_TEST(testConstructionSortie);
    CPPUNIT_TEST_SUITE_END();

public:
// Pour initialiser les variables et allouer de la mémoire
	void setUp(void);
// Pour supprimer une variable et désallouer la mémoire
	void tearDown(void);
protected:
	void testConstructionSortie(void);
private:
	Couche *C1, *C2;
}

// Les test----------------------------------------------------------------------------------

void TestCoucheEntrees::testConstructionSortie(void)
{   
	C1->constrcutionSortie();
	C2->constructionSortie();
   if ( CPPUNIT_ASSERT( C2->nbNeurone ==4 ) ){
        int i = 0 ; 
        while ( CPPUNIT_ASSERT( C1->Neurone[i] == C2->Neurone[i] ) && i<4 ) {
            i=i+1; 
        }  
   } 
}

void TestCoucheEntrees::setUp(void)
{
// à l'aide du constructeur Couche(int nbNeurone, double ValeurEntree[nbNeurone])
	C1 = new CoucheEntree(4,{6.3, 3.3, 6.0, 2,5});
    C2 = new CoucheEntree('FichDonnee.csv');
}
void TestCoucheEntrees::tearDown(void)
{
	delete C1;
    delete C2;
}
//-------------------------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestCouche );
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
	ofstream xmlFileOut("cppTestCoucheEntrees.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}