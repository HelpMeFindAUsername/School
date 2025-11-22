//Alberto Lucchini
//Progetto Autosalone
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

const int DIM = 5;
int spazioOcc = 0;


struct Auto{
    string marca;
    int cilindrata;
    int annoImmatricolazione;
    
    struct acquirente{
        string nome;
        string cognome;
        string codiceFiscale;
    } acq;
};

int menu();

void initVettAuto(Auto autosalone[], int dim);

void insAuto(Auto autosalone[], int &dim);
void visCognomi(Auto autosalone[], int dim, int cilindrataMin);
void visAutoPerAnno(Auto autosalone[], int dim, int anno);
void visTabella(Auto autosalone[], int dim);

int main(){
    Auto autosalone[DIM];
    int scelta;
    int anno;
    const int cilindrataMin = 1500;

    initVettAuto(autosalone, DIM);

    do{
        scelta = menu();
        switch(scelta){
            case 1:
                insAuto(autosalone, spazioOcc);
                break;
            case 2:
                visCognomi(autosalone, spazioOcc, cilindrataMin);
                break;
            case 3:
                cout << "Inserisci l'anno di immatricolazione da cercare: ";
                cin >> anno;
                visAutoPerAnno(autosalone, spazioOcc, anno);
                break;
            case 4:
                visTabella(autosalone, spazioOcc);
                break;
            case 0:
                cout << "Uscita in corso...\n";
                break;
            default:
                cout << "Scelta non valida. Riprova.\n";
        }
    }while(scelta != 0);

    return 0;
}

void initVettAuto(Auto autosalone[], int dim){
    for(int i = 0; i < dim; i++){
        autosalone[i].marca = "";
        autosalone[i].cilindrata = 0;
        autosalone[i].annoImmatricolazione = 0;
        autosalone[i].acq.nome = "";
        autosalone[i].acq.cognome = "";
        autosalone[i].acq.codiceFiscale = "";
    }
}

int menu(){
    int scelta;
    system("cls");
    cout << "1. Inserisci auto\n";
    cout << "2. Visualizza o cognome degli acquirenti di auto di cilindrata superiore a 1500 cc\n";
    cout << "3. Visualizza auto immatricolate in un anno specifico\n";
    cout << "4. Visualizza l'intera tabella\n";
    cout << "0. Uscita\n";
    cout << "Inserisci la tua scelta: ";
    cin >> scelta;
    return scelta;
}

void insAuto(Auto autosalone[], int &dim){
    int numAuto;
    cout << "Quante auto vuoi inserire? Max " << DIM - dim << ": ";
    cin >> numAuto;

    while(numAuto > DIM - dim || numAuto < 1){
        cout << "Numero non valido. Inserisci un numero tra 1 e " << DIM - dim << ": ";
        cin >> numAuto;
    }

    int start = dim;
    int end = start + numAuto;
    for(int i = start; i < end; i++){
        cout << "Inserisci la marca dell'auto: ";
        cin >> autosalone[i].marca;
        cout << "Inserisci la cilindrata dell'auto: ";
        cin >> autosalone[i].cilindrata;
        cout << "Inserisci l'anno di immatricolazione dell'auto: ";
        cin >> autosalone[i].annoImmatricolazione;
        cout << "Inserisci il nome dell'acquirente: ";
        cin >> autosalone[i].acq.nome;
        cout << "Inserisci il cognome dell'acquirente: ";
        cin >> autosalone[i].acq.cognome;
        cout << "Inserisci il codice fiscale dell'acquirente: ";
        cin >> autosalone[i].acq.codiceFiscale;
        cout << "Auto " << (i - start + 1) << " inserita con successo!\n";
        cout << "---------------------------\n";
    }

    dim = end; // aggiorna il contatore reale delle auto

    cout << "Tutte le auto sono state inserite. Digita 0 per tornare al menu'... ";
    int temp;
    cin >> temp;
}

void visCognomi(Auto autosalone[], int dim, int cilindrataMin){
    bool t = false;
    system("cls");
    cout << "Auto con cilindrata superiore a " << cilindrataMin << " cc:\n";
    cout << left << setw(15) << "Marca" << setw(12) << "Cilindrata" << setw(8) << "Anno" << setw(15) << "Nome" << setw(15) << "Cognome" << setw(20) << "Cod.Fiscale" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for(int i = 0; i < dim; i++){
        if(autosalone[i].cilindrata > cilindrataMin){
            cout << left << setw(15) << autosalone[i].marca 
                 << setw(12) << autosalone[i].cilindrata 
                 << setw(8) << autosalone[i].annoImmatricolazione 
                 << setw(15) << autosalone[i].acq.nome
                 << setw(15) << autosalone[i].acq.cognome
                 << setw(20) << autosalone[i].acq.codiceFiscale
                 << endl;
            t = true;
        }
    }
    if(!t){
        cout << "\nNessuna auto trovata con cilindrata superiore a " << cilindrataMin << " cc.\n";
    }
    cout << "Digita 0 per tornare al menu'...";
    int temp;
    cin >> temp;
}

void visAutoPerAnno(Auto autosalone[], int dim, int anno){
    bool found = false;
    system("cls");
    cout << "Auto immatricolate nell'anno " << anno << ":\n";
    cout << left << setw(15) << "Marca" << setw(12) << "Cilindrata" << setw(8) << "Anno" << setw(15) << "Nome" << setw(15) << "Cognome" << setw(20) << "Cod.Fiscale" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < dim; i++){
        if(autosalone[i].annoImmatricolazione == anno){
            cout << left << setw(15) << autosalone[i].marca 
                 << setw(12) << autosalone[i].cilindrata 
                 << setw(8) << autosalone[i].annoImmatricolazione 
                 << setw(15) << autosalone[i].acq.nome
                 << setw(15) << autosalone[i].acq.cognome
                 << setw(20) << autosalone[i].acq.codiceFiscale
                 << endl;
            found = true;
        }
    }
    if(!found){
        cout << "\nNessuna auto trovata per l'anno " << anno << ".\n";
    }
    cout << "Digita 0 per tornare al menu'...";
    int temp;
    cin >> temp;
}

void visTabella(Auto autosalone[], int dim){
    system("cls");
    cout << left << setw(15) << "Marca" << setw(12) << "Cilindrata" << setw(8) << "Anno" << setw(15) << "Nome" << setw(15) << "Cognome" << setw(20) << "Cod.Fiscale" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < dim; i++){
        cout << left << setw(15) << autosalone[i].marca 
             << setw(12) << autosalone[i].cilindrata 
             << setw(8) << autosalone[i].annoImmatricolazione 
             << setw(15) << autosalone[i].acq.nome
             << setw(15) << autosalone[i].acq.cognome
             << setw(20) << autosalone[i].acq.codiceFiscale
             << endl;
    }
    cout << "Digita 0 per tornare al menu'...";
    int temp;
    cin >> temp;
}