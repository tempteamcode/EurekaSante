#ifndef GESTIONFICHIERS_H
#define GESTIONFICHIERS_H

#include <string>
using std::string;

#include <fstream>
using std::fstream;

#include <vector>
using std::vector;

#include "Empreinte.h"

struct Attributs
{
	vector<string> nom;
	vector<string> type;
	vector<unsigned int> indice;
};
void AfficherAttributs(const Attributs& attributs);

bool FichierChargerAttributs(const string& path, Attributs& attributs);
bool FichierChargerEmpreintes(const string& path, vector<Empreinte>& empreintes);
bool FichierSauverEmpreintes(const string& path, const vector<Empreinte>& empreintes, bool overwrite);

#endif