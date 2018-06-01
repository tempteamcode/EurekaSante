
#include <iostream>
using std::cerr;
using std::endl;

#include "Tests.h"


Attributs attributs;
vector<Empreinte*> empreintes;
vector<Maladie*> maladies;

bool testFichierChargerAttributs(bool display)
{
	if (!FichierChargerAttributs("HealthMeasurementDescription.txt", attributs)) {
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
	
	if (!FichierChargerEmpreintes("Test4EmpreintesMaladies.txt", attributs, empreintes, maladies)) {
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
