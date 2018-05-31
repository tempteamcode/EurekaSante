#ifndef MALADIE_H
#define MALADIE_H

#include <map>
using std::map;

#include "Reglages.h"
#include "Attributs.h"
class Empreinte;


class Maladie
{
protected:
	vector<double> ecartTypes;
	vector<double> moyennes;
	vector<map<string, int>> frequences;
	string nom;
	
public:
	void Afficher(const Attributs& attributs) const;
	
	Maladie(const string& nom, const vector<Empreinte*> &empreintes);
	virtual ~Maladie();
	
	friend vector<const Maladie*> EffectuerAnalyse(const Empreinte& empreinte);
};

#endif // EMPREINTE_H