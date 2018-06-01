
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include "Tests.h"


extern Attributs attributs;
vector<Empreinte*> empreintes;
vector<Empreinte*> empreintesTest;
vector<Maladie*> maladies;

bool testFichierChargerAttributs(bool display)
{
	if (!FichierChargerAttributs(FILE_ATTRIBUTS, attributs)) {
		cerr << "Erreur lors du chargement des attributs !" << endl;
		return false;
	}
	
	if (display) {
		attributs.Afficher();
	}
	
	return true;
}

bool testFichierChargerEmpreintesMaladies(bool display)
{
	if (!testFichierChargerAttributs(false)) return false;
	
	if (!FichierChargerEmpreintes(FILE_EMPREINTESMALADIES, attributs, empreintes, maladies)) {
		cerr << "Erreur lors du chargement des empreintes+maladies !" << endl;
		return false;
	}
	
	if (display) {
		for (auto item = empreintes.cbegin(); item != empreintes.cend(); ++item) {
			(*item)->Afficher(attributs);
		}
		for (auto item = maladies.cbegin(); item != maladies.cend(); ++item) {
			(*item)->Afficher(attributs);
		}
	}
	
	return true;
}

bool testAfficherMaladiesConnues(bool display)
{
	if (!testFichierChargerEmpreintesMaladies(false)) return false;

	MaladiesConnues(maladies);

	if (display) {
		AfficherMaladiesConnues(attributs);
	}

	return true;
}

bool testEffectuerAnalyse(bool display)
{
	if (!testAfficherMaladiesConnues(false)) return false;
	
	if (!FichierChargerEmpreintes("Test4Empreintes.txt", attributs, empreintesTest)) {
		cerr << "Erreur lors du chargement des empreintes !" << endl;
		return false;
	}
	
	Analyse analyse(empreintesTest);
	
	if (display) {
		analyse.Afficher(attributs, empreintesTest);
	}
	
	return true;
}

/*
bool testEffectuerAnalyses(bool display)
{
	if (!testAfficherMaladiesConnues(false)) return false;
	
	if (!FichierChargerEmpreintes(FILE_EMPREINTESMALADIES, attributs, empreintesTest)) {
		cerr << "Erreur lors du chargement des empreintes !" << endl;
		return false;
	}
	
	Analyse analyse(empreintesTest);
	
	if (display) {
		analyse.Afficher(attributs, empreintesTest);
	}
	
	return true;
}
*/
