#include "Utilisateur.h"

Utilisateur::Utilisateur(const string& nom, const string& mdp) {
	this->nom = nom;
	this->mdp = mdp;
}

void Utilisateur::LancerAnalyse(string nomfichier) {
	Attributs att;
	vector<Empreinte*> empreintes;
	vector<Maladie*> maladies;
	vector<double> maladiesAssociees;
	if (!FichierChargerAttributs("HealthMeasurementDescription.txt", att)) {
		cerr << "Erreur lors du chargement des attributs !" << endl;
	}
	else {
		if (!FichierChargerEmpreintes(nomfichier, att, empreintes, maladies)) {
			cerr << "Erreur lors du chargement des empreintes+maladies !" << endl;
		}
		else {
			Analyse a(empreintes);
			LigneHistorique lh(this, &a);
			FichierMAJHist(*(lh.toString()), false);
		}
	}
}

