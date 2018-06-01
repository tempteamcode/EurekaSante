
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::flush;
using std::endl;

#include "InterfaceUtilisateur.h"
#include "Attributs.h"
#include "GestionFichiers.h"
#include "Utilisateur.h"
#include "Tests.h"


Attributs attributs;

vector<Utilisateur> utilisateurs;
Utilisateur* utilisateurcourant;

bool InitialiserMaladiesConnues(string nomfichier)
{
	vector<Empreinte*> empreintes;
	vector<Maladie*> maladies;
	if (!FichierChargerEmpreintes(nomfichier, attributs, empreintes, maladies)) {
		cerr << "Erreur lors du chargement des empreintes+maladies !" << endl;
		return false;
	}

	MaladiesConnues(maladies);

	// TODO : delete[] empreintes;

	return true;
}

bool InitialiserApplication()
{
	if (!FichierChargerAttributs(FILE_ATTRIBUTS, attributs)) {
		cerr << "Erreur lors du chargement des attributs !" << endl;
		return false;
	}
	
	if (!InitialiserMaladiesConnues(FILE_EMPREINTESMALADIES)) return false;
	
	Utilisateur admin("admin", "admin");
	Utilisateur mickael("mickael", "gadoud");
	utilisateurs.push_back(admin);
	utilisateurs.push_back(mickael);

	return true;
}

bool Connexion()
{
	string nom;
	string mdp;
	
	cout << "Connexion :" << endl;
	cout << "Nom d'utilisateur : " << flush; cin >> nom;
	cout << "Mot de passe : " << flush; cin >> mdp;
	
	utilisateurcourant = nullptr;
	for (auto it = utilisateurs.begin(); it != utilisateurs.end(); ++it) {
		if (it->Nom() == nom) {
			if (it->Connexion(mdp)) {
				utilisateurcourant = &(*it);
				return true;
			}
		}
	}
	
	return false;
}

void ApplicationHome()
{
	if (!Connexion()) return;
	
	cout << "1. Afficher Historique" << endl;
	cout << "2. Afficher Maladies" << endl;
	cout << "3. Analyser des empreintes" << endl;

	bool admin = utilisateurcourant->Nom() == "admin";
	
	if (admin) {
		cout << "4. Modifier la base des maladies" << endl;
	}

	cout << "Que faire ?" << endl;

	uint id;
	cin >> id;
	
	string nomfichier;

	switch (id)
	{
		case 1:
			FichierAfficherHistorique();
			break;

		case 2:
			AfficherMaladiesConnues(attributs);
			break;

		case 3:
			cout << "Nom du fichier a analyser : " << flush;
			cin >> nomfichier;
			
			utilisateurcourant->AnalyserFichier(nomfichier, attributs);
			break;

		case 4: if (!admin) break;
			cout << "Nom du fichier a charger : " << flush;
			cin >> nomfichier;
			
			InitialiserMaladiesConnues(nomfichier);
			break;
	}

	utilisateurcourant->Deconnexion();
}


bool test()
{
	if (!InitialiserApplication()) return false;
	
	ApplicationHome();
	
	cout << "En attente de toto" << endl;
	int toto;
	cin >> toto;
	
	return true;
}


int main()
{
	cout << "Demarrage de EurekaSante." << endl;
	
	
	cout << endl;
	bool success = test();
	cout << endl;
	
	if (!success) cout << "Echec du test." << endl;
	
	
	cout << "Fermeture de EurekaSante." << endl;
	cout << endl << "Pressez ENTREE pour terminer." << flush;
	char fermer = cin.get();
	return 0;
}
