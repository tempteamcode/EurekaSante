
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ios;

#include "Tests.h"


extern Attributs attributs;
vector<Empreinte*> empreintes;
vector<Empreinte*> empreintesTest;
vector<Maladie*> maladies;


#include <cstdlib>
#include <ctime>
#define randBool() bool((std::rand()%2) == 1)
#define randDouble() ((std::rand()/double(RAND_MAX)) * 300 - 100)
#define randInt(range) (std::rand() % range)
#define randString(range) char('A' + randInt(range))

// Critères SCUTU :
// 10 Millions d'empreintes
// 100 Caractéristiques
bool FichierGenererEmpreintesAleatoires(const string& path, uint nbEmpreintes, uint nbAttributs, uint nbMaladies)
{
	fstream fichier; fichier.open(path, ios::out | ios::trunc);
	if (!fichier.is_open()) return false;
	
	std::srand(uint(std::time(nullptr)));
	
	fstream fichiera; fichiera.open(path + "attr", ios::out | ios::trunc);
	if (!fichiera.is_open()) return false;
	
	fichier << "NoID";
	
	fichiera << "AttributeName;AttributeType" << endl;
	fichiera << "NoID;ID" << endl;
	vector<int> IsDouble; IsDouble.resize(nbAttributs);
	for (uint ia = 0; ia < nbAttributs; ia++) {
		fichiera << 'A' << (ia + 1) << ';' << ((IsDouble[ia] = randBool()) ? "double" : "string") << endl;
		fichier << ";A" << (ia + 1);
	}
	if (nbMaladies > 0) fichier << ";Disease";
	fichier << endl;
	
	fichiera.close();
	
	for (uint i = 0; i < nbEmpreintes; i++) {
		fichier << i;
		
		for (uint ia = 0; ia < nbAttributs; ia++) {
			if (IsDouble[ia])
				fichier << ';' << randDouble();
			else
				fichier << ';' << randString(5);
		}
		
		if (nbMaladies > 0) {
			fichier << ';';
			int im = randInt(nbMaladies);
			if (im > 0) fichier << 'M' << im;
		}
		fichier << endl;
	}

	return true;
}

bool testFichierChargerAttributs(bool display)
{
	if (!FichierChargerAttributs(FILE_ATTRIBUTS, attributs)) {
		cerr << "Erreur lors du chargement des attributs !" << endl;
		return false;
	}
	
	if (display) {
		attributs.Afficher();
	}
	
	return true;
}

bool testFichierChargerEmpreintesMaladies(bool display)
{
	if (!testFichierChargerAttributs(false)) return false;
	
	if (!FichierChargerEmpreintes(FILE_EMPREINTESMALADIES, attributs, empreintes, maladies)) {
		cerr << "Erreur lors du chargement des empreintes+maladies !" << endl;
		return false;
	}
	
	if (display) {
		for (auto item = empreintes.cbegin(); item != empreintes.cend(); ++item) {
			(*item)->Afficher(attributs);
		}
		for (auto item = maladies.cbegin(); item != maladies.cend(); ++item) {
			(*item)->Afficher(attributs);
		}
	}
	
	return true;
}

bool testAfficherMaladiesConnues(bool display)
{
	if (!testFichierChargerEmpreintesMaladies(false)) return false;

	MaladiesConnues(maladies);

	if (display) {
		AfficherMaladiesConnues(attributs);
	}

	return true;
}

bool testEffectuerAnalyse(bool display)
{
	if (!testAfficherMaladiesConnues(false)) return false;
	
	if (!FichierChargerEmpreintes("Test4Empreintes.txt", attributs, empreintesTest)) {
		cerr << "Erreur lors du chargement des empreintes !" << endl;
		return false;
	}
	
	Analyse analyse(empreintesTest);
	
	if (display) {
		analyse.Afficher(attributs, empreintesTest);
	}
	
	return true;
}

bool testEffectuerAnalyses(bool display)
{
	if (!testAfficherMaladiesConnues(false)) return false;

	if (!FichierChargerEmpreintes(FILE_EMPREINTESMALADIES, attributs, empreintesTest)) {
		cerr << "Erreur lors du chargement des empreintes !" << endl;
		return false;
	}
	
	Analyse analyse(empreintesTest);
	
	const vector<mapMaladie>& resultats = analyse.Resultats();
	
	int comptejuste = 0;
	
	for (uint ie = 0; ie < empreintes.size(); ie++) {
		const Maladie * identifie = nullptr;
		double pourcentage = 0.0;

		const mapMaladie& resultat = resultats[ie];
		for (auto it = resultat.cbegin(); it != resultat.cend(); ++it) {
			if (it->second > pourcentage) {
				identifie = it->first;
				pourcentage = it->second;
			}
		}
		
		const vector<const Maladie *> maladies = empreintes[ie]->Maladies();
		if (std::find(maladies.cbegin(), maladies.cend(), identifie) != maladies.cend())
			comptejuste++;
	}
	
	if (display) {
		cout << "Identifications correctes : " << comptejuste << "/" << empreintes.size() << ", soit un taux de reussite de " << comptejuste*100/double(empreintes.size()) << '%' << endl;
	}
	
	return true;
}
