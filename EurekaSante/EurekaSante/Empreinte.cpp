#include "Empreinte.h"

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
Empreinte::Empreinte()
{
}


Empreinte::~Empreinte()
{
}

void Empreinte::Afficher() {
	vector<string>::iterator itS;
	vector<double>::iterator itD;
	for (itS = attributsString.begin(); itS != attributsString.end(); ++itS) {
		cout << *itS << ",";
	}
	for (itD = attributsDouble.begin(); itD != attributsDouble.end(); ++itD) {
		cout << *itD << ",";
	}
	cout << endl;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
