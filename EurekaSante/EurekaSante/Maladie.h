#ifndef MALADIE_H
#define MALADIE_H

#include <map>
using std::map;

#include "Reglages.h"
#include "Attributs.h"
class Empreinte;


typedef map<string, double> freqAttr;

class Maladie
{
private:
	Maladie(const Maladie&) = delete;
	Maladie &operator=(const Maladie&) = delete;
	
protected:
	vector<double> ecartTypes;
	vector<double> moyennes;
	vector<freqAttr> frequences;
	string nom;
	
public:
	Maladie(const string& nom, const vector<Empreinte*> &empreintes);
	~Maladie() = default;
	
	const vector<double>& Maladie::EcartTypes() const;
	const vector<double>& Maladie::Moyennes() const;
	const vector<freqAttr>& Maladie::Frequences() const;
	
	void Afficher(const Attributs& attributs) const;
};

inline const vector<double>& Maladie::EcartTypes() const {
	return ecartTypes;
}
inline const vector<double>& Maladie::Moyennes() const {
	return moyennes;
}
inline const vector<freqAttr>& Maladie::Frequences() const {
	return frequences;
}

#endif // EMPREINTE_H