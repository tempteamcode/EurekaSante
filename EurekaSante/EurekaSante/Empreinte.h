#ifndef EMPREINTE_H
#define EMPREINTE_H

#include "Reglages.h"
#include "Attributs.h"
class Maladie;


class Empreinte
{
private:
	Empreinte(const Empreinte&) = delete;
	Empreinte &operator=(const Empreinte&) = delete;
	
protected:
	int id;
	vector<string> attributsString;
	vector<double> attributsDouble;
	vector<const Maladie*> maladies;
	
public:
	Empreinte(int ID);
	~Empreinte() = default;
	
	void Afficher(const Attributs& attributs) const;
	
	const vector<string>& Empreinte::AttributsString() const;
	const vector<double>& Empreinte::AttributsDouble() const;
	const vector<const Maladie*>& Empreinte::Maladies() const;

	void AjouterMaladie(const Maladie* m);
	void AjouterString(const string& s);
	void AjouterDouble(double d);
};

inline const vector<const Maladie*>& Empreinte::Maladies() const {
	return maladies;
}
inline const vector<string>& Empreinte::AttributsString() const {
	return attributsString;
}
inline const vector<double>& Empreinte::AttributsDouble() const {
	return attributsDouble;
}

inline void Empreinte::AjouterMaladie(const Maladie* m) {
	maladies.push_back(m);
}
inline void Empreinte::AjouterString(const string& s) {
	attributsString.push_back(s);
}
inline void Empreinte::AjouterDouble(double d) {
	attributsDouble.push_back(d);
}

#endif // EMPREINTE_H