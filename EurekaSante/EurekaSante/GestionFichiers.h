#ifndef GESTIONFICHIERS_H
#define GESTIONFICHIERS_H

#include <fstream>
using std::fstream;

#include "Reglages.h"
#include "Attributs.h"
#include "Empreinte.h"
#include "Maladie.h"


void FichierDechargerEmpreintes(vector<Empreinte*>& empreintes);
void FichierDechargerMaladies(vector<Maladie*>& maladies);

bool FichierChargerAttributs(const string& path, Attributs& attributs);
bool FichierChargerEmpreintes(const string& path, const Attributs& attributs, vector<Empreinte*>& empreintes);
bool FichierChargerEmpreintes(const string& path, const Attributs& attributs, vector<Empreinte*>& empreintes, vector<Maladie*>& maladies);
bool FichierSauverEmpreintes(const string& path, const Attributs& attributs, const vector<Empreinte*>& empreintes, bool overwrite);
bool FichierAfficherHistorique();
bool FichierAjouterHistorique(const vector<string>& contenu);

#endif // GESTIONFICHIERS_H