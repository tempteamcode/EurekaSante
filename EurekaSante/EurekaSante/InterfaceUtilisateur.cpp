
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
// #include "Tests.h"


Attributs attributs;

vector<Utilisateur> utilisateurs;

bool InitialiserApplication()
{
	if (!FichierChargerAttributs("HealthMeasurementDescription.txt", attributs)) {
		cerr << "Erreur lors du chargement des attributs !" << endl;
		return false;
	}
	
	vector<Empreinte*> empreintes;
	vector<Maladie*> maladies;
	if (!FichierChargerEmpreintes("HealthMeasurementsWithLabels.txt", attributs, empreintes, maladies)) {
		cerr << "Erreur lors du chargement des empreintes+maladies !" << endl;
		return false;
	}

	MaladiesConnues(maladies);
	
	// TODO : delete[] empreintes;
	
	Utilisateur admin("admin", "admin");
	Utilisateur michel("michel", "toto");
	utilisateurs.push_back(admin);
	utilisateurs.push_back(michel);

	return true;
}


bool test()
{
	/*
	if (!InitialiserApplication()) return false;

	if (!utilisateurs[1].AnalyserFichier("Test4Empreintes.txt", attributs)) return false;
	
	return FichierAfficherHistorique(); // testAfficherMaladiesConnues(true);
	*/

	return InitialiserApplication() && utilisateurs[1].AnalyserFichier("Test4Empreintes.txt", attributs) && FichierAfficherHistorique();
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
