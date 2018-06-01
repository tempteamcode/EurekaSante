#include "LigneHistorique.h"

vector<string>* LigneHistorique::toString() {
	vector<string>* contenu = new vector<string>;
	contenu->push_back("L'utilisteur " + monutilisateur->GetNom() + " a fait les analyses ci-dessous à " + date + " :");
	
	return contenu;
}