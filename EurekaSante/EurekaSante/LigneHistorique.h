#ifndef LIGNEHISTORIQUE_H
#define LIGNEHISTORIQUE_H

#include "Analyse.h" 
class Utilisateur;


class LigneHistorique
{
protected:
	string date;
	const Utilisateur& utilisateur;
	const Analyse& analyse;
	
public:
	LigneHistorique(const Utilisateur& utilisateur, const Analyse& analyse);
	~LigneHistorique() = default;
	vector<string> toString();
};

#endif // LIGNEHISTORIQUE_H