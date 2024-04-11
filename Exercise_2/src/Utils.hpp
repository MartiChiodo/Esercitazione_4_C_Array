#ifndef __UTILS_H // Header guards
#define __UTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

namespace UtilsLibrary{

//procedura per stampare gli array
void stampa_array(ofstream& file, double* array, int size);

//funzione per calcolarmi il rate of return totale
double rate_of_return(double* w, double* r, int size);

//funzione per calcolarmi il valore finale del portfolio V
double valore_finale_portfolio(double* w, double* r, const double& somma_iniziale, int size);

}


#endif
