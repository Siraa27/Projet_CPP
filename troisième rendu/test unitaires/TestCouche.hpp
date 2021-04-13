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
#include "CoucheEntree.hpp"
#include "CoucheCachee.hpp"
#include "CoucheSortie.hpp"

using namespace CppUnit;
using namespace std;

// La classe qui va faire le test 
class TestCouche : public CppUnit::TestFixture{

// Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestCouche);
    CPPUNIT_TEST(testPreActivation);
    CPPUNIT_TEST(testActivation);
    CPPUNIT_TEST_SUITE_END();

public:
// Pour initialiser les variables et allouer de la mémoire
	void setUp(void);
// Pour supprimer une variable et désallouer la mémoire
	void tearDown(void);
protected:
	void testPreActivation(void);
	void testActivation(void);
private:
	Couche *C1;
};

// Les test----------------------------------------------------------------------------------

void TestCouche::testpreActivation(void)
{
    // CPPUNIT_ASSERT() ==> bool
   CPPUNIT_ASSERT(6,87 == C->preActivation());
}

void TestCouche::testactivation(void)
{
   CPPUNIT_ASSERT( 0.001 == C->activation(6,87));
}

void TestCouche::setUp(void)
{
// à l'aide du constructeur Couche(int nbNeurone, double ValeurEntree[nbNeurone], double biais[], double MatriceLiaison [][])
	C = new Couche(4, {6.3, 3.3, 6.0, 2,5}, {0.5,0.8}, { {0.1, 0.2} , {0.3, 0.4}, {0.5, 0.6}, {0.7, 0.8} });
}
void TestBasicMath::tearDown(void)
{
	delete C;
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
    // register listener for per-test progress output // pas compris 
	CPPUNIT_NS::BriefTestProgressListener progress; // pas compris
	testresult.addListener (&progress); // pas compris 
	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
	testrunner.run(testresult);
	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write ();
	// Output XML for Jenkins CPPunit plugin
	ofstream xmlFileOut("cppTestCouche.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}