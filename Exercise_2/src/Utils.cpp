#include "Utils.hpp"

namespace UtilsLibrary{

//procedura per stampare gli array
void stampa_array(ofstream& file, double* array, int size) {
    file << "[";
    for (int i=0; i<size; i++){
        file << *(array + i) << " " ;
    }
    file << "]";
}

//funzione per calcolarmi il rate of return totale
double rate_of_return(double* w, double* r, int size){
    //si vuole scrivere la relazione V = sum( (1+r[i])*w[i]*S ) come V = (1+rate_of_return)S
    // si deduce dunque che sum((1+r[i])*w[i]) deve essere scritto come 1 + rate_of_return
    // sviluppando l'espressione si ottiene rate_of_return = sum(r[i]*w[i]) considerando che le w[i] sommano a 1
    double val = 0;
    for (int i = 0; i<size; i++){
        val += *(w+i) * *(r+i);
    }
    return val;
}

//funzione per calcolarmi il valore finale del portfolio V
double valore_finale_portfolio(double* w, double* r, const double &somma_iniziale, int size){
    double val = 0;
    for(int i =0; i<size; i++){
        val += (1 + *(r+i)) * (*(w+i)) * somma_iniziale;
    }
    return val;
}


}
