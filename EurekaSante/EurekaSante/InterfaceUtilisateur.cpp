#include <iomanip>
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::flush;
using std::endl;

#define cin_safe(var) cin >> var; if (cin.fail()) {cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}

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

void MenuAfficherMaladie()
{
	extern vector<const Maladie*> maladiesConnues;
	
	uint i = 0;
	cout << "Maladies :" << endl;
	for (auto it = maladiesConnues.cbegin(); it != maladiesConnues.cend(); ++it, i++) {
		string nom = (*it)->Nom();
		if (nom == "") nom = "Profil sain";
		cout << (i+1) << ". " << nom << endl;
	}
	cout << endl;
	
	uint choix;
	cout << "Choix : " << flush;
	cin_safe(choix);
	
	if ((choix > 0) && (choix <= maladiesConnues.size())) {
		(maladiesConnues[choix-1])->Afficher(attributs);
	}
	cout << endl;
}

bool MenuConnexion()
{
	string nom;
	string mdp;
	for (;;) {
		cout << "Connexion" << endl;
		cout << "Nom d'utilisateur : " << flush; cin_safe(nom);
		cout << "Mot de passe : " << flush; cin_safe(mdp);
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
		
		int choix;
		cout << endl;
		cout << "Mauvaise combinaison identifiant/mot de passe." << endl;
		cout << "Voulez-vous tentez de vous reconnecter ?" << endl;
		cout << "0. Non" << endl;
		cout << "1. Oui" << endl;
		cout << endl;
		cin_safe(choix);
		if (choix == 0) return false;
	}
}
void ApplicationHome()
{
	for (;;) {
		if (!MenuConnexion()) return;
		while (utilisateurcourant != nullptr) {
			bool admin = utilisateurcourant->Nom() == "admin";
			
			cout << "0. Deconnexion" << endl;
			cout << "1. Afficher Historique" << endl;
			cout << "2. Afficher Maladies" << endl;
			cout << "3. Afficher une maladie" << endl;
			cout << "4. Analyser des empreintes" << endl;
 if (admin) cout << "5. Modifier la base des maladies" << endl;
			cout << endl;
			cout << "Que faire ?" << endl;
			
			string nomfichier;
			
			uint id;
			cin_safe(id);
			cout << endl;
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
				MenuAfficherMaladie();
				break;
				
			case 4:
				cout << "Nom du fichier a analyser : " << flush;
				cin_safe(nomfichier);
				
				utilisateurcourant->AnalyserFichier(nomfichier, attributs);
				break;
				
			case 5: if (!admin) break;
				cout << "Nom du fichier a charger : " << flush;
				cin_safe(nomfichier);
				
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
		cout << "0. Non" << endl;
		cout << "1. Oui" << endl;
		cout << endl;
		cin_safe(choix);
		if (choix == 0) return;
	}
}

void ApplicationTest() {
	for (;;) {
		cout << "0. Quitter" << endl;
		cout << "1. Test : Charger un fichier d'empreintes maladies" << endl;
		cout << "2. Test : Afficher les maladies connues par la base" << endl;
		cout << "3. Test : Effectuer une analyse" << endl;
		cout << "4. Test : Charger des attributs" << endl;
		cout << "5. Test : Effectuer des statistiques d'analyses" << endl;
		cout << "6. Test : Performances" << endl;
		cout << endl;
		cout << "Que faire ?" << endl;
		
		uint id;
		cin_safe(id);
		cout << endl;
		switch (id)
		{
			case 0: return;
			case 1: testChronometrer(testFichierChargerEmpreintesMaladies, true); break;
			case 2: testChronometrer(testAfficherMaladiesConnues,          true); break;
			case 3: testChronometrer(testEffectuerAnalyse,                 true); break;
			case 4: testChronometrer(testFichierChargerAttributs,          true); break;
			case 5: testChronometrer(testEffectuerStatistiques,            true); break;
			case 6: testChronometrer(testDuree,                            true); break;
		}
		
		cout << endl;
		system("pause");
		cout << endl;
	} 
}

#ifdef DEV
#define INIT_MSG "Demarrage de EurekaSante en mode developpeur."
#define INIT_APP ApplicationTest
#else
#define INIT_MSG "Demarrage de EurekaSante."
#define INIT_APP if (!InitialiserApplication()) return false; ApplicationHome
#endif

bool run()
{
	INIT_APP();
	return true;
}

int main()
{
	cout << INIT_MSG << endl;
	
	
	cout << endl;
	bool success = run();
	
	if (!success) cout << "Echec de l'execution." << endl;
	
	
	cout << "Fermeture de EurekaSante." << endl;
	system("pause");
	return 0;
}
