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


#include "Interface.hpp"


using namespace CppUnit;
using namespace std;

// La classe qui va faire le test 
class TestInterface : public CppUnit::TestFixture{

// Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestInterface);
    CPPUNIT_TEST(testLectureParam);
    CPPUNIT_TEST(testLectureFichier);
    CPPUNIT_TEST_SUITE_END();

public:
// Pour initialiser les variables et allouer de la mémoire
	void setUp(void);
// Pour supprimer une variable et désallouer la mémoire
	void tearDown(void);
protected:
	void testLectureParam(void);
	void testLectureFichier(void);
private:
	Interface *I1, *I2, *I3, *I4, *I5, *I6, *I7;
};

// Les test----------------------------------------------------------------------------------

void TestInterface::testLectureParam(void)
{

}

void TestInterface::testLectureFichier(void)
{
    CPPUNIT_ASSERT ( {0} == I1-> lectureFichier('TestVide.csv') ) // à vérifier le singleton 
    CPPUNIT_ASSERT ( {-1} == I2-> lectureFichier('TestMalRempliTypeReseau.csv') )
    CPPUNIT_ASSERT ( {-1} == I3-> lectureFichier('TestMalRempliCasUtilisation.csv') )
	CPPUNIT_ASSERT ( {-1} == I4-> lectureFichier('TestMalRempliNbCouche.csv') )
	CPPUNIT_ASSERT ( {-1} == I5-> lectureFichier('TestMalRempliNbNeurone.csv') )
    CPPUNIT_ASSERT ( {-2} == I6-> lectureFichier('TestMauvaisFormat.csv') )
    CPPUNIT_ASSERT ( {1, 1, 3, 2, 5, 2, 0} == I7-> lectureFichier('TestDonnees.csv') )
}

void TestInterface::setUp(void)
{
// à l'aide du constructeur Interface()
	I1 = new Interface(String 'TestVide.csv');
    I2 = new Interface(String 'TestMalRempliTypeReseau.csv');
    I3 = new Interface(String 'TestMalRempliCasUtilisation.csv');
    I4 = new Interface(String 'TestMalRempliNbCouche.csv');
    I5 = new Interface(String 'TestMalRempliNbNeurone.csv');
    I6 = new Interface(String 'TestMauvaisFormat.csv');
    I7 = new Interface(String 'TestDonnees.csv');
}
void TestCouche::tearDown(void)
{
	delete I1;
    delete I2;
    delete I3;
    delete I4;
    delete I5;
    delete I6;
    delete I7;
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
	ofstream xmlFileOut("cppTestInterface.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
