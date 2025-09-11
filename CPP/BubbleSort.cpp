//
//  main.cpp
//  19maz
//
//  Created by Alberto Lucchini on 3/19/25.
//

#include <iostream>
using namespace std;

const int NE = 50;

int vet[NE], vetApp[NE];
int sc;
bool verso;

void assVet(){
    for(int i = 0; i < NE; i++){
        vet[i] = rand() % 101;
    }
}

void copiaVet(){
    for(int i = 0; i < NE; i++){
        vetApp[i] = vet[i];
    }
}

void ordinaVet(){
    //crescente
    if(verso){
        for(int j = 0; j < NE - 1; j++){
            for(int i = 0; i < NE - 1; i++){
                if(vetApp[i] > vetApp[i + 1]){
                    sc = vetApp[i];
                    vetApp[i] = vetApp[i + 1];
                    vetApp[i + 1] = sc;
                }
            }
        }
    }
    //decrescente
    else{
        for(int j = 0; j < NE - 1; j++){
            for(int i = 0; i < NE - 1; i++){
                if(vetApp[i] < vetApp[i + 1]){
                    sc = vetApp[i];
                    vetApp[i] = vetApp[i + 1];
                    vetApp[i + 1] = sc;
                }
            }
        }
    }
}

void stampaVet(){
    cout << "Vettore originale:\n";
    for (int i = 1; i < NE + 1; i++) {
        cout << vet[i-1];
        if(vet[i-1] < 10){
            cout << "     ";
        }
        else if (vet [i-1] < 100){
            cout << "    ";
        }
        else if (vet [i-1] >= 100){
            cout << "   ";
        }
        if(i % 10 == 0) {
            cout << endl;
        }
    
    }
    cout << "Vettore ordinato:\n";
    for (int i = 1; i < NE+1; i++) {
        cout << vetApp[i-1];
        if(vetApp[i-1] < 10){
            cout << "     ";
        }
        else if (vetApp[i-1] < 100){
            cout << "    ";
        }
        else if (vetApp[i-1] >= 100){
            cout << "   ";
        }
        if(i % 10 == 0) {
            cout << endl;
        }
    }
    
    
    
    
}

int main() {
    
    srand(time(0));
    cout << "Inserisci il verso dell'ordinamento (0. deccrescente      1. crescente): ";
    cin >> verso;
    assVet();
    copiaVet();
    ordinaVet();
    stampaVet();
    
    return 0;
}
