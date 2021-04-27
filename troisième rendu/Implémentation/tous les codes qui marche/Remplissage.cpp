void Reseau::Remplissage(std::vector<CoucheEntrees> x, std::vector<CoucheSorties> y, std::string nomFic)
{
    std::ifstream fichier( nomFic ); //Ouverture en lecture

    if ( fichier ) 
    { 
        std::string ligne; // variable contenant chaque ligne lue 
        double buffer;

		std::getline( fichier, ligne ); //Recupere la 1ere ligne contenant differentes infos
  		std::vector<std::string> result; 
  		std::istringstream iss(ligne); // créer un flux a partir de la chaîne donnee
  		std::string str;
  		while (std::getline(iss, str, ' ')) //Le separateur est un espace
    		result.push_back(str); //On stock les elements de chaque ligne dans un vector result

		//Premiere ligne : nbLignes, nbColonnes, et nbNeurones d'entree
		int nbLignes = result[0];
		int nbColonnes = result[1];
        int nbNeurones = result[2];
		
		int ind = 0; //indice des individus

        while ( std::getline( fichier, ligne ) && (i<nbLignes) 
        { 
			result.clear();
  			iss(ligne); //// créer un flux a partir de la chaîne donnee
  			while (std::getline(iss, str, ' '))
    			result.push_back(str);

			//Set les entrees 
			for(int i=0; i<nbColonnes-2; i++)
			{
				buffer = std::stod(result[i]);
            	x[ind].getNeurone(i).setSortie(buffer); //On set la sortie du neurone
			}
			//Set les sorties
			for (int i = 0; i < y[ind].getNbNeurones(); i++)
			{
				buffer = std::stod(result[nbColonnes-1]);
				if (buffer==i)
					y[ind].getNeurone(i).setSortie(1);
				else
					y[ind].getNeurone(i).setSortie(0);
			}
			ind++;
        } 
    } 	
}
