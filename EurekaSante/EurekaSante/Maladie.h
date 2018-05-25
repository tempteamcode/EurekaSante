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
#include "Empreinte.h"
using namespace std;
//--------------------------------------------------- Interfaces utilisées

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
	vector<double> ecartTypesDouble;
	vector<double> moyennes;
	vector<freqAttr>frequenceAttributString;
	string nom;
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Maladie(const string& nom);
	virtual ~Maladie();
	void CalculerCaracteristiques(const vector<Empreinte*> &e);

	friend class Empreinte;
	friend void AfficherMaladie(Maladie m);
};
//-------------------------------- Autres définitions dépendantes de <Empreinte>
#endif // EMPREINTE_H

