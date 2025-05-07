//
//  main.cpp
//  7mag
//
//  Created by Alberto Lucchini on 5/7/25.
/*
 array 100 el
 input rand

 stamp_vet
 5 spazi in gotoxy tra un elemento e l'altro
 ordin_vet => decrescente
 richiama_vet

 menù iniziale
 1 carica dati
 2 stampa dati
 3 ordina dati e stampa dati
 4 esci
 */


#include <iostream>
#include <ctime>
#include <stdlib>
#include <windows.h>

using namespace std;

const int NE = 100;
int vet[NE], vet_ord[NE];
int x = 0, y = 0;
int incx=3;

void carica_vet(int vet[], int vet2[], int ne);
void stampa_vet(int vet[], int vet2[], int ne);
void ordina_vet(int vet[], int ne);
int menu();



int main(){
    srand(time(0));
    switch (menu()) {
        case 1:
            carica_vet(vet, vet_ord, NE);
            break;
        case 2:
            stampa_vet(vet, vet_ord, NE);
            break;
        case 3:
            ordina_vet(vet_ord, NE);
            break;
        
        default:
            break;
    }
    return 0;
}

void carica_vet(int v[], int v2[], int ne){
    for(int i = 0; i < ne; i++){
        v[i] = rand()%50;
        v2[i] = v[i];
    }
}


void ordina_vet(int v[], int ne){
    int sc;
    for(int i = 0; i < ne-1; i++){
        for (int j = i++; j < ne; j++) {
            if(v[i] < v[j]){
                sc = v[i];
                v[i] = v[j];
                v[j] = sc;
            }
        }
    }
}

void stampa_vet(int vet[], int vet2[], int ne){
    for (int i = 0; i < 10; i++) {
        x = 0
        for (int j = 0; j < 10; i++) {
            y = i;
            gotoxy(x, y);
            cout << vet[i*10+j];
            x+=incx;
        }
    }
    y = 12;
    incx = 5;
    
    for (int i = 0; i < 10; i++) {
        x = 0;
        for (int j = 0; j < 10; i++) {
            y++;
            gotoxy(x, y);
            cout << vet2[i*10+j];
            x+=incx;
        }
    }
    
}

int menu(){
    int input;
    cout << "!BENVENUTO!\n";
    
    cout << "\n1 carica dati\n";
    cout << "2 stampa dati\n";
    cout << "3 ordina dati e stampa dati\n";
    cout << "4 esci\n\n";
    
    cout << "Inserisci un'opzione: ";
    cin >> input;
    
    return input;
}
