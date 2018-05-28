#include "Analyse.h"

vector<Maladie> EffectuerAnalyse(const Empreinte& empreinte)
{
	vector<Maladie> maladiesAssociees;

	for (auto item = maladiesConnues.cbegin(); item < maladiesConnues.cend(); ++item)
	{
		const Maladie* m = *item;

		double sommeproximites = 0.0;
		
		for (uint idouble = 0; idouble < empreinte.attributsDouble.size(); idouble++)
		{
			double et = m->ecartTypes[idouble];
			double moy = m->moyennes[idouble];

			double valeur = empreinte.attributsDouble[idouble];

			double proximite = abs(valeur - moy) / et;
			sommeproximites += proximite;
		}

		// [...]
	}

	// [...]

	return maladiesAssociees;
}
