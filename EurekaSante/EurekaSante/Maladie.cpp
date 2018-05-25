#include "Maladie.h"



Maladie::Maladie()
{
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
	int size = e.at(0)->attributsDouble.size();
	double* somme = new double[size];
	Empreinte* pointeurE;
	//
	for (itE = e.cbegin(); itE != e.cend(); ++itE) {
		pointeurE = *itE;
		int positionitS = 0;
		int positionitD = 0;
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

		}
	}
	delete somme;
}