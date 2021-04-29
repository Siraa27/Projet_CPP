#include <iostream>
#include <string>

#include <vector>
#include <iterator>

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
#include "InterfaceFichier.hpp"

/////////////   g++ -o testInterfaceFichier InterfaceFichier.cpp Interface.cpp TestInterfaceFichier.cpp -lcppunit

using namespace CppUnit;
using namespace std;

// La classe qui va faire le test 
class TestInterfaceFichier : public CppUnit::TestFixture{

// Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestInterfaceFichier);
   // CPPUNIT_TEST(testLectureParam);
    CPPUNIT_TEST(testLectureFichier);
    CPPUNIT_TEST_SUITE_END();

public:
// Pour initialiser les variables et allouer de la mémoire
	void setUp(void);
// Pour supprimer une variable et désallouer la mémoire
	void tearDown(void);
protected:
	void testLectureFichier(void);
private:
	InterfaceFichier *I1,*I2,*I31,*I32,*I33,*I34,*I4,*I5,*I6,*I7;
};

///////////////////////////////////////////////////////// Les tests///////////////////////////////////////////////////////////////////////////////////

void TestInterfaceFichier::testLectureFichier(void)
{
	cout<<"Fichier non existant \n";
	I1->lectureFichier("TestBlabla.csv");
    CPPUNIT_ASSERT (-1 == I1->gettypeReseau() );

	cout<<"Fichier fichier vide\n";
	I2->lectureFichier("TestFichierVide.txt");
    CPPUNIT_ASSERT (-1 == I2->gettypeReseau() );
	I31->lectureFichier("TestFichierMalRempli1.csv");//Nombre de couche cachees non valide

    CPPUNIT_ASSERT (-1 == I31->getnbCouchesCachees() );
	I32->lectureFichier("TestFichierMalRempli2.csv");//Poid inf a 0
    CPPUNIT_ASSERT (-1 == I32->getchoixPoid() );

	I33->lectureFichier("TestFichierMalRempli3.csv");//CNb neurones dans couche cachee nulle
    CPPUNIT_ASSERT (-1 == I33->getnbNeuronesParCouches(0) );

	I34->lectureFichier("TestFichierMalRempli4.csv");//Nb neurones dans couche cachee negatif
    CPPUNIT_ASSERT (-1 == I34->getnbNeuronesParCouches(0) );

	I4->lectureFichier("TestFichierManqueDonnees.csv");
    CPPUNIT_ASSERT (-1 == I4->gettypeReseau() );

	I5->lectureFichier("TestFichierMauvaisFormat.pdf");
    CPPUNIT_ASSERT (-1 == I5->getchoixPoid() );
    
    
    
    cout<<"Fichier conforme sans couche cachée\n";
	I6->lectureFichier("TestBonFichierSansCC.csv");
    CPPUNIT_ASSERT (1 == I6->gettypeReseau() );
    CPPUNIT_ASSERT (1 == I6->getcasUtilisation() );
    CPPUNIT_ASSERT (0 == I6->getnbCouchesCachees() );
	CPPUNIT_ASSERT (8 == I6->getnbNeuronesEntree() );
	CPPUNIT_ASSERT (3 == I6->getnbNeuronesSortie() );
    CPPUNIT_ASSERT (0 == I6->getnbNeuronesParCouches(0) );
    CPPUNIT_ASSERT (0 == I6->getchoixPoid() );
    
    
	cout<<"Fichier conforme\n";
	I7->lectureFichier("TestBonFichier.csv");
    CPPUNIT_ASSERT (1 == I7->gettypeReseau() );
    CPPUNIT_ASSERT (1 == I7->getcasUtilisation() );
    CPPUNIT_ASSERT (4 == I7->getnbCouchesCachees() );
	CPPUNIT_ASSERT (8 == I7->getnbNeuronesEntree() );
	CPPUNIT_ASSERT (3 == I7->getnbNeuronesSortie() );
    CPPUNIT_ASSERT (2 == I7->getnbNeuronesParCouches(0) );
    CPPUNIT_ASSERT (4 == I7->getnbNeuronesParCouches(1) );
    CPPUNIT_ASSERT (6 == I7->getnbNeuronesParCouches(2) );
	CPPUNIT_ASSERT (5 == I7->getnbNeuronesParCouches(3) );
    CPPUNIT_ASSERT (0 == I7->getchoixPoid() );
}


void TestInterfaceFichier::setUp(void)
{
	I1 = new InterfaceFichier();
	I2 = new InterfaceFichier();
	I31 = new InterfaceFichier();
	I32 = new InterfaceFichier();
	I33 = new InterfaceFichier();
	I34 = new InterfaceFichier();
	I4 = new InterfaceFichier();
	I5 = new InterfaceFichier();
	I6 = new InterfaceFichier();
    I7 = new InterfaceFichier();
}
void TestInterfaceFichier::tearDown(void)
{
	delete I1;
    delete I2;
	delete I31;
    delete I32;
    delete I33;
	delete I34;
	delete I4;
	delete I5;
	delete I6;
    delete I7;
}

////////////////////////////////////////////////////////////////// *~MAIN~* /////////////////////////////////////////////////////////

CPPUNIT_TEST_SUITE_REGISTRATION( TestInterfaceFichier );
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
