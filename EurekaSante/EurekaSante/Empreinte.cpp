#include "Empreinte.h"

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
Empreinte::Empreinte(int ID)
{
	id = ID;
}


Empreinte::~Empreinte()
{
}

void Empreinte::Afficher(const Attributs& attributs) const {
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

void Empreinte::AjouterMaladie(Maladie* m) {
	mesMaladies.push_back(m);
}

void Empreinte::AjouterDouble(double d) {
	attributsDouble.push_back(d);
}

void Empreinte::AjouterString(string s) {
	attributsString.push_back(s);
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
