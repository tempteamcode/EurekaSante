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

	FichierDechargerEmpreintes(empreintes);
	MaladiesConnues(maladies);

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
	int choix;
	while (true) {
		cout << "Connexion" << endl;
		cout << "Nom d'utilisateur : " << flush; cin >> nom;
		cout << "Mot de passe : " << flush; cin >> mdp;
		cout << endl;

		utilisateurcourant = nullptr;
		for (auto it = utilisateurs.begin(); it != utilisateurs.end(); ++it) {
			if (it->Nom() == nom) {
				if (it->Connexion(mdp)) {
					utilisateurcourant = &(*it);
					return true;
				}
			}
		}
		cout << endl;
		cout << "Mauvaise combinaison identifiant/mdp" << endl;
		cout << "Voulez-vous tentez de vous reconnecter ?" << endl;
		cout << "1. Oui" << endl;
		cout << "2. Non" << endl;
		cout << endl;
		cin >> choix;
		if (choix == 2) return false;
	}
}
void ApplicationHome()
{
	cout << endl;
	for (;;) {
		if (!Connexion()) return;
		while (utilisateurcourant != nullptr) {

			cout << "0. Deconnexion" << endl;
			cout << "1. Afficher Historique" << endl;
			cout << "2. Afficher Maladies" << endl;
			cout << "3. Analyser des empreintes" << endl;

			bool admin = utilisateurcourant->Nom() == "admin";

			if (admin) {
				cout << "4. Modifier la base des maladies" << endl;
			}
			cout << endl;
			cout << "Que faire ?" << endl;
			
			uint id;
			cin >> id;

			string nomfichier;

			switch (id)
			{
			case 0:
				utilisateurcourant->Deconnexion();
				utilisateurcourant = nullptr;
				break;
				
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
			if (id != 0) {
				cout << endl;
				system("pause");
				cout << endl;
			}
		}
		
		int choix;
		cout << endl;
		cout << "Voulez-vous vous reconnecter ?" << endl;
		cout << "1. Oui" << endl;
		cout << "2. Non" << endl;
		cout << endl;
		cin >> choix;
		if (choix == 2) return;
	}

}

void ApplicationTest() {
	cout << endl;
	for (;;) {
		cout << "0. Quitter" << endl;
		cout << "1. Test : Charger un fichier d'empreintes maladies " << endl;
		cout << "2. Test : Afficher les maladies connues par la base " << endl;
		cout << "3. Test : Effectuer une analyse " << endl;
		cout << "4. Test : Charger des attributs" << endl;
		cout << "5. Test : Effectuer des analyses" << endl;
		cout << endl;
		
		uint id;
		cin >> id;
		switch (id)
		{
		case 0:
			return;
		case 1:
			testFichierChargerEmpreintesMaladies(true);
			break;
		case 2:
			testAfficherMaladiesConnues(true);
			break;
		case 3:
			testEffectuerAnalyse(true);
			break;
		case 4:
			testFichierChargerAttributs(true);
			break;
		case 5:
			testEffectuerAnalyses(true);
			break;
		}
		
		cout << endl;
		system("pause");
		cout << endl;
	} 
}

#include <cstdio>
#include <ctime>

bool test()
{
	/*
	FichierGenererEmpreintesAleatoires("C:\\Temp\\bcpdm.csv", 10000, 100, 10);
	cout << "Empreintes generees." << endl;

	double duration;
	std::clock_t start; start = std::clock();

	//testEffectuerAnalyse(false);
	testEffectuerAnalyses(true);
	
	duration = (std::clock() - start) / double(CLOCKS_PER_SEC);
	cout << "Duree de l'analyse : " << duration << " secondes." << endl;
	return true;
	*/

	#ifdef DEV
		ApplicationTest();
	#else
		if (!InitialiserApplication()) return false;
		ApplicationHome();
	#endif
	
	return true;
}

#ifdef DEV
#define MSG_Welcome "Demarrage de EurekaSante en mode developpeur."
#else
#define MSG_Welcome "Demarrage de EurekaSante."
#endif

int main()
{
	cout << MSG_Welcome << endl;
	
	
	cout << endl;
	bool success = test();
	cout << endl;
	
	if (!success) cout << "Echec du test." << endl;
	
	
	cout << "Fermeture de EurekaSante." << endl;
	system("pause");
	return 0;
}
