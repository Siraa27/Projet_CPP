all : final

final : main.o Matrice.o Couche.o CoucheEntree.o CoucheSorties.o CoucheCachee.o Neurone.o Reseau.o InterfaceManuelle.o InterfaceFichier.o Interface.o ReseauForwarded.o
#+LINKER

main.o : main.cpp
	g++ -c main.cpp
	
Matrice.o : Matrice.hpp Matrice.cpp
	g++ -c Matrice.cpp
	
Couche.o : Couche.hpp Couche.cpp
	g++ -c Couche.cpp
	
CoucheEntrees.o : CoucheEntrees.hpp CoucheEntrees.cpp
	g++ -c CoucheEntrees.cpp

CoucheSorties.o : CoucheSorties.hpp CoucheSorties.cpp
	g++ -c CoucheSorties.cpp
	
CoucheCachees.o : CoucheCachees.hpp CoucheCachees.cpp
	g++ -c CoucheCachees.cpp
	
Neurone.o : Neurone.hpp Neurone.cpp
	g++ -c Neurone.cpp
	
Reseau.o : Reseau.hpp Reseau.cpp
	g++ -c Reseau.cpp
	
InterfaceManuelle.o : InterfaceManuelle.hpp InterfaceManuelle.cpp
	g++ -c InterfaceManuelle.cpp
	
InterfaceFichier.o : InterfaceFichier.hpp InterfaceFichier.cpp
	g++ -c InterfaceFichier.cpp
	
Interface.o : Interface.hpp Interface.cpp
	g++ -c Interface.cpp

ReseauForwarded.o : ReseauForwarded.hpp ReseauForwarded.cpp
	g++ -c ReseauForwarded.cpp	
	

TestMatrice: Matrice.o TestMatrice.o
	g++ -o TestMatrice Matrice.cpp TestMatrice.cpp -lcppunit

TestCoucheEntrees: CoucheEntrees.o TestCoucheEntrees.o
	g++ -o TestCoucheEntrees CoucheEntrees.cpp TestCoucheEntrees.cpp -lcppunit

TestCoucheSorties: CoucheSorties.o TestCoucheSorties.o
	g++ -o TestCoucheSorties CoucheSorties.cpp TestCoucheSorties.cpp -lcppunit
	
TestCoucheCachees: CoucheCachees.o TestCoucheCachees.o
	g++ -o TestCoucheCachees CoucheCachees.cpp TestCoucheCachees.cpp -lcppunit
	
TestReseau : Reseau.o TestReseau.o
	g++ -o TestReseau Reseau.cpp TestReseau.cpp -lcppunit
	
TestInterfaceFichier : InterfaceFichier.o TestInterfaceFichier.o
	g++ -o TestInterfaceFichier InterfaceFichier.cpp TestInterfaceFichier.cpp -lcppunit

TestMatrice.o:TestMatrice.cpp
	g++ -c TestMatrice.cpp
	
TestCoucheEntrees.o:TestCoucheEntrees.cpp
	g++ -c TestCoucheEntrees.cpp
	
TestCoucheSorties.o:TestCoucheSorties.cpp
	g++ -c TestCoucheSorties.cpp

TestCoucheCachees.o:TestCoucheCachees.cpp
	g++ -c TestCoucheCachees.cpp
	
TestReseau.o:TestReseau.cpp
	g++ -c TestReseau.cpp
	
TestInterfaceFichier.o:TestInterfaceFichier.cpp
	g++ -c TestInterfaceFichier.cpp
	
clean:
rm -fr *.o

mrproper:
rm -fr final
