#include "Empreinte.h"

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using std::cout;
using std::endl;

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

Empreinte::Empreinte(int ID)
{
	id = ID;
}

void Empreinte::Afficher(const Attributs& attributs) const
{
	uint istring = 0;
	uint idouble = 0;

	for (uint i = 0; i < attributs.Compte(); i++) {
		cout << attributs.GetName(i) << ":";
		if (attributs.IsDouble(i)) {
			cout << attributsDouble[idouble++];
		}
		else {
			cout << attributsString[istring++];
		}
		cout << ";";
	}
	cout << endl;
}

Empreinte::~Empreinte()
{
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
