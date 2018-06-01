
#include <iostream>
using std::cout;
using std::endl;

#include "Analyse.h"

const double ANALYSE_SEUIL = 0.5;


vector<const Maladie*> maladiesConnues;

void MaladiesConnues(vector<Maladie*> maladies) {
	maladiesConnues.resize(maladies.size());

	auto cit = maladiesConnues.begin();
	for (auto it = maladies.cbegin(); it != maladies.cend(); ++it, ++cit) {
		*cit = *it;
	}
}


Analyse::Analyse(const vector<Empreinte*> &empreintes) {
	uint nbEmpreintes = empreintes.size();
	resultats.resize(nbEmpreintes);
	
	auto cit = empreintes.cbegin();
	for (auto it = resultats.begin(); it != resultats.end(); ++cit, ++it) {
		EffectuerAnalyse(*it, *(*cit));
	}
}

void Analyse::Afficher(const Attributs& attributs, const vector<Empreinte*> &empreintes) const {
	auto cit = resultats.cbegin();
	for (auto it = empreintes.cbegin(); it != empreintes.cend(); ++it, ++cit) {
		const Empreinte& e = *(*it);
		
		cout << endl;
		cout << "ANALYSE DE L'EMPREINTE :" << endl;
		e.Afficher(attributs);
		cout << "MALADIES IDENTIFIEES :" << endl;
		
		const mapMaladie& resultat = *cit;
		if (resultat.size() == 0) cout << "- Aucune" << endl;

		for (auto item = resultat.cbegin(); item != resultat.cend(); ++item) {
			const Maladie& m = *(item->first);
			double pourcentage = item->second * 100;

			const string& nom = m.Nom();
			if (nom != "") {
				cout << "- " << nom << " avec " << pourcentage << "%" << endl;
			}
			else {
				cout << "- Sain a " << pourcentage << "%" << endl;
			}
		}
	}
}


void EffectuerAnalyse(mapMaladie& resultat, const Empreinte& empreinte)
{
	const vector<double>& attributsDouble = empreinte.AttributsDouble();
	const vector<string>& attributsString = empreinte.AttributsString();
	uint nbDouble = attributsDouble.size();
	uint nbString = attributsString.size();
	uint nbAttributs = nbDouble + nbString;
	
	for (auto item = maladiesConnues.cbegin(); item < maladiesConnues.cend(); ++item)
	{
		const Maladie& m = *(*item);
		
		double sommeproximites = 0.0;
		// bool possible = true;
		
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
				proximite = -1.0 / nbAttributs;
				// possible = false;
				// break;
			}
			
			sommeproximites += proximite;
		}
		
		// if (possible) {
			for (uint istring = 0; istring < nbString; istring++)
			{
				double freq = m.Frequences()[istring].at(attributsString[istring]);
				sommeproximites += freq;
			}
			
			double proximite = sommeproximites / nbAttributs;
			if (proximite > ANALYSE_SEUIL) resultat[*item] = proximite;
		// }
	}
}
