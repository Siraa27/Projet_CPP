
#include <iostream>
#include <string>
#include <list>
#include <cmath>

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
#include "Matrice.hpp"
#include "Neurone.hpp"

using namespace CppUnit;
using namespace std;

/*!
 * \file TestCoucheSortie.cpp
 * \brief C'est une classe qui permet de vérifier que les méthodes utilisées dans CoucheSortie renvoie bien le résultat attendu. 
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_tests_unitaires
 */


   /*! \class TestCoucheSortie
   * \brief Classe pour les tests 
   *
   */


// La classe qui va faire le test 
class TestCoucheSorties : public CppUnit::TestFixture{
    // Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestCoucheSorties); /*!< La suite des test que nous allons effectuer  */
	CPPUNIT_TEST(testPreActivation); /*!< Le test qui va vérifier la méthode de PreActivation  */
    CPPUNIT_TEST(testFoncActivation); /*!< Le test qui va vérifier la méthode d'Activation  */
	CPPUNIT_TEST(testDerivFoncActivation); /*!< Le test qui va vérifier la méthode la dérivée de la méthode d'activation  */
    CPPUNIT_TEST_SUITE_END();

public:
    /*!
     *  \fn setUp(void)
     *  \brief  Pour initialiser les variables et allouer de la mémoire
    */
	void setUp(void);
	/*!
     *  \fn tearDown(void)
     *  \brief  Pour supprimer une variable et désallouer la mémoire
    */
	void tearDown(void);
protected:
    /*!
     *  \fn testPreActivation(void)
     *  \brief qui teste que la fonction de pré activation renvoie bien la somme pondérée des entrées
    */
	void testPreActivation(void);
	/*!
     *  \fn testActivation(void)
     *  \brief La fonction d'activation effectue des changement directement sur le tableau de neurones de la couche donc ce test
	 * \brief  va vérifier que le paramètre a bien était modifié 
    */
	void testFoncActivation(void);
	/*!
     *  \fn testDerivFoncActivation(void)
     *  \brief  test que la derivee de la fonction d'activation renvoie bien la bonne valeur
    */
	void testDerivFoncActivation(void);
private:
	CoucheSorties   *C1, *C2;
	Couche *C0 ;
};

//------------------------------------------LES TESTS---------------------------------------------------
//------------------------------------------------------------------------------------------------------


void TestCoucheSorties::setUp(void)
{
// ça me parait bizarre de construire une coucheSortie vaec un tableau de neurone qui a comme valeur ceux  d'une coucheCachee
	C1 = new CoucheSorties(3,2);
	C2 = new CoucheSorties(3,2);
	C0 = new Couche(2); //Couche (const int nbN)
}
void TestCoucheSorties::tearDown(void)
{
	delete C0;
	delete C1;
	delete C2;
}

void TestCoucheSorties::testPreActivation(void)
{
	// Ma matrice liaison
    // 0.3 | 0.2 | 
    // 0.5 | 0.4 |
	// 0.7 | 0.6 |
	// Remplissage de la matrice liaison 
	// Ligne I
	C1->getLiaisonEntrees().setCoefMatrice( 0, 0, 0.3 );
	C1->getLiaisonEntrees().setCoefMatrice( 0, 1, 0.2 );
	// Ligne II
	C1->getLiaisonEntrees().setCoefMatrice( 1, 0, 0.5 );
	C1->getLiaisonEntrees().setCoefMatrice( 1, 1, 0.4 );
	// Ligne III
	C1->getLiaisonEntrees().setCoefMatrice( 2, 0, 0.7);
	C1->getLiaisonEntrees().setCoefMatrice( 2, 1, 0.6 );

	// Ma matrice biais est égale à 
    // 0 |
	// 0 |
	// 0 |
	// Remplissage de la matrice biais
	C1->getBiais().setCoefMatrice( 0, 0, 0 );
	C1->getBiais().setCoefMatrice( 1, 0, 0 );
	C1->getBiais().setCoefMatrice( 2, 0, 0 );

	
	// Création des matrices pour les tests
   Matrice* Resultat = new Matrice (3,1); 
   Matrice* TestResultat = new Matrice (3,1);

	// Ma matrice TestResultat est égale à :
	// 0.00032517738 |
	// 0.000550354376|
	// 0.00077553214 |
	// Remplissage de la matrice de TestResultat avec les valeurs souhaitees
   TestResultat->setCoefMatrice( 0, 0, 0.00032517738);
   TestResultat->setCoefMatrice( 1, 0, 0.000550354376); 
   TestResultat->setCoefMatrice( 2, 0, 0.00077553214); 

	// Création du Bouchon 
	// Le tableau de neurone de La couche precedente est égale à : 
	// 0.001 |
	// 0.0001258869 |
	C0->modifNeurone(0,0.001);
	C0->modifNeurone(1,0.0001258869);

	*Resultat = C1->preActivation(*C0);

	for (int i = 0 ; i < 3; i++){
		CPPUNIT_ASSERT( fabs(TestResultat->getCoefMatrice(i,0) - Resultat->getCoefMatrice(i,0)) < 0.01 ) ;
	};
    
}


