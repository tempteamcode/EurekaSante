
#include <iostream>
using std::cout;
using std::endl;

#include "Reglages.h"
#include "Attributs.h"

void Attributs::Ajouter(string nom, string type)
{
	noms.push_back(nom);
	types.push_back(type);
	indices.push_back(uint(indices.size()));
}

void Attributs::Afficher() const
{
	for (uint index = 0; index < indices.size(); index++) {
		cout << '#' << index << " : " << '(' << types[index] << ") " << noms[index] << endl;
	}
}

bool Attributs::IsDouble(uint index) const
{
	return (types[index] == "double");
}
