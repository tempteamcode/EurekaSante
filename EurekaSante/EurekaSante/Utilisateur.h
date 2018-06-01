#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "Reglages.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "GestionFichiers.h"
#include <iostream>
#include "Analyse.h"
#include "LigneHistorique.h"
using namespace std;

class Utilisateur
{
protected:
	string nom;
	string mdp;
	
public:
	Utilisateur(const string& nom, const string& mdp);
	~Utilisateur() = default;
	
	const string& Nom() const;
	bool AnalyserFichier(string nomfichier, const Attributs& attributs);
};

inline const string& Utilisateur::Nom() const {
	return nom;
}

#endif // UTILISATEUR_H