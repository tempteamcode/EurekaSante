#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "Reglages.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "GestionFichiers.h"
#include "Analyse.h"
#include "LigneHistorique.h"

class Utilisateur
{
protected:
	bool connecte;
	string nom;
	string mdp;
	
public:
	Utilisateur(const string& nom, const string& mdp);
	~Utilisateur() = default;
	
	const string& Nom() const;
	
	bool Connexion(string s);
	void Deconnexion();

	bool AnalyserFichier(string nomfichier, const Attributs& attributs);
};

inline const string& Utilisateur::Nom() const {
	return nom;
}

inline bool Utilisateur::Connexion(string s)
{
	return (connecte = (s == mdp));
}

inline void Utilisateur::Deconnexion()
{
	connecte = false;
}

#endif // UTILISATEUR_H