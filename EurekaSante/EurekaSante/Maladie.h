#pragma once
//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Maladie>
//
//
//------------------------------------------------------------------------
struct ecartType {
	string nom;
	double valeur;
};
struct moyenne {
	string nom;
	double valeur;
};
class Maladie
{
	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Attributs protégés
	//----------------------------------------------------- Méthodes protégées
	vector<ecartType> ecartTypes;

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Maladie();
	virtual ~Maladie();
};
//-------------------------------- Autres définitions dépendantes de <Empreinte>
#endif // EMPREINTE_H

