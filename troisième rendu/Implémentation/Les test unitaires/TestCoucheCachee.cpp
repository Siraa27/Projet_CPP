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


#include "Lib/Couche.hpp"
#include "Lib/CoucheCachee.hpp"
#include "Lib/Matrice.hpp"

///opt/homebrew/opt/cppunit/include/ /// ne me supprimez pas pleaaase 

using namespace CppUnit;
using namespace std;


/*!
 * \file TestCoucheCachee.cpp
 * \brief C'est une classe qui permet de vérifier que les méthodes utilisées dans CoucheCachee renvoie bien le résultat attendu. 
 * \author Groupe projet A1
 * \version 0.1
 */
/*! \namespace Les_tests_unitaires
 */


   /*! \class TestCoucheCachee
   * \brief Classe pour les tests 
   *
   */

// La classe qui va faire le test 
class TestCoucheCachee : public CppUnit::TestFixture{
    // Pour pouvoir tourner plusieurs tests aux même temps
    CPPUNIT_TEST_SUITE(TestCoucheCachee); /*!< La suite des test que nous allons effectuer  */
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
	CoucheCachee *C1, *C2;
	Couche *C0;

};

// Les test----------------------------------------------------------------------------------
void TestCoucheCachee::setUp(void)
{
	C0 = new Couche (4);
	C1 = new CoucheCachee (2, 4); // dans l'exemple qu'on a pris la couche d'entrée contient 4 neurones
	C2 = new CoucheCachee (2, 4); // idem
}
void TestCoucheCachee::tearDown(void)
{
	delete C1;
	delete C2;
	delete C0;
}
// 

void TestCoucheCachee::testPreActivation(void) 
{
	// Ma matrice liaison
    // 0.1 | 0.3 | 0.5 | 0.7 |
    // 0.2 | 0.4 | 0.6 | 0.8 |
	// Remplissage de la matrice liaison 
	int k = 1;
    for (int j = 0; j < 4; j++ ){ // Je fixe d'abords la colonne c'est plus simple pour l'incrementation de k 
	   for (int i = 0; i < 2 ; i++){
		   C1->getLiaisonEntrees().setCoefMatrice( i, j, k * 0.1 );
		   k = k + 1;
	    }
    }

    // Ma matrice biais est égale à 
    // 0.5 | 0.8 |
	// Remplissage de la matrice biais
	C1->getBiais().setCoefMatrice( 0, 0, 0.5 );
	C1->getBiais().setCoefMatrice( 0, 1, 0.8 );


	// Création des matrices pour les tests
   Matrice* Resultat = new Matrice (1,2); 
   Matrice* TestResultat = new Matrice (1,2); 

	// Ma matrice TestResultat est égale à :
	// 6.87 | 8.98 |
	// Remplissage de la matrice de TestResultat avec les valeurs souhaitees
   TestResultat->setCoefMatrice( 0, 0, 6.87 );
   TestResultat->setCoefMatrice( 0, 1, 8.98 );

	// Création du Bouchon 
	// Le tableau de neurone de La couche precedente est égale à : 
	// 6.3 | 3.3 | 6.0 | 2.5 |
	C0->getNeurone(0).setSortie(6.3);
	C0->getNeurone(1).setSortie(3.3);
	C0->getNeurone(2).setSortie(6.0);
	C0->getNeurone(3).setSortie(2.5);
	// preActivation renvoie une (Matrice) donc elle va cracher les valeurs dans la matrice Resultat 
   Resultat = C1->preActivation(*C0);

   CPPUNIT_ASSERT( fabs( TestResultat->getCoefMatrice(0,0) - Resultat->getCoefMatrice(0,0) ) < 0.00001 &&  fabs( TestResultat->getCoefMatrice(0,1) - Resultat->getCoefMatrice(0,1) ) < 0.00001 ) ;
};

void TestCoucheCachee::testFoncActivation(void)
{	
	// Comme la matrice résultat etait variable local au test précédent on la rerempli !!
    // La matrice résultat trouvé à l'aide de la methode preactivation est égale à :
	// 6.87 | 8.98 |
	Matrice* SommePond = new Matrice (1,2); 	
	SommePond->setCoefMatrice( 0, 0, 6.87 );
    SommePond->setCoefMatrice( 0, 1, 8.98 );
	// On veut que le tableau de neurone dans la couche C1 soit égale à :
	// 0.001 | 0.0001258869


	//{
		//j'ai deux idée pour faire les tests je sais pas laquelle est mieux ou laquelle marche 

	/*Matrice NeuroneTest = new Matrice (1,2); 	
	NeuroneTest.setCoefMatrice( 0, 0, 0.001);
    NeuroneTest.setCoefMatrice( 0, 1, 0.0001258869);
	CPPUNIT_ASSERT( fabs(NeuroneTest.getCoefMatrice(0,0) -  C1->getNeurone(1).getSortie()) < 0.00001 && fabs( NeuroneTest.getCoefMatrice(0,1)- C1->getNeurone(2).getSortie() ) < O.00OO1); 
	*/
	
	C2->getNeurone(0).setSortie(0.001); // getNeurone(1) nous donne le premier neurone de la couche et 
	                                    //setSortie(double) nous permet de lui attribuer une valeur
	C2->getNeurone(1).setSortie(0.0001258869); // C2->Couche::getNeurone(2).setSortie(0.0001258869); ???s

   C1->foncActivation(SommePond);	
   CPPUNIT_ASSERT( fabs(C2->getNeurone(0).getSortie() -  C1->getNeurone(0).getSortie()) < 0.00001 && fabs( C2->getNeurone(1).getSortie() - C1->getNeurone(1).getSortie() ) < 0.00001); 
	//}


};

void TestCoucheCachee::testDerivFoncActivation(void)
{
	CPPUNIT_ASSERT( (0.0010363235505306467 - C1->derivFoncActivation(6.87)) < 0.00001 );
};
//--------------------------------------------------------------------------------------------------

//------------------------------------------LE MAIN-------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestCoucheCachee );
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
//--------------------------------------------------------------------------------------------------