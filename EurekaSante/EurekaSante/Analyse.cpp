
#include "Analyse.h"


vector<double> EffectuerAnalyse(const Empreinte& empreinte)
{
	vector<double> maladiesAssociees;
	
	const vector<double>& attributsDouble = empreinte.attributsDouble;
	const vector<string>& attributsString = empreinte.attributsString;
	uint nbDouble = attributsDouble.size();
	uint nbString = attributsString.size();
	
	for (auto item = maladiesConnues.cbegin(); item < maladiesConnues.cend(); ++item)
	{
		const Maladie* m = *item;
		
		double sommeproximites = 0.0;
		bool possible = true;
		
		for (uint idouble = 0; idouble < nbDouble; idouble++)
		{
			double et = m->ecartTypes[idouble] * 3;
			double moy = m->moyennes[idouble];
			
			double valeur = attributsDouble[idouble];
			
			double proximite = 1.0 - (abs(valeur - moy) / et);
			if (proximite < 0.0) {
				possible = false;
				break;
			}
			sommeproximites += proximite;
		}
		
		for (uint istring = 0; istring < nbString; istring++)
		{
			double freq = m->frequences[istring].at(attributsString[istring]);
			sommeproximites += freq;
		}
		
		double proximite = sommeproximites / (nbDouble + nbString);
		maladiesAssociees.push_back(proximite);
	}
	
	return maladiesAssociees;
}
