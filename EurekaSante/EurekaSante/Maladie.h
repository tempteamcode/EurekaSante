#ifndef MALADIE_H
#define MALADIE_H

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------

//--------------------------------------------------- Interfaces utilis�es

#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <map>
using namespace std;
#include <math.h>

#include "Reglages.h"
#include "Attributs.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef map<string, int> freqAttr;
//------------------------------------------------------------------------
// R�le de la classe <Maladie>
//
//
//------------------------------------------------------------------------
class Empreinte;
class Maladie
{
	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Attributs prot�g�s
	//----------------------------------------------------- M�thodes prot�g�es
	vector<double> ecartTypes;
	vector<double> moyennes;
	vector<freqAttr>frequenceAttributString;
	string nom;
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Maladie(const string& nom);
	virtual ~Maladie();
	void Afficher(const Attributs& attributs) const;
	void CalculerCaracteristiques(const vector<Empreinte*> &e);
	
	friend vector<Maladie> EffectuerAnalyse(const Empreinte& empreinte);
};
//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>

#endif // EMPREINTE_H