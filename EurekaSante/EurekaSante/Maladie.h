#pragma once
//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H
#include <string>
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
struct attributString {
	string nom;
	string valeur;
};
struct attributDouble {
	string nom;
	double valeur;
};
class Maladie
{
	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Attributs protégés
	//----------------------------------------------------- Méthodes protégées
	

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Maladie();
	virtual ~Maladie();
};
//-------------------------------- Autres définitions dépendantes de <Empreinte>
#endif // EMPREINTE_H

