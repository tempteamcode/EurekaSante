
#include "InterfaceUtilisateur.h"

#include "GestionFichiers.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout << "Demarrage de EurekaSante." << endl;

	Attributs attributs;
	FichierChargerAttributs("HealthMeasurementDescription.txt", attributs);
	AfficherAttributs(attributs);
	
	string temp;
	cin >> temp;
	cout << "Fermeture de EurekaSante." << endl;
	return 0;
}
