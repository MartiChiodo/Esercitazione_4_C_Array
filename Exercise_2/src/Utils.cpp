#include "Utils.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

namespace UtilsLibrary{

//funzione che mi legge da file i dati necessari
bool ImportData(const string& nameFile, size_t& n, double& S, double*& w, double*& r){
    //apro il file di input
    ifstream ifs(nameFile);
    if (ifs.fail()){
        cerr << "Error opening the input file" << endl;
        return false;
    }

    //assumo che il formato del file sia giusto
    //leggo il valore di S
    string headerS;
    getline(ifs, headerS);
    size_t pos = headerS.find(';'); // Trova la posizione del punto e virgola
    string S_str = headerS.substr(pos + 1);
    S = stod(S_str); // Converti la seconda parte in double

    //leggo la dimensione dei vettori
    string headern;
    getline(ifs, headern);
    pos = headern.find(';'); // Trova la posizione del punto e virgola
    string n_str = headern.substr(pos + 1);
    n = stod(n_str); // Converti la seconda parte in double

    //salto una riga
    string str;
    getline(ifs, str);

    //mi salvo i due vettori w e r
    w = new double[n];
    r = new double[n];
    size_t contatore = 0;

    while (ifs.is_open() && contatore<n){
        string line;
        getline(ifs, line);
        pos = line.find(';'); // Trova la posizione del punto e virgola
        string w_str = line.substr(0, pos); // Estrai la prima parte come stringa
        string r_str = line.substr(pos + 1); // Estrai la seconda parte come stringa

        double wVAL = stod(w_str); // Converti la prima parte in double
        double rVAL = stod(r_str); // Converti la seconda parte in double

        //aggiungo i valori trovati agli array w e r
        w[contatore] = wVAL,
        r[contatore] = rVAL;

        contatore ++;
    }

    ifs.close();
    return true;
}


//procedura per convertire gli array in stringhe stampabili
string array_to_stringa(const double* const& array, const size_t& size) {
    string str;
    ostringstream toString;
    toString << "[ ";
    for (size_t i = 0; i<size; i++){
        toString << array[i] << " ";
    }
    toString << "]";

    return toString.str();
}

//funzione per calcolarmi il rate of return totale
double rate_of_return(const double* const& w, const double* const& r, const size_t& size){
    //si vuole scrivere la relazione V = sum( (1+r[i])*w[i]*S ) come V = (1+rate_of_return)S
    // si deduce dunque che sum((1+r[i])*w[i]) deve essere scritto come 1 + rate_of_return
    // sviluppando l'espressione si ottiene rate_of_return = sum(r[i]*w[i]) considerando che le w[i] sommano a 1
    double val = 0;
    for (size_t i = 0; i<size; i++){
        val += w[i] * r[i];
    }
    return val;
}

//funzione per calcolarmi il valore finale del portfolio V
double valore_finale_portfolio(const double* const& w, const double* const& r, const double& somma_iniziale, const size_t& size){
    double val = 0;
    for(size_t i =0; i<size; i++){
        val += (1 + r[i]) * (w[i]) * somma_iniziale;
    }
    return val;
}


}
