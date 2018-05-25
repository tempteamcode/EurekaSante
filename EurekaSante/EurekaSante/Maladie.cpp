#include "Maladie.h"



Maladie::Maladie(const string& nom)
{
	this->nom = nom;
}


Maladie::~Maladie()
{
}

void Maladie::CalculerCaracteristiques(const vector<Empreinte*> &e) {
	vector<Empreinte*>::const_iterator itE;
	vector<string>::const_iterator itS;
	vector<double>::const_iterator itD;
	freqAttr::iterator itM;
	map<string, int>* m;
	double moyenne = 0.0;
	double ecarttype = 0.0;
	double ecartsomme = 0.0;
	int size = e.at(0)->attributsDouble.size();
	double* somme = new double[size];
	double** valeurAttribut;
	valeurAttribut = new double*[e.size];
	for (int i = 0; i < e.size; i++) {
		valeurAttribut[i] = new double[size];
	}
	int indicesomme = 0;
	int positionitS;
	int positionitD;
	int indiceEmpreinte = 0;
	for (int j = 0; j < size; j++) {
		somme[j] = 0;
	}
	Empreinte* pointeurE;
	for (itE = e.cbegin(); itE != e.cend(); ++itE) {
		pointeurE = *itE;
		positionitS = 0;
		positionitD = 0;
		indicesomme = 0;
		for (itS = pointeurE->attributsString.cbegin(); itS != pointeurE->attributsString.cend(); ++itS) {
			m = &(frequenceAttributString.at(positionitS));
			itM = m->find(*itS);
			if (itM != m->end()) {
				itM->second++;
			}
			else {
				m->insert(make_pair(*itS, 1));
			}
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
		moyenne = somme[i] / (e.size);
		moyennes.push_back(moyenne);
		for (int j = 0; j < e.size; j++) {
			ecartsomme += pow((valeurAttribut[j][i]-moyenne) , 2);
		}
		ecarttype = sqrt(ecartsomme / e.size);
		ecartTypesDouble.push_back(ecartsomme);
	}
	delete somme;
	delete valeurAttribut;
}