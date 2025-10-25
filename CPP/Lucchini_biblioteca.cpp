// LUCCHINI ALBERTO

#include <iostream>
#include <iomanip>

using namespace std;

int personaCercata;
string libroCercato;

const int DIM = 3;

struct libri{
    struct codiceLibro{
        string isbn[20];
        int id;
    }cLibro;

    string titolo[60];

    string autore;

    struct annoPub{
        int mese;
        int anno;
    } aPub;

    struct  Editore{
        string sede[40];
        string cEd[40];
    } genitore1;
};

int menu();

int main(){

    return 0;
}

int menu(){
    int scelta;

    cout << "MENU'" << endl;
    cout << "1. Aggiungi nuovo libro\n";
    cout << "2. Cerca libro tramite ISBN o ID\n";
    cout << "3. Cerca libro per autore\n";
    cout << "4. Visualizza collezione\n";
    cout << "0. Uscita\n";
    cout << "Inserisci la tua scelta: ";
    cin >> scelta;

    return scelta;
}