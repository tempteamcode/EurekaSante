
#include <fstream>
using std::fstream;
using std::ios;

#include <map>
using std::map;

#include <sstream>
using std::istringstream;


#include "Reglages.h"
#include "Attributs.h"
#include "Empreinte.h"
#include "GestionFichiers.h"


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
		
		attributs.Ajouter(nom, type);
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
