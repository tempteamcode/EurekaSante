#ifndef ANALYSE_H
#define ANALYSE_H

#include <unordered_map>
using std::unordered_map;

#include "Reglages.h"
#include "Empreinte.h"
#include "Maladie.h"

unordered_map<const Maladie*, double> EffectuerAnalyse(const Empreinte& empreinte);

void SetMaladiesConnues(vector<Maladie*> maladies);

#endif // ANALYSE_H