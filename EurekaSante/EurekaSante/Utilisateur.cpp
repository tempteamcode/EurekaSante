#include "Utilisateur.h"

#include <iostream>
using std::cerr;
using std::endl;

Utilisateur::Utilisateur(const string& nom, const string& mdp)
: nom(nom), mdp(mdp), connecte(false)
{
}

bool Utilisateur::AnalyserFichier(string nomfichier, const Attributs& att)
{
	if (!connecte) return false;

	vector<Empreinte*> empreintes;

	if (!FichierChargerEmpreintes(nomfichier, att, empreintes)) {
		cerr << "Erreur lors du chargement des empreintes !" << endl;
		return false;
	}

	Analyse a(empreintes);
	a.Afficher(att, empreintes);

	LigneHistorique lh((*this), a);
	FichierAjouterHistorique(lh.toString());
	
	return true;
}
