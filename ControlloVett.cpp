//
//  main.cpp
//  19mar
//
//  Created by Alberto Lucchini on 3/19/25.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int NE = 20;

int vet[NE];
bool vetApp[NE];

void assVet(){
    for(int i = 0; i < NE; i++){
        vet[i] = rand() % 101;
    }
}

void controlloVet(){
    //crescente
    for(int i = 0; i <= NE; i++){
        if(vet[i] == i){
            vetApp[i] = 1;
        }
        else{
            vetApp[i] = 0;
        }
    }
}

void stampaVet(){
    cout << "Vettore originale:\n";
    for (int i = 1; i <= NE; i++) {
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
    
    }
    cout << "\nVettore di controllo:\n";
    for (int i = 1; i <= NE; i++) {
        cout << vetApp[i];
        cout << "     ";
    }
    
    
    
    
}

int main() {
    
    srand(time(0));
    assVet();
    controlloVet();
    stampaVet();
    
    return 0;
}
