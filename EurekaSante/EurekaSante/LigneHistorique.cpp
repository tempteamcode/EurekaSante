
#include "LigneHistorique.h"
#include "Utilisateur.h"

LigneHistorique::LigneHistorique(const Utilisateur& utilisateur, const Analyse& analyse)
: utilisateur(utilisateur), analyse(analyse)
{
	time_t t;
	time(&t);
	tm date;
	localtime_s(&date, &t);
	char yyyymmdd[16];
	std::strftime(yyyymmdd, sizeof(yyyymmdd), "%Y-%m-%d", &date);
	this->date = yyyymmdd;
}

vector<string> LigneHistorique::toString() {
	vector<string> contenu;

	contenu.push_back("L'utilisateur " + utilisateur.Nom() + " a fait les analyses ci-dessous à " + date + " :");
	vector<mapMaladie> map = analyse.Resultats();
	for (uint i = 0; i < map.size(); i++) {
		contenu.push_back("Pour l'empreinte " + to_string(i) + " de cette analyse, le résultat est ci-dessous : ");
		for (auto it = map[i].cbegin(); it != map[i].cend(); ++it) {
			contenu.push_back(it->first->Nom() + " : "+to_string(it->second * 100.0)+"%");
		}
		contenu.push_back("");
	}

	return contenu;
}
