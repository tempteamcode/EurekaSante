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

bool testFichierChargerAttributs(bool display);
bool testFichierChargerEmpreintesMaladies(bool display);
bool testAfficherMaladiesConnues(bool display);
bool testEffectuerAnalyse(bool display);
bool testEffectuerAnalyses(bool display);

#endif // TESTS_H