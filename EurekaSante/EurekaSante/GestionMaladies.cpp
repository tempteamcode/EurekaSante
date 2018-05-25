#include "GestionMaladies.h"
#include "Maladie.h"

void AfficherMaladie(Maladie m,Attributs a) {
	int i = 0;
	vector<double>::const_iterator itD;
	cout << "Le nom de la maladie est : " << m.nom << endl;
	cout << "Les moyennes de chaque attribut :";
	for (itD = m.moyennes.cbegin(); itD != m.moyennes.cend(); ++itD) {
		cout << *itD << " ";
	}
	cout << endl;
	cout << "Les écarts types de chaque attribut :";
	for (itD = m.ecartTypesDouble.cbegin(); itD != m.ecartTypesDouble.cend(); ++itD) {
		cout << *itD << " ";
	}
	cout
}