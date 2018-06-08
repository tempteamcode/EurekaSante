
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ios;
using std::cin;

#include "Tests.h"


extern Attributs attributs;
vector<Empreinte*> empreintes;
vector<Empreinte*> empreintesTest;
vector<Maladie*> maladies;


#define randBool() bool((std::rand()%2) == 1)
#define randDouble() ((std::rand()/double(RAND_MAX)) * 300 - 100)
#define randInt(range) (std::rand() % range)
#define randString(range) char('A' + randInt(range))

bool FichierGenererEmpreintesAleatoires(const string& path, uint nbEmpreintes, uint nbAttributs, uint nbMaladies)
{
	fstream fichier; fichier.open(path, ios::out | ios::trunc);
	if (!fichier.is_open()) return false;
	
	std::srand(uint(std::time(nullptr)));
	
	fstream fichiera; fichiera.open(path + "_attr", ios::out | ios::trunc);
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

bool testFichierChargerAttributs(bool display, const string& path)
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

bool testFichierChargerEmpreintesMaladies(bool display, const string& path)
{
	if (!testFichierChargerAttributs(false)) return false;
	
	if (!FichierChargerEmpreintes(path, attributs, empreintes, maladies)) {
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

void testEffectuerStatistiques_(bool display);
bool testEffectuerStatistiques(bool display, const string& path)
{
	if (!testAfficherMaladiesConnues(false)) return false;
	
	if (!FichierChargerEmpreintes(path, attributs, empreintesTest)) {
		cerr << "Erreur lors du chargement des empreintes !" << endl;
		return false;
	}
	
	testEffectuerStatistiques_(display);
	
	return true;
}
void testEffectuerStatistiques_(bool display)
{
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
		cout << "Identifications correctes : " << comptejuste << "/" << empreintes.size() << ", soit un taux de reussite de " << comptejuste * 100 / double(empreintes.size()) << '%' << endl;
	}
}

bool testDuree(bool display)
{
	string nbEmpreintesStr;
	cout << "Nombre d'empreintes : ";
	cin >> nbEmpreintesStr;
	string nbAttrStr;
	cout << "Attributs : ";
	cin >> nbAttrStr;
	string nbMaladiesStr;
	cout << "Maladies : ";
	cin >> nbMaladiesStr;
	cout << endl;
	if (FichierGenererEmpreintesAleatoires("bcpdm.csv", stoi(nbEmpreintesStr), stoi(nbAttrStr), stoi(nbMaladiesStr))){
		cout << "Empreintes generees dans 'bcpdm.csv'." << endl;
	} else {
		cerr << "Erreur d'ecriture d'empreintes dans 'bcpdm.csv'." << endl;
		return false;
	}
	
	if (FichierChargerAttributs("bcpdm.csv_attr", attributs) &&
		FichierChargerEmpreintes("bcpdm.csv", attributs, empreintes, maladies)) {
		cout << "Attributs+empreintes+maladies lues." << endl;
	} else {
		cerr << "Erreur lors du chargement des attributs+empreintes+maladies !" << endl;
		return false;
	}
	
	empreintesTest = empreintes;
	MaladiesConnues(maladies);
	
	
	double duration;
	std::clock_t start; start = std::clock();
	testEffectuerStatistiques_(display);
	duration = (std::clock() - start) / double(CLOCKS_PER_SEC);
	
	if (display) {
		cout << "Duree de l'analyse : " << duration << " secondes." << endl;
	}
	
	return true;
}


bool testChronometrer(bool (*fn) (bool), bool display)
{
	bool reussite;
	
	double duration;
	std::clock_t start; start = std::clock();
	reussite = fn(display);
	duration = (std::clock() - start) / double(CLOCKS_PER_SEC);
	
	if (reussite && display) {
		cout << "Duree du test : " << duration << " secondes." << endl;
	}
	
	return reussite;
}
