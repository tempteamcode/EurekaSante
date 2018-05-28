#include "Maladie.h"
#include "Empreinte.h"


Maladie::Maladie(const string& nom)
: nom (nom)
{
}

Maladie::~Maladie()
{
}

void Maladie::Afficher(const Attributs& a) const
{
	cout << "Maladie : " << nom << endl;
	
	uint istring = 0;
	uint idouble = 0;
	for (uint i = 0; i < a.Compte(); i++) {
		cout << "Attribut " << a.GetName(i) << " :" << endl;
		
		if (a.IsDouble(i)) {
			cout << "  Moyenne : " << moyennes[idouble] << " ";
			cout << "Ecart type : " << ecartTypes[idouble] << endl;
			idouble++;
		}
		else {
			const auto& fmap = frequenceAttributString[istring];
			for (freqAttr::const_iterator itMap = fmap.cbegin(); itMap != fmap.cend(); ++itMap) {
				cout << "  Valeur : \"" << itMap->first << "\" ";
				cout << "Fréquence : " << itMap->second << endl;
			}
			istring++;
		}
	}
}

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
	/*cout << "start" << endl;
	for (size_t i = 0; i < e.size(); i++) {
		for (int j = 0; j < size; j++) {
			cout << valeurAttribut[i][j] << " ";
		}
		cout << endl;
	}
	cout << "end" << endl;*/
	for (int i = 0; i < size; i++) {
		ecartsomme = 0;
		moyenne = somme[i] / double(e.size());
		moyennes.push_back(moyenne);
		for (size_t j = 0; j < e.size(); j++) {
			ecartsomme += pow((valeurAttribut[j][i]-moyenne) , 2);
		}
		ecarttype = sqrt(ecartsomme / double(e.size()));
		ecartTypes.push_back(ecarttype);
	}
	delete somme;
	delete valeurAttribut;
}
