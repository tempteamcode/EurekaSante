#include "Empreinte.h"

//---------- R�alisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- M�thodes publiques
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

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
