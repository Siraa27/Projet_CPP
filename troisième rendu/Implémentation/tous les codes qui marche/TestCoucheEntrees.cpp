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
#include "Matrice.hpp"


using namespace CppUnit;
using namespace std;

/*!
 * \file TestEntree.cpp
 * \brief C'est une classe qui permet de vérifier que les méthodes utilisées dans CoucheEntree renvoie bien le résultat attendu. 
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_tests_unitaires
 */


   /*! \class TestCoucheEntree
   * \brief Classe pour les tests 
   */

// La classe qui va faire le test 
class TestCoucheEntrees : public CppUnit::TestFixture{
    // Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestCoucheEntrees);
    CPPUNIT_TEST(testConstructionSortie); /*!< Le test qui va vérifier la méthode constructionSortie  */
    CPPUNIT_TEST_SUITE_END();

public:
    /*!
     *  \fn setUp(void)
     *  \brief  Pour initialiser les variables et allouer de la mémoire
    */
	void setUp(void);


	/*!
     *  \fn setUp(void)
     *  \brief  Pour supprimer une variable et désallouer la mémoire
    */
	void tearDown(void);

protected:
    /*!
     *  \fn testConstructionSortie(void)
     *  \brief ume méthode qui teste que la méthode constructionSortie initialise bien les données en entrée
    */
	void testConstructionSortie(void);
private:
	CoucheEntrees *C;

};

//------------------------------------------LES TESTS---------------------------------------------------
//------------------------------------------------------------------------------------------------------

void TestCoucheEntrees::setUp(void)
{
// à l'aide du constructeur Couche(int nbNeurone, double ValeurEntree[nbNeurone])
    C = new CoucheEntrees(4,"FichTest"); //le fichier test contiendra la ligne suivante 6.3,3.3,6.0,2.5
	
}
void TestCoucheEntrees::tearDown(void)
{
	delete C;
}

void TestCoucheEntrees::testConstructionSortie(void)
{   

	std::vector<double> TableauTest;
	TableauTest.push_back(6.3);
	TableauTest.push_back(3.3);
	TableauTest.push_back(6.0);
	TableauTest.push_back(2.5);
	
	C->constructionSortie("FichTest.txt");

	for (int i = 0; i < 4; i++){
		
		CPPUNIT_ASSERT( abs(TableauTest[i] - C->getNeurone(i).getSortie()) < 0.01);
	}
	// Deuxième façon de faire je sais pas laquelle est mieux !!!
	/*
	Matrice NeuroneVerif ; 
	C1->constructionSortie();
	NeuroneVerif = new Matrice (1,4);
	NeuroneVerif = C1->recupSortiesNeurones();
	for (int i = 0; i < 4; i++){
		CPPUNIT_ASSERT( fabs(TableauTest[i] - NeuroneVerif.getCoefMatrice(0,i)) < 0.00001);
	}

	*/
}


//--------------------------------------------------------------------------------------------------

//------------------------------------------LE MAIN-------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( TestCoucheEntrees );
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
//--------------------------------------------------------------------------------------------------
