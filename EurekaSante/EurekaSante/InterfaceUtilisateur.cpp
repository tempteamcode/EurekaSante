
#include "InterfaceUtilisateur.h"
#include "Attributs.h"
#include "GestionFichiers.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout << "Demarrage de EurekaSante." << endl;

	Attributs attributs;
	FichierChargerAttributs("HealthMeasurementDescription.txt", attributs);
	attributs.Afficher();
	
	cout << "Fermeture de EurekaSante." << endl;
	cout << endl << "Pressez ENTREE pour terminer." << flush;
	char fermer = cin.get();
	return 0;
}
