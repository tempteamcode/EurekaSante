#include "Utilisateur.h"

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
	LigneHistorique lh((*this), a);
	FichierMAJHist(lh.toString(), false);
	
	return true;
}
