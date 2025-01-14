//
//  main.cpp
//  Pari, Dispari
//
//  Created by Alberto Lucchini on 1/8/25.
//

#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main() {
    int vet[20];
    int vetP[20];
    int vetD[20];
    int contaP = 0, contaD = 0;
    float media = 0;

// Creazione dei 20 numeri casuali per il vettore
    srand(time(0));
    for(int i=0; i < 20; i++){
        vet[i] = rand() % 51;
    }

// Inizializzazione dei vettori vetP e vetD
    for(int i = 0; i < 20; i++){
        vetP[i] = 99;
        vetD[i] = 99;
    }

// Assegnazione dei valori pari e dispari ai vettori vetP e vetD
    for(int i = 0; i < 20; i++){
        
        if(vet[i]%2 == 0){
            vetP[contaP] = vet[i];
            contaP++;
        }
        else{
            vetD[contaD] = vet[i];
            contaD++;
        }
    }

// Stampa dei vettori
    cout << "Numeri:          ";

    for (int i = 0; i < 20; i++) {
       cout << i << ": " << vet[i];
       if(i < 19)
        cout << ", ";
    }
    cout << "\n\n";
    cout << "Numeri pari:     ";
    
     for (int i = 0; i < contaP; i++) {
       cout << i << ": " << vetP[i];
       if(i < contaP-1)
        cout << ", ";
    }
    cout << "\n\n";
    cout << "Numeri dispari:  ";
    
     for (int i = 0; i < contaD; i++) {
       cout << i << ": " << vetD[i];
       if(i < contaD-1)
        cout << ", ";
    }
    
    for(int i = 0; i < contaP; i++){
        media += vetP[i];
    }


    if (media != 0) {
        media /= contaP;
        cout << "\n\nMedia pari: " << media << endl;
    }
    else
        cout << "\n\nNon ci sono valori pari" << endl;
    
    media = 0;
    

    for(int i = 0; i < contaD; i++){
        media += vetD[i];
    }

    
    if (media != 0) {
        media /= contaD;
        cout << "Media dispari: " << media << endl;
    }
    else
        cout << "Non ci sono valori dispari" << endl;
    
    
    return 0;
}
