#ifndef REGLAGES_H
#define REGLAGES_H

#include <vector>
#include <string>
using std::vector;
using std::string;

//#define DEV

typedef unsigned int uint;

const char CSV_SEPARATOR = ';';

const string FILE_HISTORY = "Historique.txt";
const string FILE_ATTRIBUTS = "HealthMeasurementDescription.txt";
const string FILE_EMPREINTESMALADIES = "HealthMeasurementsWithLabels.txt";

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