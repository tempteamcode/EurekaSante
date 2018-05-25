
#include <iostream>
using std::cout;
using std::endl;

#include "Reglages.h"
#include "Attributs.h"

uint Attributs::Compte() const
{
	return uint(indices.size());
}

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

const string& Attributs::GetName(uint index) const
{
	return noms[index];
}
bool Attributs::IsDouble(uint index) const
{
	return (types[index] == "double");
}
