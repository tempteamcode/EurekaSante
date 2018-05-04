#pragma once
//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define EMPREINTE_H
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include "Maladie.h"
using namespace std;
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Empreinet>
//
//
//------------------------------------------------------------------------
class Maladie;
class Empreinte
{
	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Attributs prot�g�s
	//----------------------------------------------------- M�thodes prot�g�es
	vector<string> attributsString;
	vector<double> attributsDouble;
	int id;
	vector<Maladie*> mesMaladies;
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Empreinte(int ID);
	virtual ~Empreinte();
	void Afficher() const;
	void AjouterMaladie(Maladie* m);
	void AjouterString(string s);
	void AjouterDouble(double d);

	friend class Maladie;
};
//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>
#endif // EMPREINTE_H
