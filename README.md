# Projet_C++


5.2.2 Les tests de la classe Réseau

testConstructeurReseau :

Pour créer un réseau, les choix sont multiples. Comme on l'a vu plus haut dans la partie InterfaceUtilisateur, c'est par le biais d'un fichier au bon format que l'utilisateur peut obtenir un type de réseau particulier. Réseau(Liste listeParametres) est le constructeur de la classe Reseau et prend en paramètres la liste listeParametres qui contient :

• Le premier paramètre du fichier sera le type de réseau. Dans notre projet, seul le réseau forwarded sera fonctionel (représenté par l'entier 1). 

• Le second paramètre du fichier est le cas d'utilisation du réseau (1:classification, 2:prédiction, 3:identification des objets et 4: reconnaissance d'image). Rappelons que seule le choix 1 et potentiellement 2 seront implémentés. 

• Le troisième paramètre compte le nombre de couches cachées, nbCouche. 

• Le quatrième paramètre compte le nombre de neurones par couche cachée (classe CoucheCachée). 

• Le cinquième paramètre du fichier est 0 ou x un entier positif non nul :     - 0 si l'initialisation de la matrice de poids initiaux est faite aléatoirement.      - x si l'utilisateur choisit d'initaliser tous les poids à x. 

On prend alors 2 exemples :Un réseau R1 de type Forwarded avec 3 couches cachées, 2 neurones par couches et des poids initialisés aléatoirement.Un réseau R2 de type Forwarded avec 1 couches cachées, 4 neurones par couches et des poids initialisés à 0.5.Remarque : Il est impossible de calculer l'égalité entre 2 flottants en machine. On utilise pour parer cela : la norme de la différence entre la valeur attendue et la valeur recupérée dans le fichier pour obtenir le booléen qui indique si le test est réussi ou non.C'est cette technique que l'on utilise ici pour le test concernant les poids initialisés à 0.5.

testAjouterCouche

testErreur

calcGradC

testApprentissage

testBackPropagation

Resultat:

