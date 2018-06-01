
#include <iostream>
using std::cout;
using std::endl;

#include <math.h>

#include "Maladie.h"
#include "Empreinte.h"


void Maladie::Afficher(const Attributs& a) const
{
	cout << "Maladie : " << nom << endl;
	
	uint istring = 0;
	uint idouble = 0;
	for (uint i = 0; i < a.Compte(); i++) {
		cout << "Attribut " << a.GetName(i) << " :";
		
		if (a.IsDouble(i)) {
			cout << "  Moyenne : " << moyennes[idouble] << " ";
			cout << "Ecart type : " << ecartTypes[idouble] << endl;
			idouble++;
		}
		else {
			const freqAttr& fmap = frequences[istring];
			if (fmap.size() > 1) cout << endl;
			for (freqAttr::const_iterator it = fmap.cbegin(); it != fmap.cend(); ++it) {
				cout << "  Valeur : \"" << it->first << "\" ";
				cout << "Frequence : " << it->second << endl;
			}
			istring++;
		}
	}
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
	const double poids = 1.0 / nbEmpreintes;
	for (uint ie = 0; ie < nbEmpreintes; ie++) {
		const Empreinte& e = *empreintes[ie];
		for (uint istr = 0; istr < nbAttributsString; istr++) {
			frequences[istr][e.AttributsString()[istr]] += poids;
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
	
	delete somme;
	delete valeurAttribut;
}

/*
void Maladie::CalculerCaracteristiques(const vector<Empreinte*> &e) {
	vector<Empreinte*>::const_iterator itE;
	vector<string>::const_iterator itS;
	vector<double>::const_iterator itD;
	freqAttr::iterator itM;
	double moyenne = 0.0;
	double ecarttype = 0.0;
	double ecartsomme = 0.0;
	int nbEmpreintes = static_cast<int>(e.size());
	int size = static_cast<int>(e.at(0)->attributsDouble.size());
	double* somme = new double[size];
	double** valeurAttribut;
	valeurAttribut = new double*[static_cast<int>(e.size())];
	for (int i = 0; i < nbEmpreintes; i++) {
		valeurAttribut[i] = new double[size];
	}
	int indicesomme = 0;
	int positionitS;
	int positionitD;
	int indiceEmpreinte = 0;
	for (int j = 0; j < size; j++) {
		somme[j] = 0;
	}
	frequenceAttributString.resize(e.at(0)->attributsString.size());
	Empreinte* pointeurE;
	for (itE = e.cbegin(); itE != e.cend(); ++itE) {
		pointeurE = *itE;
		positionitS = 0;
		positionitD = 0;
		indicesomme = 0;
		for (itS = pointeurE->attributsString.cbegin(); itS != pointeurE->attributsString.cend(); ++itS) {
			map<string, int>& m = frequenceAttributString[positionitS];
			m[*itS]++;
			positionitS++;
		}
		for (itD = pointeurE->attributsDouble.cbegin(); itD != pointeurE->attributsDouble.cend(); ++itD) {
			valeurAttribut[indiceEmpreinte][indicesomme] = *itD;
			somme[indicesomme] += *itD;
			indicesomme++;
		}
		indiceEmpreinte++;
	}
	for (int i = 0; i < size; i++) {
		ecartsomme = 0;
		moyenne = somme[i] / double(e.size());
		moyennes.push_back(moyenne);
		for (size_t j = 0; j < e.size(); j++) {
			ecartsomme += pow((valeurAttribut[j][i] - moyenne), 2);
		}
		ecarttype = sqrt(ecartsomme / double(e.size()));
		ecartTypes.push_back(ecarttype);
	}
	delete somme;
	delete valeurAttribut;
}
*/
