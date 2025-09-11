//
//  main.cpp
//  22Feb
//
//  Created by Alberto Lucchini on 2/22/25.
/*
 Si definisca un vettore di 27 elementi di sole lettere minuscole
 1. definire
 2. Init vet
 3. Stampa vet
 4. def un vet di 27 elementi con il valore corrispondete della tabella ascii
 5. Stampa vet n
 */

#include <iostream>
using namespace std;

const int IND = 27;
char vet[IND];
int vetn[IND];

void initVet(){
    for (int i = 0; i < IND; i++) {
        vet[i] = 0;
        vetn[i] = 0;
    }
}

void assVet(){
    for (int i = 0; i < IND; i++) {
        vet[i] = rand()%26 + 97;
        vetn[i] = vet[i];
    }
}

void stampaVet(){
    cout << "\nVet lettere:      ";
    for (int i = 0; i < IND; i++) {
        cout << i << ":" << vet[i];
        cout << "     ";
    }
    cout << "\n\nVet ASCII:      ";
    for (int i = 0; i < IND; i++) {
        cout << i << ":" << vetn[i];
        if (vetn[i] < 10) {
            cout << "     ";
        }
        else if (vetn[i] >= 10) {
            cout << "    ";
        }
    }
}

int main() {
    srand(time(0));
    char in;
    bool trovato = 0;
    int pos;
    initVet();
    assVet();
    stampaVet();
    cout << "\n\nChe lettera si vuole trovare?   ";
    cin >> in;
    
    for (int i = 0; i < IND && !trovato; i++) {
        if (vet[i] == in) {
            trovato = 1;
            pos = i;
        }
    }
    if(trovato)
        cout << "\nLa lettera " << in << " si trova nella posizione " << pos << endl;
    else
        cout << "\nLa lettera " << in << " non è disponibile." << endl;
    return 0;
}
