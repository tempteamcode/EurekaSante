#pragma once
//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H
#include <string>
#include <iostream>
using namespace std;
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Maladie>
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
	//----------------------------------------------------- Attributs prot�g�s
	//----------------------------------------------------- M�thodes prot�g�es
	

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Maladie();
	virtual ~Maladie();
};
//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>
#endif // EMPREINTE_H

