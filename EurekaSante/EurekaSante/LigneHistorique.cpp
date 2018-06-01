#include "LigneHistorique.h"

#include "Utilisateur.h"

vector<string>* LigneHistorique::toString() {
	vector<string>* contenu = new vector<string>;
	contenu->push_back("L'utilisteur " + monutilisateur->GetNom() + " a fait les analyses ci-dessous à " + date + " :");
	vector<mapMaladie> map = a->Resultats();
	for (int i = 0; i < map.size(); i++) {
		contenu->push_back("Pour l'empreinte " + to_string(i) + " de cette analyse, le résultat est ci-dessous : ");
		for (auto it = map[i].cbegin(); it != map[i].cend(); ++it) {
			contenu->push_back(it->first->Nom() + " : "+to_string(it->second * 100.0)+"%");
		}
		contenu->push_back("");
	}
	return contenu;
}