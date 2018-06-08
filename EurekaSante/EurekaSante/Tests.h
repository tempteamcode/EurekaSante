#ifndef TESTS_H
#define TESTS_H

#include "Reglages.h"
#include "Attributs.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "Analyse.h"
#include "InterfaceUtilisateur.h"
#include "GestionFichiers.h"
#include "GestionMaladies.h"

bool FichierGenererEmpreintesAleatoires(const string& path, uint nbEmpreintes, uint nbAttributs, uint nbMaladies);


bool testFichierChargerAttributs(bool display, const string& path);
bool testFichierChargerEmpreintesMaladies(bool display, const string& path);
bool testEffectuerStatistiques(bool display, const string& path);

inline bool testFichierChargerAttributs(bool display) { return testFichierChargerAttributs(display, FILE_ATTRIBUTS); }
inline bool testFichierChargerEmpreintesMaladies(bool display) { return testFichierChargerEmpreintesMaladies(display, FILE_EMPREINTESMALADIES); }
inline bool testEffectuerStatistiques(bool display) { return testEffectuerStatistiques(display, FILE_EMPREINTESMALADIES); }

bool testAfficherMaladiesConnues(bool display);
bool testEffectuerAnalyse(bool display);
bool testDuree(bool display);


bool testChronometrer(bool(*fn) (bool), bool display);

#endif // TESTS_H