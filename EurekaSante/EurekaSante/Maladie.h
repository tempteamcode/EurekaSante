#ifndef MALADIE_H
#define MALADIE_H

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------

//--------------------------------------------------- Interfaces utilisées

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
// Rôle de la classe <Maladie>
//
//
//------------------------------------------------------------------------
class Empreinte;
class Maladie
{
	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Attributs protégés
	//----------------------------------------------------- Méthodes protégées
	vector<double> ecartTypes;
	vector<double> moyennes;
	vector<freqAttr>frequenceAttributString;
	string nom;
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Maladie(const string& nom);
	virtual ~Maladie();
	void Afficher(const Attributs& attributs) const;
	void CalculerCaracteristiques(const vector<Empreinte*> &e);
	
	friend vector<Maladie> EffectuerAnalyse(const Empreinte& empreinte);
};
//-------------------------------- Autres définitions dépendantes de <Empreinte>

#endif // EMPREINTE_H