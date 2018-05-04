#pragma once
//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <map>
#include "EMpreinte.h"
using namespace std;
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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
	vector<double> ecartTypesDOuble;
	vector<double> moyennes;
	vector<map<string, int>> frequenceAttributString;
	string nom;
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Maladie();
	virtual ~Maladie();
	void calculerCaracteristiques(const vector<Empreinte*> &e);

	friend class Empreinte;
};
//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>
#endif // EMPREINTE_H

