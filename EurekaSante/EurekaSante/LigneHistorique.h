#ifndef LIGNEHISTORIQUE_H
#define LIGNEHISTORIQUE_H
#include <time.h>
#include "Utilisateur.h"
#include "Analyse.h" 
typedef tm* dateJ;
class LigneHistorique
{

protected:
	dateJ date;
	Utilisateur& monutilisateur;
	Analyse& a;
public:
	LigneHistorique(const Utilisateur& monutilisateur,const Analyse& analyse) {
		time_t t;
		date = localtime(&t);
		this->monutilisateur = monutilisateur;
		a = analyse;
	}
	~LigneHistorique() = default;
	vector<string>* toString();
};

#endif // LIGNEHISTORIQUE_H