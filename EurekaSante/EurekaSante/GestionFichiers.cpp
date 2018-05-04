
#include <fstream>
using std::fstream;
using std::ios;

#include "GestionFichiers.h"
typedef unsigned int uint;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Empreintes.h"

bool FichierChargerEmpreintes(const string& path, vector<Empreintes>& empreintes)
{
	fstream fichier;
	fichier.open(path, ios::in);
	if (!fichier.is_open()) return false;


}

bool FichierSauverEmpreintes(const string& path, const vector<Empreintes>& empreintes, bool overwrite)
{
	fstream fichier;
	fichier.open(path, ios::out | (overwrite ? ios::trunc : ios::ate));
	// ios::trunc efface le contenu précédent
	// ios::ate ajoute du contenu à la fin
	if (!fichier.is_open()) return false;
	
}
