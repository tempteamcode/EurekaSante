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

void Empreinte::Afficher() const {
	vector<string>::const_iterator itS;
	vector<double>::const_iterator itD;
	for (itS = attributsString.cbegin(); itS != attributsString.cend(); ++itS) {
		cout << itS << ";";
	}
	for (itD = attributsDouble.cbegin(); itD != attributsDouble.cend(); ++itD) {
		cout << itD << ";";
	}
	cout << endl;
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
