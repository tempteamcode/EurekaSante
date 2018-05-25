#pragma once
//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <map>
#include <math.h>
#include "GestionMaladies.h"
#include "Attributs.h"
using namespace std;
//--------------------------------------------------- Interfaces utilis�es

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
	void CalculerCaracteristiques(const vector<Empreinte*> &e);

	friend void AfficherUneMaladie(const Maladie& m, const Attributs& a);
	friend vector<Maladie> EffectuerAnalyse(const Empreinte& empreinte);
};
//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>
#endif // EMPREINTE_H

