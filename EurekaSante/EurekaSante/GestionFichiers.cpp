
#include <fstream>
using std::fstream;
using std::ios;

#include "GestionFichiers.h"
typedef unsigned int uint;


#include "Empreinte.h"

#include <map>
using std::map;

#include <sstream>
using std::istringstream;


const char CSV_SEPARATOR = ';';


/*
AttributeName;AttributeType
NoID;ID
A1;string
A2;double
A3;double
A4;double
*/


void AfficherAttributs(const Attributs& attributs) {
	for (uint index = 0; index < attributs.indice.size(); index++) {
		cout << '#' << index << " : " << '(' << attributs.type[index] << ") " << attributs.nom[index] << endl;
	}
}


bool FichierChargerAttributs(const string& path, Attributs& attributs)
{
	fstream fichier;
	fichier.open(path, ios::in);
	if (!fichier.is_open()) return false;

	string data;
	getline(fichier, data);
	getline(fichier, data);

	for (;;)
	{
		getline(fichier, data);
		istringstream line(data);
		if (fichier.fail()) break;

		string nom;
		string type;
		getline(line, nom, CSV_SEPARATOR);
		getline(line, type);
		
		attributs.nom.push_back(nom);
		attributs.type.push_back(type);
		attributs.indice.push_back(uint(attributs.indice.size()));
	}
	
	return true;
}


bool FichierChargerEmpreintes(const string& path, vector<Empreinte>& empreintes)
{
	fstream fichier;
	fichier.open(path, ios::in);
	if (!fichier.is_open()) return false;
	
	string data;
	for(;;)
	{
		getline(fichier, data);
		istringstream line(data);

		string nom;
		string type;
		getline(line, nom, CSV_SEPARATOR);
		getline(line, type);


	}
}



bool FichierSauverEmpreintes(const string& path, const vector<Empreinte>& empreintes, bool overwrite)
{
	fstream fichier;
	fichier.open(path, ios::out | (overwrite ? ios::trunc : ios::ate));
	// ios::trunc efface le contenu précédent
	// ios::ate ajoute du contenu à la fin
	if (!fichier.is_open()) return false;
	
	//[...]
	return false;
}
