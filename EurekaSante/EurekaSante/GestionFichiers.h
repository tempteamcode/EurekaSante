#ifndef GESTIONFICHIERS_H
#define GESTIONFICHIERS_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::fstream;

#include "Reglages.h"
#include "Attributs.h"
#include "Empreinte.h"
#include "Maladie.h"

bool FichierChargerAttributs(const string& path, Attributs& attributs);
bool FichierChargerEmpreintes(const string& path, const Attributs& attributs, vector<Empreinte*>& empreintes, vector<Maladie*>& maladies = vector<Maladie*>());
bool FichierSauverEmpreintes(const string& path, const vector<Empreinte>& empreintes, bool overwrite);

#endif