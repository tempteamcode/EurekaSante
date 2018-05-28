#ifndef ANALYSE_H
#define ANALYSE_H

#include <vector>
using std::vector;

#include "Reglages.h"
#include "Empreinte.h"
#include "Maladie.h"

vector<const Maladie*> maladiesConnues;

vector<Maladie> EffectuerAnalyse(const Empreinte& empreinte);

#endif // ANALYSE_H