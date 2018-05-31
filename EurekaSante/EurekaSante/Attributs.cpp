
#include <iostream>
using std::cout;
using std::endl;

#include "Attributs.h"


void Attributs::Ajouter(string nom, string type)
{
	noms.push_back(nom);
	types.push_back(type);
	indices.push_back(Compte());
}

void Attributs::Afficher() const
{
	for (uint index = 0; index < Compte(); index++) {
		cout << '#' << index << " : " << '(' << types[index] << ") " << noms[index] << endl;
	}
}
