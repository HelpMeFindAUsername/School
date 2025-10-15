// StructProva.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstring>

using namespace std;

const int DIM_ELE = 1;

struct lista {
    char nome[20];
    char cognome[20];
    char indirizzo[50];
    char citta[30];
    struct dataDiNascita {
        int giorno;
        int mese;
        int anno;
    } dataDiNascita;

    struct numeroTel {
        int prefisso;
        char numero[10];
    } nTel;

    struct genitore1 {
        char nome[40];
        char cognome[40];
    } genitore1;

    struct genitore2 {
        char nome[40];
        char cognome[40];
    } genitore2;

    char mail[60];
};

lista elenco[DIM_ELE];

void prendiInfo(int nElenco) {
    cout << "Inserisci il nome: ";
    cin >> elenco[nElenco].nome;
    cout << "Inserisci il cognome: ";
    cin >> elenco[nElenco].cognome;

    cout << "Inserisci l'indirizzo: ";
    cin >> elenco[nElenco].indirizzo;

    cout << "Inserisci la citta': ";
    cin >> elenco[nElenco].citta;

    cout << "Inserisci il giorno di nascita: ";
    cin >> elenco[nElenco].dataDiNascita.giorno;
    cout << "Inserisci il mese di nascita: ";
    cin >> elenco[nElenco].dataDiNascita.mese;
    cout << "Inserisci l'anno di nascita: ";
    cin >> elenco[nElenco].dataDiNascita.anno;

    cout << "Inserisci il prefisso del numero di telefono: +";
    cin >> elenco[nElenco].nTel.prefisso;
    cout << "Inserisci il numero di telefono: ";
    cin >> elenco[nElenco].nTel.numero;

    cout << "Inserisci il nome del primo genitore: ";
    cin >> elenco[nElenco].genitore1.nome;
    cout << "Inserisci il cognome del primo genitore: ";
    cin >> elenco[nElenco].genitore1.cognome;

    cout << "Inserisci il nome del secondo genitore: ";
    cin >> elenco[nElenco].genitore2.nome;
    cout << "Inserisci il cognome del secondo genitore: ";
    cin >> elenco[nElenco].genitore2.cognome;

    cout << "Inserisci l'indirizzo email: ";
    cin >> elenco[nElenco].mail;
}

void stampaEle(int nElenco) {
    cout << "Nome: " << elenco[nElenco].nome << endl;
    cout << "Cognome: " << elenco[nElenco].cognome << endl;
    cout << "Indirizzo: " << elenco[nElenco].indirizzo << endl;
    cout << "Citta': " << elenco[nElenco].citta << endl;
    cout << "Data di nascita: " << elenco[nElenco].dataDiNascita.giorno << "/"
         << elenco[nElenco].dataDiNascita.mese << "/"
         << elenco[nElenco].dataDiNascita.anno << endl;
    cout << "Numero di telefono: +" << elenco[nElenco].nTel.prefisso << " "
         << elenco[nElenco].nTel.numero << endl;
    cout << "Genitore 1: " << elenco[nElenco].genitore1.nome << " " << elenco[nElenco].genitore1.cognome << endl;
    cout << "Genitore 2: " << elenco[nElenco].genitore2.nome << " " << elenco[nElenco].genitore2.cognome << endl;
    cout << "Email: " << elenco[nElenco].mail << endl;
}

int main() {
    for (int i = 0; i < DIM_ELE; i++) {
        cout << "\nInserimento dati per la persona #" << (i + 1) << endl;
        prendiInfo(i);
    }

    // system("cls"); // Optional: clear screen, not portable

    for (int i = 0; i < DIM_ELE; i++) {
        cout << "\nDati della persona #" << (i + 1) << endl;
        stampaEle(i);
    }

    return 0;
}