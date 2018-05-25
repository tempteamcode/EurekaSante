#include "GestionMaladies.h"



void AfficherUneMaladie(const Maladie& m, const Attributs& a) {
	vector<double>::const_iterator itD;
	vector<freqAttr>::const_iterator itSI;
	cout << "Le nom de la maladie est : " << m.nom << endl;
	cout << "Les moyennes de chaque attribut double :";
	int indice = 0;
	for (itD = m.moyennes.cbegin(); itD != m.moyennes.cend(); ++itD) {
		while (a.IsDouble(indice) == false && indice < a.Compte()) {
			indice++;
		}
		cout << a.GetName(indice) << " :";
		cout << *itD << " ";
		indice++;
	}
	cout << endl;
	indice = 0;
	cout << "Les écarts types de chaque attribut double :";
	for (itD = m.ecartTypesDouble.cbegin(); itD != m.ecartTypesDouble.cend(); ++itD) {
		while (a.IsDouble(indice) == false && indice < a.Compte()) {
			indice++;
		}
		cout << a.GetName(indice) << " :";
		cout << *itD << " ";
		indice++;
	}
	cout << endl;
	for (itSI = m.frequenceAttributString.cbegin(); itSI != m.frequenceAttributString.cend(); ++itD) {
		while (a.IsDouble(indice) == false && indice < a.Compte()) {
			indice++;
		}
		cout << a.GetName(indice) << " :";
		cout << *itD << " ";
		indice++;
	}
}