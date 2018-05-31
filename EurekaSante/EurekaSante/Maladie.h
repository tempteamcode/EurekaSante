#ifndef MALADIE_H
#define MALADIE_H

#include <map>
using std::map;

#include "Reglages.h"
#include "Attributs.h"
class Empreinte;


class Maladie
{
private:
	Maladie(const Maladie&) = delete;
	Maladie &operator=(const Maladie&) = delete;
	
	friend vector<const Maladie*> EffectuerAnalyse(const Empreinte& empreinte);
	
protected:
	vector<double> ecartTypes;
	vector<double> moyennes;
	vector<map<string, int>> frequences;
	string nom;
	
public:
	Maladie(const string& nom, const vector<Empreinte*> &empreintes);
	~Maladie() = default;

	void Afficher(const Attributs& attributs) const;
};

#endif // EMPREINTE_H