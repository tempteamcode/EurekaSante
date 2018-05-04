#ifndef GESTIONFICHIERS_H
#define GESTIONFICHIERS_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::fstream;

#include "Empreinte.h"

bool FichierChargerAttributs(const string& path, Attributs& attributs);
bool FichierChargerEmpreintes(const string& path, vector<Empreinte>& empreintes);
bool FichierSauverEmpreintes(const string& path, const vector<Empreinte>& empreintes, bool overwrite);

#endif