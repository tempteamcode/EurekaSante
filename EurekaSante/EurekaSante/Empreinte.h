#pragma once
//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define EMPREINTE_H
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Empreinet>
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
class Empreinte
{
	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Attributs protégés
	//----------------------------------------------------- Méthodes protégées
	vector<attributString> attributsString;
	vector<attributDouble> attributsDouble;
	
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Empreinte();
	virtual ~Empreinte();
	void Afficher();
};
//-------------------------------- Autres définitions dépendantes de <Empreinte>
#endif // EMPREINTE_H
