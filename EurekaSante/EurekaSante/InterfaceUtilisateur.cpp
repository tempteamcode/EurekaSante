
#include "InterfaceUtilisateur.h"
#include "Attributs.h"
#include "GestionFichiers.h"
#include "Tests.h"

#include <iostream>
using std::cout;
using std::endl;

bool test()
{
	return testFichierChargerEmpreintesMaladies();
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
