
#include <iostream>
using std::cout;
using std::endl;

#include <math.h>

#include "Maladie.h"
#include "Empreinte.h"


void Maladie::Afficher(const Attributs& a) const
{
	if (nom != "") {
		cout << "Maladie : " << nom << endl;
	}
	else {
		cout << "Profil sain : " << endl;
	}
	
	uint istring = 0;
	uint idouble = 0;
	for (uint i = 0; i < a.Compte(); i++) {
		cout << a.GetName(i) << " :";
		
		if (a.IsDouble(i)) {
			cout << "  Moyenne : " << moyennes[idouble];
			cout << "  Ecart type : " << ecartTypes[idouble] << endl;
			idouble++;
		}
		else {
			const freqAttr& fmap = frequences[istring];
			if (fmap.size() > 1) cout << endl;
			for (freqAttr::const_iterator it = fmap.cbegin(); it != fmap.cend(); ++it) {
				cout << "  Valeur : \"" << it->first << '\"';
				cout << "  Frequence : " << it->second << endl;
			}
			istring++;
		}
	}
	cout << endl;
}

Maladie::Maladie(const string& nom, const vector<Empreinte*> &empreintes)
:	nom(nom)
{
	uint nbEmpreintes = empreintes.size();
	uint nbAttributsDouble = (*empreintes.cbegin())->AttributsDouble().size();
	uint nbAttributsString = (*empreintes.cbegin())->AttributsString().size();
	
	double* somme = new double[nbAttributsDouble];
	double** valeurAttribut = new double*[nbAttributsDouble];
	for (uint i = 0; i < nbAttributsDouble; i++) {
		somme[i] = 0.0;
		valeurAttribut[i] = new double[nbEmpreintes];
	}
	
	frequences.resize(nbAttributsString);
	for (uint ie = 0; ie < nbEmpreintes; ie++) {
		const Empreinte& e = *empreintes[ie];
		for (uint istr = 0; istr < nbAttributsString; istr++) {
			frequences[istr][e.AttributsString()[istr]]++;
		}
		for (uint idbl = 0; idbl < nbAttributsDouble; idbl++) {
			somme[idbl] += (valeurAttribut[idbl][ie] = e.AttributsDouble()[idbl]);
		}
	}
	
	
	moyennes.resize(nbAttributsDouble);
	ecartTypes.resize(nbAttributsDouble);
	for (uint i = 0; i < nbAttributsDouble; i++) {
		double moyenne = somme[i] / nbEmpreintes;
		moyennes[i] = moyenne;
		
		double ecartsomme = 0.0;
		double* valeurs = valeurAttribut[i];
		for (uint j = 0; j < nbEmpreintes; j++) {
			ecartsomme += pow((valeurs[j] - moyenne), 2);
		}
		
		double ecartType = sqrt(ecartsomme / nbEmpreintes);
		ecartTypes[i] = ecartType;
	}
	
	for (uint istr = 0; istr < nbAttributsString; istr++) {
		freqAttr& freqistr = frequences[istr];
		
		double fmax = 0.0;
		for (auto it = freqistr.cbegin(); it != freqistr.cend(); ++it) {
			if (it->second > fmax) fmax = it->second;
		}
		if (fmax > 0.0) {
			for (auto it = freqistr.begin(); it != freqistr.end(); ++it) {
				it->second /= fmax;
			}
		}
	}
	
	delete somme;
	delete valeurAttribut;
}
