CC = g++
OPT = -c 

OBJ = Main.o Matrice.o Couche.o CoucheEntrees.o CoucheSorties.o CoucheCachee.o Neurone.o Reseau.o InterfaceManuelle.o InterfaceFichier.o Interface.o 
#*.o

# Création des executables
# editon des liens ( on rassemble les objets) 

Prog: $(OBJ)
	$(CC) $(OBJ) -o Prog

TestMatrice: Matrice.o TestMatrice.o
	$(CC) -o TestMatrice Matrice.cpp TestMatrice.cpp -lcppunit

TestCoucheEntrees: CoucheEntrees.o TestCoucheEntrees.o Couche.o Matrice.o Neurone.o
	$(CC) -o TestCoucheEntrees CoucheEntrees.cpp TestCoucheEntrees.cpp -lcppunit

TestCoucheSorties: CoucheSorties.o TestCoucheSorties.o Couche.o Matrice.o Neurone.o
	$(CC) -o TestCoucheSorties CoucheSorties.cpp TestCoucheSorties.cpp -lcppunit
	
TestCoucheCachees: CoucheCachees.o TestCoucheCachees.o Couche.o Matrice.o Neurone.o
	$(CC) -o TestCoucheCachees CoucheCachees.cpp TestCoucheCachees.cpp -lcppunit
	
TestReseau : Reseau.o TestReseau.o
	$(CC) -o TestReseau Reseau.cpp TestReseau.cpp -lcppunit
	
TestInterfaceFichier : InterfaceFichier.o TestInterfaceFichier.o
	$(CC) -o TestInterfaceFichier InterfaceFichier.cpp TestInterfaceFichier.cpp -lcppunit


# Compilation des objets des programmes principales 
Main.o : Main.cpp *.hpp
	$(CC) $(OPT) Main.cpp

Matrice.o : Matrice.cpp  Matrice.hpp 
	$(CC) $(OPT) Matrice.cpp 
	
Couche.o : Couche.cpp Couche.hpp Matrice.hpp Neurone.hpp
	$(CC) $(OPT) Couche.cpp
	
CoucheEntrees.o : CoucheEntrees.cpp CoucheEntrees.hpp Couche.hpp Neurone.hpp 
	$(CC) $(OPT) CoucheEntrees.cpp

CoucheSorties.o : CoucheSorties.cpp CoucheSorties.hpp Couche.hpp Matrice.hpp Neurone.hpp
	$(CC) $(OPT) CoucheSorties.cpp
	
CoucheCachees.o : CoucheCachee.cpp CoucheCachee.hpp Couche.hpp Couche.hpp Neurone.hpp Matrice.hpp
	$(CC) $(OPT) CoucheCachees.cpp
	
Neurone.o : Neurone.cpp Neurone.hpp 
	$(CC) $(OPT) Neurone.cpp
	
Reseau.o : Reseau.cpp *.hpp
	$(CC) $(OPT) Reseau.cpp
	
InterfaceManuelle.o : InterfaceManuelle.cpp InterfaceManuelle.hpp Interface.hpp
	$(CC) $(OPT) InterfaceManuelle.cpp
	
InterfaceFichier.o : InterfaceFichier.cpp InterfaceFichier.hpp Interface.hpp
	$(CC) $(OPT) InterfaceFichier.cpp
	
Interface.o : Interface.cpp Interface.hpp
	$(CC) $(OPT) Interface.cpp

ReseauForwarded.o : ReseauForwarded.cpp ReseauForwarded.hpp Reseau.hpp
	$(CC) $(OPT) ReseauForwarded.cpp
	
	
# Compilation des objets pour les programmes de test 
TestMatrice.o:TestMatrice.cpp
	$(CC) $(OPT) TestMatrice.cpp
	
TestCoucheEntrees.o:TestCoucheEntrees.cpp
	$(CC) $(OPT) TestCoucheEntrees.cpp
	
TestCoucheSorties.o:TestCoucheSorties.cpp
	$(CC) $(OPT) TestCoucheSorties.cpp

TestCoucheCachees.o:TestCoucheCachee.cpp
	$(CC) $(OPT) TestCoucheCachees.cpp
	
TestReseau.o:TestReseau.cpp
	$(CC) $(OPT) TestReseau.cpp
	
TestInterfaceFichier.o:TestInterfaceFichier.cpp 
	$(CC) $(OPT) TestInterfaceFichier.cpp
	
clean:
	rm *.o *.gch TestInterfaceFichier TestReseau TestMatrice TestCoucheEntrees TestCoucheSorties TestCoucheCachees final


