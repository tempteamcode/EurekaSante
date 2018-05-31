#ifndef ANALYSE_H
#define ANALYSE_H

#include "Reglages.h"
#include "Empreinte.h"
#include "Maladie.h"

vector<const Maladie*> maladiesConnues;

vector<const Maladie*> EffectuerAnalyse(const Empreinte& empreinte);

#endif // ANALYSE_H