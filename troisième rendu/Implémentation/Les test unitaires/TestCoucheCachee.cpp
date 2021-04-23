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
    CPPUNIT_TEST_SUITE(TestCouche); /*!< La suite des test que nous allons effectuer  */
	CPPUNIT_TEST(testPreActivation); /*!< Le test qui va vérifier la fonction de PreActivation  */
    CPPUNIT_TEST(testFoncActivation); /*!< Le test qui va vérifier la fonction d'Activation  */
	CPPUNIT_TEST(testDerivFoncActivation); /*!< Le test qui va vérifier la fonction la dérivée de la fonction d'activation  */
    CPPUNIT_TEST_SUITE_END();

public:
// Pour initialiser les variables et allouer de la mémoire
	void setUp(void);
// Pour supprimer une variable et désallouer la mémoire
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
	void testActivation(void);
	/*!
     *  \fn testDerivFoncActivation(void)
     *  \brief  test que la derivee de la fonction d'activation renvoie bien la bonne valeur
    */
	void testDerivFoncActivation(void);
private:
	CoucheCachee *C1, *C2;

}

// Les test----------------------------------------------------------------------------------
void TestCoucheCachee::setUp(void)
{
	// Pour faire ce test on a besoin d'un objet couEntrée avec lee tableau de neurones initialisés avec 
	//les valeurs données dans le rapport
	// Comment faire ça ?
	// Dans les tests peut-on accéder à des attributs private
	// Est ce que je peux créer un objet coucheEntrée et l'initialiser comme je veux 
	// Notre constructeur coucheEntrée initialise le tableau de neurones avec un fichier comment faire ?  

	// Dans coucheCachee.hpp j'ai un attribut Matrice* LiaisonsEntrees; est ce que je peux faire 
	// C1->LiaisonEntrees.setCoefMatrice(i,j,coef)
    // un contructeur avec que des zéro pour la matrice de laisiason et que des zéros pour les biais (la couche verte)
	C1 = new CoucheCachee (2, 4); // dans l'exemple qu'on a pris la couche d'entrée contient 4 neurones
	C2 = new CoucheCachee (2, 4); // idem
}
void TestCoucheCachee::tearDown(void)
{
	delete C1;
	delete C2;
}
// 

void TestCoucheCachee::testpreActivation(void) 
{
   Matrice Somme; // à tester 
   Somme = C1->preActivation();

   CPPUNIT_ASSERT( fabs(6.87 - C1->getNeurone(1).getSortie()) < 0.00001 &&  fabs(8.98 - C1->getNeurone(2).getSortie()) < 0.00001) ;
}

void TestCoucheCachee::testactivation(void)
{
	C1->foncActivation(Somme);
	C2->getNeurone(1).setSortie(0.001); // getNeurone(1) nous donne le premier neurone de la couche et 
	                                    //setSortie(double) nous permet de lui attribuer une valeur
	C2->getNeurone(2).setSortie(0.0001258869);

   CPPUNIT_ASSERT( fabs(C2->getNeurone(1).getSortie() -  C1->getNeurone(1).getSortie()) < 0.00001 ); 
   CPPUNIT_ASSERT( fabs( C2->getNeurone(2).getSortie() - C1->getNeurone(2).getSortie() ) < O.00OO1 ); 
}

void TestCoucheCachee::testactivation(void)
{
	CPPUNIT_ASSERT( (0.0010363235505306467 - derivFoncActivation(6.87)) < 0.00001 );
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