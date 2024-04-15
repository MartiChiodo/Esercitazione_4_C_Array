#ifndef __UTILS_H // Header guards
#define __UTILS_H


#include <string>

using namespace std;

namespace UtilsLibrary{

//funzione che mi legge da file i dati necessari
bool ImportData(const string& nameFile, size_t& n, double& S, double*& w, double*& r);

//procedura per convertire gli array in stringhe stampabili
string array_to_stringa(const double* const& array, const size_t& size);

//funzione per calcolarmi il rate of return totale
double rate_of_return(const double* const& w, const double* const& r, const size_t& size);

//funzione per calcolarmi il valore finale del portfolio V
double valore_finale_portfolio(const double* const& w, const double* const& r, const double& somma_iniziale, const size_t& size);

}


#endif
