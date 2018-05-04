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

void Empreinte::Afficher() const {
	vector<string>::const_iterator itS;
	vector<double>::const_iterator itD;
	for (itS = attributsString.cbegin(); itS != attributsString.cend(); ++itS) {
		cout << *itS << ";";
	}
	for (itD = attributsDouble.cbegin(); itD != attributsDouble.cend(); ++itD) {
		cout << *itD << ";";
	}
	cout << endl;
}

void Empreinte::AjouterMaladie(Maladie* m) {
	mesMaladies.push_back(m);
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
