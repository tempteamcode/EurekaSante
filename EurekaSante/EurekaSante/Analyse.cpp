
#include "Analyse.h"


vector<const Maladie*> EffectuerAnalyse(const Empreinte& empreinte)
{
	vector<const Maladie*> maladiesAssociees;
	
	const vector<double>& attributsDouble = empreinte.attributsDouble;
	const vector<string>& attributsString = empreinte.attributsString;
	
	for (auto item = maladiesConnues.cbegin(); item < maladiesConnues.cend(); ++item)
	{
		const Maladie* m = *item;
		
		double sommeproximites = 0.0;
		
		for (uint idouble = 0; idouble < attributsDouble.size(); idouble++)
		{
			double et = m->ecartTypes[idouble];
			double moy = m->moyennes[idouble];
			
			double valeur = attributsDouble[idouble];
			
			double proximite = abs(valeur - moy) / et;
			sommeproximites += proximite;
		}
		
		// [...]
	}
	
	// [...]
	
	return maladiesAssociees;
}
