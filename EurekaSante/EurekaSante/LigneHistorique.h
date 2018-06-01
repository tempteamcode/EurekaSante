#ifndef LIGNEHISTORIQUE_H
#define LIGNEHISTORIQUE_H
#include <time.h>
#include <ctime>
#include "Utilisateur.h"
#include "Analyse.h" 
class LigneHistorique
{

protected:
	string date;
	Utilisateur* monutilisateur;
	//Analyse& a;
public:
	LigneHistorique(Utilisateur* utilisateur) {
		time_t t;
		time(&t);
		tm date;
		localtime_s(&date, &t);
		char yyyymmdd[16];
		std::strftime(yyyymmdd, sizeof(yyyymmdd), "%Y-%m-%d", &date);
		this->date = yyyymmdd;
		//date = dateJ;
		monutilisateur = utilisateur;
		//a = analyse;
	}
	~LigneHistorique() = default;
	vector<string>* toString();
};

#endif // LIGNEHISTORIQUE_H