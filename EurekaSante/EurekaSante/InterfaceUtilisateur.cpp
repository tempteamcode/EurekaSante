
#include <iostream>
using std::cin;
using std::cout;
using std::flush;
using std::endl;

#include "InterfaceUtilisateur.h"
#include "Attributs.h"
#include "GestionFichiers.h"
#include "Tests.h"


bool test()
{
	return testAfficherMaladiesConnues(true);
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
