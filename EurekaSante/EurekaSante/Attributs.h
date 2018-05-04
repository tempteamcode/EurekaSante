#ifndef ATTRIBUTS_H
#define ATTRIBUTS_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Reglages.h"

class Attributs
{
public:
	uint Compte() const;
	void Ajouter(string nom, string type);
	void Afficher() const;
	bool IsDouble(uint index) const;
	
private:
	vector<string> noms;
	vector<string> types;
	vector<uint> indices;
};


#endif // ATTRIBUTS_H