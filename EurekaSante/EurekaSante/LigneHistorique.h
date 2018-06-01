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
	const Utilisateur& monutilisateur;
	const Analyse& analyse;
public:
	LigneHistorique(const Utilisateur& monutilisateur, const Analyse& analyse)
	: monutilisateur(monutilisateur), analyse(analyse)
	{
		time_t t;
		// date = localtime(&t);
	}
	~LigneHistorique() = default;
	vector<string> toString();
};

#endif // LIGNEHISTORIQUE_H