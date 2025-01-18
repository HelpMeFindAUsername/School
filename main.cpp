//
//  main.cpp
//  Es18gennaio
//
//  Created by Alberto Lucchini on 1/18/25.
//
/*
 
 definire un vettore di 20 elementi
 inizializzare con numeri casuali(4-40)
 definire un'altro vettore di 20 elementi
 chiedere all'utente un numero intero(0-10)
 ogni elemento del secondo vettore[i] conterra l'elemento del primo vettore di posizione i + input
 
 vet2[i] = vet[i+input]
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    
    srand(time(0));
    
    int vet1[20], vet2[20];
    
    for(int i = 0; i < 20; i++){
        vet1[i] = (rand() % 37) + 4;
    }
        
    cout << "Hello, World!\n";
    
    
    return 0;
}
