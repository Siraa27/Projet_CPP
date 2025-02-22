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
#include "CoucheCachee.hpp"


using namespace CppUnit;
using namespace std;

// La classe qui va faire le test 
class TestCoucheCachee : public CppUnit::TestFixture{
    // Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestCouche);
    CPPUNIT_TEST(testCalculSortie);
	CPPUNIT_TEST(testPreActivation);
    CPPUNIT_TEST(testActivation);
    CPPUNIT_TEST_SUITE_END();

public:
// Pour initialiser les variables et allouer de la mémoire
	void setUp(void);
// Pour supprimer une variable et désallouer la mémoire
	void tearDown(void);
protected:
	void testCalculSortie(void);
	void testPreActivation(void);
	void testActivation(void);
private:
	Couche *C1, *C2, *C3;

}

// Les test----------------------------------------------------------------------------------
void TestCoucheCachee::testpreActivation(void)
{
    // CPPUNIT_ASSERT() ==> bool
	double t[2];
	t = C1->preActivation();
   CPPUNIT_ASSERT( fabs(6.87 - t[1]) < 0.00001 &&  fabs(8.98 - t[2]) < 0.00001) ;
}
/* C'est un peu la même chose que calcul sortie à revoir 
void TestCoucheCachee::testactivation(void)
{
	C2->activation({6.87});
	C2->activation({9,98});

   CPPUNIT_ASSERT( fabs(0.001 -  C2->activation(6,87)) < 0.00001 ); 
   CPPUNIT_ASSERT( fabs( 0.0001258869 - C2->activation(8.98) ) < O.00OO1 ); 
}
*/
void TestCoucheCachee::setUp(void)
{
// un contructeur avec que des zéro pour la matrice de laisiason et que des zéros pour les biais (la couche verte)
	C1 = new CoucheCachee(4, {6.3, 3.3, 6.0, 2,5}, {0,0},  { {0, 0} , {0, 0}, {0, 0}, {0, 0} });
// à l'aide du constructeur Couche(int nbNeurone, double ValeurEntree[nbNeurone], double biais[], double MatriceLiaison [][])
	C2 = new CoucheCachee(2, {6.87, 8.98}, {0.5,0.8}, { {0.1, 0.2} , {0.3, 0.4}, {0.5, 0.6}, {0.7, 0.8} });
	C3 = new CoucheCachee(2, {0.001, 0.0001258869}, {0,0}, { {0, 0} , {0, 0}, {0, 0}, {0, 0} });
}
void TestCoucheCachee::tearDown(void)
{
	delete C1;
	delete C2;
	delete C3;
}

void TestCoucheCachee::testCalculSortie(void)
{  

  C2.calculSortie();
  int i = 0 ; 
   while ( CPPUNIT_ASSERT( fabs(C2->Neurone[i] - C3->Neurone[i] ) < 0.00001) && i<4 ) {
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
	ofstream xmlFileOut("cppTestCoucheCachee.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}