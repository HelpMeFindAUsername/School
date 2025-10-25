// LUCCHINI ALBERTO

#include <iostream>
#include <iomanip>

using namespace std;

int personaCercata;
string cognomeCercato;

bool uscita = false;

const int DIM = 1;

struct lista {
    string nome[20];
    string cognome[20];
    string indirizzo[50];
    string citta[30];
    struct dataDiNascita {
        int giorno;
        int mese;
        int anno;
    } dataDiNascita;

    struct numeroTel {
        int prefisso;
        string numero[10];
    } nTel;

    struct genitore1 {
        string nome[40];
        string cognome[40];
    } genitore1;

    struct genitore2 {
        string nome[40];
        string cognome[40];
    } genitore2;

    string mail[60];
};

lista persona[DIM];

void chiediDati(){
    for(int i=0; i<DIM; i++){
        cout << "Inserisci il nome: ";
        cin >> persona[i].nome[i];
        cout << "Inserisci il cognome: ";
        cin >> persona[i].cognome[i];
        cout << "Inserisci l'indirizzo: ";
        cin >> persona[i].indirizzo[i];
        cout << "Inserisci la citta': ";
        cin >> persona[i].citta[i];
        cout << "Inserisci la data di nascita (gg mm aaaa): ";
        cin >> persona[i].dataDiNascita.giorno >> persona[i].dataDiNascita.mese >> persona[i].dataDiNascita.anno;
        cout << "Inserisci il prefisso telefonico: ";
        cin >> persona[i].nTel.prefisso;
        cout << "Inserisci il numero di telefono: ";
        cin >> persona[i].nTel.numero[i];
        cout << "Inserisci il nome del genitore 1: ";
        cin >> persona[i].genitore1.nome[i];
        cout << "Inserisci il cognome del genitore 1: ";
        cin >> persona[i].genitore1.cognome[i];
        cout << "Inserisci il nome del genitore 2: ";
        cin >> persona[i].genitore2.nome[i];
        cout << "Inserisci il cognome del genitore 2: ";
        cin >> persona[i].genitore2.cognome[i];
        cout << "Inserisci la mail: ";
        cin >> persona[i].mail[i];
    }
}

void cercaPersone(string cognome){
    for(int i=0; i<DIM; i++){
        if(persona[i].cognome[i] == cognome){
            cout << "Nome: " << persona[i].nome[i] << endl;
            cout << "Cognome: " << persona[i].cognome[i] << endl;
            cout << "Indirizzo: " << persona[i].indirizzo[i] << endl;
            cout << "Citta': " << persona[i].citta[i] << endl;
            cout << "Data di nascita: " << persona[i].dataDiNascita.giorno << "/" << persona[i].dataDiNascita.mese << "/" << persona[i].dataDiNascita.anno << endl;
            cout << "Numero di telefono: +" << persona[i].nTel.prefisso << " " << persona[i].nTel.numero[i] << endl;
            cout << "Genitore 1: " << persona[i].genitore1.nome[i] << " " << persona[i].genitore1.cognome[i] << endl;
            cout << "Genitore 2: " << persona[i].genitore2.nome[i] << " " << persona[i].genitore2.cognome[i] << endl;
            cout << "Mail: " << persona[i].mail[i] << endl;
            personaCercata = i;
        }
    }
}

void cambioDato(){
    int scelta;
    cout << "Cosa vuoi cambiare?" << endl;
    cout << "1 - Nome" << endl;
    cout << "2 - Cognome" << endl;
    cout << "3 - Indirizzo" << endl;
    cout << "4 - Citta'" << endl;
    cout << "5 - Data di nascita" << endl;
    cout << "6 - Numero di telefono" << endl;
    cout << "7 - Genitore 1" << endl;
    cout << "8 - Genitore 2" << endl;
    cout << "9 - Mail" << endl;
    cin >> scelta;

    switch(scelta){
        case 1:
            cout << "Inserisci il nuovo nome: ";
            cin >> persona[personaCercata].nome[personaCercata];
            break;
        case 2:
            cout << "Inserisci il nuovo cognome: ";
            cin >> persona[personaCercata].cognome[personaCercata];
            break;
        case 3:
            cout << "Inserisci il nuovo indirizzo: ";
            cin >> persona[personaCercata].indirizzo[personaCercata];
            break;
        case 4:
            cout << "Inserisci la nuova citta': ";
            cin >> persona[personaCercata].citta[personaCercata];
            break;
        case 5:
            cout << "Inserisci la nuova data di nascita (gg mm aaaa): ";
            cin >> persona[personaCercata].dataDiNascita.giorno >> persona[personaCercata].dataDiNascita.mese >> persona[personaCercata].dataDiNascita.anno;
            break;
        case 6:
            cout << "Inserisci il nuovo prefisso telefonico: ";
            cin >> persona[personaCercata].nTel.prefisso;
            cout << "Inserisci il nuovo numero di telefono: ";
            cin >> persona[personaCercata].nTel.numero[personaCercata];
            break;
        case 7:
            cout << "Inserisci il nuovo nome del genitore 1: ";
            cin >> persona[personaCercata].genitore1.nome[personaCercata];
            cout << "Inserisci il nuovo cognome del genitore 1: ";
            cin >> persona[personaCercata].genitore1.cognome[personaCercata];
            break;
        case 8:
            cout << "Inserisci il nuovo nome del genitore 2: ";
            cin >> persona[personaCercata].genitore2.nome[personaCercata];
            cout << "Inserisci il nuovo cognome del genitore 2: ";
            cin >> persona[personaCercata].genitore2.cognome[personaCercata];
            break;
        case 9:
            cout << "Inserisci la nuova mail: ";
            cin >> persona[personaCercata].mail[personaCercata];
            break;
        default:
            cout << "Scelta non valida." << endl;
        }
}

void stampaTabella(){
    cout << setw(15) << ""  << setw(15) << "Nome" << setw(15) << "Cognome" << setw(15) << "Indirizzo" << setw(15) << "Citta'" << setw(15) << "Data di nascita" << setw(20) << "Numero di telefono" << setw(20) << "Genitore 1" << setw(20) << "Genitore 2" << setw(30) << "Mail" << endl;
    for(int i = 0; i < DIM; i++){
        cout << setw(15) << i+1 << setw(15) << persona[i].nome[i] << setw(15) << persona[i].cognome[i] << setw(15) << persona[i].indirizzo[i] << setw(15) << persona[i].citta[i] << setw(2) << setfill('0') << persona[i].dataDiNascita.giorno << "/" << setw(2) << setfill('0') << persona[i].dataDiNascita.mese << "/" << setw(4) << setfill('0') << persona[i].dataDiNascita.anno << setfill(' ') << setw(20) << "+" << persona[i].nTel.prefisso << " " << persona[i].nTel.numero[i] << setw(20) << persona[i].genitore1.nome[i] << " " << persona[i].genitore1.cognome[i] << setw(20) << persona[i].genitore2.nome[i] << " " << persona[i].genitore2.cognome[i]  << setw(30) << persona[i].mail[i] << endl;
    }
    cout << endl;
    cout << "Inserisci il cognome di chi vuoi modificare? (0 per uscire): ";
    cin >> cognomeCercato;
    if(cognomeCercato == "0"){
        uscita = true;
    }
}

int main(){
    chiediDati();
    system("cls");
    stampaTabella();
    while(!uscita){
        system("cls");
        cercaPersone(cognomeCercato);
        if(!uscita){
            cambioDato();
            stampaTabella();
        }
    }
    return 0;
}