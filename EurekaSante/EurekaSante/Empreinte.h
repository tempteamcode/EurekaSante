#pragma once
//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define EMPREINTE_H
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;
class Maladie;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Empreinte>
//
//
//------------------------------------------------------------------------
class Empreinte
{
	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Attributs protégés
	//----------------------------------------------------- Méthodes protégées
	vector<string> attributsString;
	vector<double> attributsDouble;
	int id;
	vector<Maladie*> mesMaladies;
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Empreinte(int ID);
	virtual ~Empreinte();
	void Afficher() const;
	void AjouterMaladie(Maladie* m);
	void AjouterString(string s);
	void AjouterDouble(double d);

	friend class Maladie;
};
//-------------------------------- Autres définitions dépendantes de <Empreinte>
#endif // EMPREINTE_H
