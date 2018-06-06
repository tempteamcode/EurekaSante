
#include <unordered_map>
using std::unordered_map;
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::fstream;
using std::ios;
#include <sstream>
using std::istringstream;

#include "GestionFichiers.h"


bool FichierChargerAttributs(const string& path, Attributs& attributs)
{
	fstream fichier; fichier.open(path, ios::in);
	if (!fichier.is_open()) return false;
	
	string data;
	getline(fichier, data); // AttributeName;AttributeType
	getline(fichier, data); // NoID;ID
	
	for (;;) {
		getline(fichier, data);
		if (fichier.fail()) break;
		istringstream line(data);
		
		string nom;
		string type;
		getline(line, nom, CSV_SEPARATOR);
		getline(line, type);
		
		attributs.Ajouter(nom, type);
	}
	
	return true;
}

void FichierDechargerEmpreintes(vector<Empreinte*>& empreintes) {
	for (auto it = empreintes.begin(); it != empreintes.end(); ++it) {
		delete (*it);
	}
	empreintes.clear();
}

void FichierDechargerMaladies(vector<Maladie*>& maladies) {
	for (auto it = maladies.begin(); it != maladies.end(); ++it) {
		delete (*it);
	}
	maladies.clear();
}

bool FichierChargerEmpreintes(const string& path, const Attributs& attributs, vector<Empreinte*>& empreintes)
{
	vector<Maladie*> maladies;
	bool result = FichierChargerEmpreintes(path, attributs, empreintes, maladies);
	FichierDechargerMaladies(maladies);
	return result;
}

bool FichierChargerEmpreintes(const string& path, const Attributs& attributs, vector<Empreinte*>& empreintes, vector<Maladie*>& maladies)
{
	fstream fichier; fichier.open(path, ios::in);
	if (!fichier.is_open()) return false;
	
	string data;
	getline(fichier, data); // NoID;A1;A2;A3;A4;Disease
	bool hasmaladie = (data.find(";Disease") != string::npos);
	
	unordered_map<string, vector<Empreinte*>> liens;
	
	for (;;) {
		getline(fichier, data);
		if (fichier.fail()) break;
		istringstream line(data);
		
		getline(line, data, CSV_SEPARATOR);
		int NoID = stoi(data);
		Empreinte* empreinte = new Empreinte(NoID);
		
		for (uint i = 0; i < attributs.Compte(); i++) {
			string value;
			getline(line, value, CSV_SEPARATOR);
			
			if (attributs.IsDouble(i)) {
				empreinte->AjouterDouble(stod(value));
			} else {
				empreinte->AjouterString(value);
			}
		}
		
		empreintes.push_back(empreinte);
		
		if (hasmaladie) {
			string nommaladie;
			getline(line, nommaladie);
			liens[nommaladie].push_back(empreinte);
		}
	}
	
	if (hasmaladie) {
		for (auto item = liens.begin(); item != liens.end(); ++item) {
			auto& sesempreintes = item->second;
			
			Maladie* maladie = new Maladie(item->first, item->second);
			maladies.push_back(maladie);
			
			for (auto item = sesempreintes.begin(); item != sesempreintes.end(); ++item) {
				(*item)->AjouterMaladie(maladie);
			}
		}
	}

	return true;
}

bool FichierSauverEmpreintes(const string& path, const Attributs& attributs, const vector<Empreinte*>& empreintes, bool overwrite)
{
	fstream fichier; fichier.open(path, ios::out | (overwrite ? ios::trunc : ios::ate));
	if (!fichier.is_open()) return false;
	
	fichier << "NoID";
	for (uint i = 0; i < attributs.Compte(); i++) {
		fichier << attributs.GetName(i);
	}
	fichier << endl;
	
	uint ie = 0;
	for (auto ite = empreintes.cbegin(); ite != empreintes.cend(); ++ite) {
		const Empreinte& e = *(*ite);
		fichier << ie;
		
		uint idouble = 0;
		uint istring = 0;
		for (uint ia = 0; ia < attributs.Compte(); ia++) {
			if (attributs.IsDouble(ia)) {
				fichier << CSV_SEPARATOR << e.AttributsDouble()[idouble++];
			}
			else {
				fichier << CSV_SEPARATOR << e.AttributsString()[istring++];
			}
		}
		
		ie++;
	}
	
	return true;
}



bool FichierAfficherHistorique()
{
	fstream fichier; fichier.open(FILE_HISTORY, ios::in);
	if (!fichier.is_open()) return false;

	string line;
	for (;;) {
		getline(fichier, line);
		if (fichier.fail()) break;
		cout << line << endl;
	}
	
	return true;
}

bool FichierAjouterHistorique(const vector<string>& contenu)
{
	fstream fichier; fichier.open(FILE_HISTORY, ios::app | ios::ate);
	if (!fichier.is_open()) return false;

	for (auto it = contenu.cbegin(); it != contenu.cend(); ++it) {
		fichier << (*it) << endl;
	}

	return true;
}