void TestCoucheSorties::testFoncActivation(void)
{
	// Comme la matrice résultat etait variable local au test précédent on la rerempli !!
    // La matrice résultat trouvé à l'aide de la methode preactivation est égale à :
	// 0.00032517738 |
	// 0.000550354376|
	// 0.00077553214 |
	Matrice* SommePond = new Matrice (3,1); 	
    SommePond->setCoefMatrice( 0, 0, 0.00032517738);
    SommePond->setCoefMatrice( 1, 0, 0.000550354376); 
    SommePond->setCoefMatrice( 2, 0, 0.00077553214); 

	// On veut que le tableau de neurone dans la couche C1 soit égale à :
	// 0,499918705655716 |
	// 0,499862411409473 | 
	// 0,499806116974718 |

	
		//{
		//j'ai deux idée pour faire les tests je sais pas laquelle est mieux ou laquelle marche 

	Matrice* NeuroneTest = new Matrice (3,1); 
	NeuroneTest->setCoefMatrice( 0, 0, 0.499918705655716);
    NeuroneTest->setCoefMatrice( 1, 0, 0.499862411409473);
    NeuroneTest->setCoefMatrice( 2, 0, 0.499806116974718);
    	
    C1->foncActivation(*SommePond);
	for (int i = 0; i < 3 ; i++){
		CPPUNIT_ASSERT ( fabs(NeuroneTest->getCoefMatrice(i,0) - C1->getNeurone(i).getSortie() )< 0.01 ) ; 
	}
	/*CPPUNIT_ASSERT( abs( NeuroneTest->getCoefMatrice(0,0) -C1->getNeurone(0).getSortie()) < 0.00001 );
	CPPUNIT_ASSERT( abs( NeuroneTest->getCoefMatrice(0,1)- C1->getNeurone(1).getSortie()) < 0.00001); */

	
	/*
	C2->getNeurone(0).setSortie(1); // getNeurone(1) nous donne le premier neurone de la couche et 
	                                    //setSortie(double) nous permet de lui attribuer une valeur
	C2->getNeurone(1).setSortie(2); // C2->Couche::getNeurone(2).setSortie(0.0001258869); ???s
	C2->getNeurone(2).setSortie(3); 

	C1->foncActivation(*SommePond);
	for (int i = 0; i < 3 ; i++){
		CPPUNIT_ASSERT ( abs(C2->getNeurone(i).getSortie() - C1->getNeurone(i).getSortie() )< 0.00001 ) ; 
	}*/
    
        

}

void TestCoucheSorties::testDerivFoncActivation(void)
{
	CPPUNIT_ASSERT( (0.0010363235505306467 - C1->derivFoncActivation(6.87)) < 0.00001 );
};


//--------------------------------------------------------------------------------------------------

//------------------------------------------LE MAIN-------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestCoucheSorties );
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
//--------------------------------------------------------------------------------------------------