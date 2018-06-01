#ifndef ANALYSE_H
#define ANALYSE_H

#include <map>
using std::map;

#include "Reglages.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "GestionMaladies.h"

typedef map<const Maladie*, double> mapMaladie;

class Analyse
{
private:
	Analyse(const Analyse&) = delete;
	Analyse &operator=(const Analyse&) = delete;
	
protected:
	vector<mapMaladie> resultats;
	
public:
	Analyse(const vector<Empreinte*>& empreintes);
	~Analyse() = default;
	
	const vector<mapMaladie>& Resultats() const;
	
	void Afficher(const Attributs& attributs, const vector<Empreinte*> &empreintes) const;
};

inline const vector<mapMaladie>& Analyse::Resultats() const {
	return resultats;
}

void EffectuerAnalyse(mapMaladie& resultat, const Empreinte& empreinte);

#endif // ANALYSE_H