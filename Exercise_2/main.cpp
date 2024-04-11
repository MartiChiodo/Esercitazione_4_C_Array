#include "src/Utils.hpp"

int main()
{
    //leggo da file le informazioni necessarie: assumo che il file sia scritto nel giusto formato
    string fileNameI = "data.csv";
    ifstream ifs(fileNameI);
    string fileNameO = "result.txt";
    ofstream ofs(fileNameO);

    if (ifs.fail()){
        cerr << "Error opening the input file" << endl;
        return 1;
    }
    if (ofs.fail()){
        cerr << "Error opening the output file" << endl;
        return 1;
    }

    double S;
    string headerS;
    getline(ifs, headerS);
    size_t pos = headerS.find(';'); // Trova la posizione del punto e virgola
    string S_str = headerS.substr(pos + 1);
    S = stod(S_str); // Converti la seconda parte in double
    ofs << fixed << setprecision(2) <<  "S = " << S << ", "; //i primi due output mi servono per stampare S nel formato richiesto

    int n;
    string headern;
    getline(ifs, headern);
    pos = headern.find(';'); // Trova la posizione del punto e virgola
    string n_str = headern.substr(pos + 1);
    n = stod(n_str); // Converti la seconda parte in double
    ofs << fixed << setprecision(2) <<  "n = " << n << endl; //i primi due output mi servono per stampare S nel formato richiesto

    //salto una riga
    string str;
    getline(ifs, str);

    //creo i due array in memoria dinamica
    double* w = new double[n];
    double* r = new double[n];
    int contatore = 0;

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

    //stampo i due array in output
    ofs << "w = ";
    UtilsLibrary::stampa_array(ofs, w, n);
    ofs << endl;

    ofs << "r = ";
    UtilsLibrary::stampa_array(ofs, r, n);
    ofs << endl;

    ofs << "Rate of return of the portfolio: " << setprecision(4) <<  UtilsLibrary::rate_of_return(w,r,n) << endl;
    ofs << "V: " << fixed << setprecision(2) << UtilsLibrary::valore_finale_portfolio(w,r,S,n) << endl;


    ifs.close();
    ofs.close();

  return 0;
}

