#ifndef EMPREINTE_H
#define EMPREINTE_H

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------

//--------------------------------------------------- Interfaces utilisées

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Reglages.h"
#include "Attributs.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Maladie;

//------------------------------------------------------------------------
// Rôle de la classe <Empreinte>
//
//
//------------------------------------------------------------------------
class Empreinte
{
	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Attributs protégés
	//----------------------------------------------------- Méthodes protégées
	vector<string> attributsString;
	vector<double> attributsDouble;
	int id;
	vector<Maladie*> mesMaladies;
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	//-------------------------------------------- Constructeurs - destructeur
	Empreinte(int ID);
	virtual ~Empreinte();
	void Afficher(const Attributs& attributs) const;
	void AjouterMaladie(Maladie* m);
	void AjouterString(const string& s);
	void AjouterDouble(double d);

	friend class Maladie;
	friend vector<Maladie> EffectuerAnalyse(const Empreinte& empreinte);
};
//-------------------------------- Autres définitions dépendantes de <Empreinte>

inline void Empreinte::AjouterMaladie(Maladie* m) {
	mesMaladies.push_back(m);
}

inline void Empreinte::AjouterDouble(double d) {
	attributsDouble.push_back(d);
}

inline void Empreinte::AjouterString(const string& s) {
	attributsString.push_back(s);
}

#endif // EMPREINTE_H