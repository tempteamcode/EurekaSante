
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
	getline(fichier, data); // AttributeName;AttributeType
	getline(fichier, data); // NoID;ID
	
	for (;;)
	{
		getline(fichier, data);
		if (fichier.fail()) break;
		istringstream line(data);
		
		string nom;
		string type;
		getline(line, nom, CSV_SEPARATOR);
		getline(line, type);
		
		attributs.Ajouter(nom, type);
	}
	
	return true;
}


/*
NoID;A1;A2;A3;A4;Disease
0;AA;152.522201822802;147.966461981174;132.340194347595;M1
1;AA;18.7131577189311;23.0351482966652;173.707814305872;M2
*/


bool FichierChargerEmpreintes(const string& path, const Attributs& attributs, vector<Empreinte>& empreintes)
{
	fstream fichier;
	fichier.open(path, ios::in);
	if (!fichier.is_open()) return false;
	
	string data;
	getline(fichier, data); // NoID;A1;A2;A3;A4;Disease
	bool hasmaladie = (data.find(";Disease") != string::npos);
	
	map<string, vector<Empreinte*>> liens;
	vector<Maladie> maladies;
	
	for(;;)
	{
		getline(fichier, data);
		if (fichier.fail()) break;
		istringstream line(data);
		
		getline(line, data, CSV_SEPARATOR);
		int NoID = stoi(data);
		Empreinte empreinte(NoID);
		
		for (int i = 1; i < attributs.Compte(); i++) {
			string value;
			getline(line, value, CSV_SEPARATOR);

			if (attributs.IsDouble(i)) {
				double valued = stod(value);
				empreinte.AjouterDouble(valued);
			}
			else
			{
				empreinte.AjouterString(value);
			}
		}

		empreintes.push_back(empreinte);

		if (hasmaladie) {
			string nommaladie;
			getline(line, nommaladie);
			liens[nommaladie].push_back(&empreinte);
		}
	}
	
	for (int i = 0; i < empreintes.size(); i++) {
		
	}
}

bool FichierSauverEmpreintes(const string& path, const Attributs& attributs, const vector<Empreinte>& empreintes, bool overwrite)
{
	fstream fichier;
	fichier.open(path, ios::out | (overwrite ? ios::trunc : ios::ate));
	// ios::trunc efface le contenu précédent
	// ios::ate ajoute du contenu à la fin
	if (!fichier.is_open()) return false;
	
	//[...]
	return false;
}
