
#include "Analyse.h"

const double ANALYSE_SEUIL = 0.5;

vector<const Maladie*> maladiesConnues;

void SetMaladiesConnues(vector<Maladie*> maladies) {
	maladiesConnues.resize(maladies.size());

	auto cit = maladiesConnues.begin();
	for (auto it = maladies.cbegin(); it != maladies.cend(); ++it, ++cit) {
		*cit = *it;
	}
}

unordered_map<const Maladie*, double> EffectuerAnalyse(const Empreinte& empreinte)
{
	unordered_map<const Maladie*, double> resultat;

	const vector<double>& attributsDouble = empreinte.AttributsDouble();
	const vector<string>& attributsString = empreinte.AttributsString();
	uint nbDouble = attributsDouble.size();
	uint nbString = attributsString.size();
	
	for (auto item = maladiesConnues.cbegin(); item < maladiesConnues.cend(); ++item)
	{
		const Maladie& m = *(*item);
		
		double sommeproximites = 0.0;
		bool possible = true;
		
		for (uint idouble = 0; idouble < nbDouble; idouble++)
		{
			double et = m.EcartTypes()[idouble] * 3;
			double moy = m.Moyennes()[idouble];
			
			double valeur = attributsDouble[idouble];
			
			double proximite;
			if (et == 0.0) {
				proximite = (valeur == moy ? 1.0 : 0.0);
			}
			else {
				proximite = 1.0 - (abs(valeur - moy) / et);
			}
			
			if (proximite < 0.0) {
				possible = false;
				break;
			}
			
			sommeproximites += proximite;
		}
		
		if (possible) {
			for (uint istring = 0; istring < nbString; istring++)
			{
				double freq = m.Frequences()[istring].at(attributsString[istring]);
				sommeproximites += freq;
			}

			double proximite = sommeproximites / (nbDouble + nbString);
			if (proximite > ANALYSE_SEUIL) resultat[*item] = proximite;
		}
	}
	
	return resultat;
}
