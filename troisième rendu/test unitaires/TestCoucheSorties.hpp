
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
#include "CoucheSorties.hpp"


using namespace CppUnit;
using namespace std;

// La classe qui va faire le test 
class TestCoucheSorties : public CppUnit::TestFixture{
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
	void testPreActivation(void);
	void testActivation(void);
private:
	Couche *C;
}

// Les test----------------------------------------------------------------------------------

void TestCoucheSorties::testCalculortie(void)
{   
	
}
void TestCoucheSortie::testpreActivation(void)
{
    // CPPUNIT_ASSERT() ==> bool
	double t[3];
	t = C1->preActivation();
    CPPUNIT_ASSERT( fabs(3.856 - t[1]) < 0.00001 &&  fabs(7.027 - t[2]) < 0.00001 && fabs(10,197 - t[3]) < 0.00001) ;
}
/* c'est la même chose que calcul sortie
void TestCoucheSortie::testactivation(void)
{
	// nous allons utiliser ici une fonctin qui prednra le max 
	C1->activation({3.856, 7.027, 10.197});
    int i = 0 ; 
    while ( CPPUNIT_ASSERT( C2->Neurone[i] == C1->Neurone[i] )  && i<3 ) {
            i=i+1; 
        }  

}
*/
void TestCoucheSortie::setUp(void)
{
// ça me parait bizarre de construire une coucheSortie vaec un tableau de neurone qui a comme valeur ceux  d'une coucheCachee
	C1 = new CoucheSortie(3, {6.87, 8.98}, {0,0},  { {0.2,0.5,0.7}, {0.2,0.4,0.6} });

	C2 = new CoucheSortie(3, {0,0,1}, {0,0}, { {0, 0,0} , {0, 0,0} });

}
void TestCouche::tearDown(void)
{
	delete C1;
	delete C2;
}

void TestCoucheCachee::testCalculSortie(void)
{  

  C1.calculSortie();
  int i = 0 ; 
   while ( CPPUNIT_ASSERT( C2->Neurone[i] == C1->Neurone[i] ) && i<4 ) {
            i=i+1; 
        }  
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
	ofstream xmlFileOut("cppTestCoucheSorties.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}