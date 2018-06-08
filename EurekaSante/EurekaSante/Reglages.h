#ifndef REGLAGES_H
#define REGLAGES_H


#include <vector>
#include <string>
using std::vector;
using std::string;

// #define DEV // A SUPPRIMER DANS LA VERSION CLIENT

typedef unsigned int uint;

const char CSV_SEPARATOR = ';';

const string FILE_HISTORY = "Historique.txt";
const string FILE_ATTRIBUTS = "HealthMeasurementDescription.txt"; // "C:\\Temp\\bcpdm.csvattr";
const string FILE_EMPREINTESMALADIES = "HealthMeasurementsWithLabels.txt";  // "C:\\Temp\\bcpdm.csv";

/*
#include <string>
using std::string;
#include <sstream>
using std::istringstream;

inline istringstream fromString(const string& data)
{
	return istringstream(data);
}
*/

#endif // REGLAGES_H