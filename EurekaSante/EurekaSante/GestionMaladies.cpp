
#include <iostream>
using std::cout;
using std::endl;

#include "GestionMaladies.h"

vector<const Maladie*> maladiesConnues;

void MaladiesConnues(vector<Maladie*> maladies) {
	maladiesConnues.resize(maladies.size());
	
	auto cit = maladiesConnues.begin();
	for (auto it = maladies.cbegin(); it != maladies.cend(); ++it, ++cit) {
		*cit = *it;
	}
}

void AfficherMaladiesConnues(const Attributs& attributs) {
	for (auto cit = maladiesConnues.cbegin(); cit != maladiesConnues.cend(); ++cit) {
		const Maladie& m = *(*cit);
		m.Afficher(attributs);
	}
}
