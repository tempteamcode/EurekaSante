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

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
