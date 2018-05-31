#ifndef ATTRIBUTS_H
#define ATTRIBUTS_H

#include "Reglages.h"

class Attributs
{
public:
	uint Compte() const;
	void Ajouter(string nom, string type);
	void Afficher() const;
	const string& GetName(uint index) const;
	bool IsDouble(uint index) const;
	
private:
	vector<string> noms;
	vector<string> types;
	vector<uint> indices;
};

inline uint Attributs::Compte() const {
	return uint(indices.size());
}

inline const string& Attributs::GetName(uint index) const {
	return noms[index];
}

inline bool Attributs::IsDouble(uint index) const {
	return (types[index] == "double");
}

#endif // ATTRIBUTS_H