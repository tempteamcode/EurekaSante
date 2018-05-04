#pragma once
//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define EMPREINTE_H
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Empreinet>
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
	//----------------------------------------------------- Attributs prot�g�s
	//----------------------------------------------------- M�thodes prot�g�es
	vector<attributString> attributsString;
	vector<attributDouble> attributsDouble;
	
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Empreinte();
	virtual ~Empreinte();
	void Afficher();
};
//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>
#endif // EMPREINTE_H
