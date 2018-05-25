#include "Tests.h"

Attributs attributs;
vector<Empreinte*> empreintes;
vector<Maladie*> maladies;

bool testFichierChargerAttributs()
{
	if (!FichierChargerAttributs("HealthMeasurementDescription.txt", attributs))
	{
		cerr << "Erreur lors du chargement des attributs !" << endl;
		return false;
	}
	attributs.Afficher();

	return true;
}

bool testFichierChargerEmpreintesMaladies()
{
	if (!testFichierChargerAttributs()) return false;

	if (!FichierChargerEmpreintes("Test4EmpreintesMaladies.txt", attributs, empreintes, maladies))
	{
		cerr << "Erreur lors du chargement des empreintes+maladies !" << endl;
		return false;
	}

	for (auto item = empreintes.cbegin(); item != empreintes.cend(); ++item)
	{
		(*item)->Afficher();
	}

	return true;
}
