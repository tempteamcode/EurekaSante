#include "GestionMaladies.h"



void AfficherUneMaladie(const Maladie& m, const Attributs& a) {
	cout << "Le nom de la maladie est : " << m.nom << endl;
	uint istring = 0;
	uint idouble = 0;
	freqAttr::const_iterator itMap;

	for (uint i = 0; i < a.Compte(); i++) {
		cout << a.GetName(i) << ":";
		cout << endl;
		if (a.IsDouble(i)) {
			cout << "Moyenne : ";
			cout << m.moyennes[idouble];
			cout << "Ecart type : ";
			cout << m.ecartTypesDouble[idouble];
			idouble++;
		}
		else {
			for (itMap = m.frequenceAttributString[istring].cbegin(); itMap != m.frequenceAttributString[istring].cend(); ++itMap) {
				cout << "Valeur : ";
				cout << itMap->first<<" ";
				cout << "Fréquence : ";
				cout << itMap->second;
				if (itMap != m.frequenceAttributString[istring].cend()) {
					cout << endl;
				}
			}
			istring++;
		}
		cout << endl;
	}
	
}