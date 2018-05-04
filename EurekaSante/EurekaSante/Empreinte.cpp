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
	vector<attributString>::iterator itS;
	vector<attributDouble>::iterator itD;
	for (itS = attributsString.begin(); itS != attributsString.end(); ++itS) {
		cout << itS->nom << " : "<< itS->valeur << ",";
	}
	for (itD = attributsDouble.begin(); itD != attributsDouble.end(); ++itD) {
		cout << itD->nom << " : " << itD->valeur << ",";
	}
	cout << endl;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
