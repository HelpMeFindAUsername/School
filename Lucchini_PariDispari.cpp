//
//  main.cpp
//  Pari, Dispari
//
//  Created by Alberto Lucchini on 1/8/25.
//

#include <iostream>
#include <cmath>

using namespace std;

// Creazione dei 20 numeri casuali per il vettore
void assVet(int* vet){
    srand(time(0));
    for(int i=0; i < 20; i++){
        vet[i] = rand() % 101;
    }
}
// Inizializzazione dei vettori vetP e vetD
void initVet(int* vetP, int* vetD){
    for(int i = 0; i < 20; i++){
        vetP[i] = 99;
        vetD[i] = 99;
    }
}
// Assegnazione dei valori pari e dispari ai vettori vetP e vetD
void assVetPD(int* vet, int* vetP, int* vetD, int& contaP, int& contaD){
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
}
// Stampa dei vettori
void stampaVet(int* vet, int* vetP, int* vetD, int contaP, int contaD){
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
}
// Calcolo della media
float mediaPD(int vetPD[], int conta){
    float media = 0;
    for(int i = 0; i < conta; i++){
        media += vetPD[i];
    }
    media /= conta;
    return media;
}
//stampo la media dei numeri pari e dispari
void stampaMedia(int* vetP, int* vetD, int contaP, int contaD){
    if (contaP != 0){
        cout << "Media numeri pari: " << mediaPD(vetP, contaP) << endl;
    }

    else{
        cout << "Non ci sono valori pari" << endl;
    }
    if (contaD != 0){
        cout << "Media numeri dispari: " << mediaPD(vetD, contaD) << endl;
    }

    else{
        cout << "Non ci sono valori dispari" << endl;
    }
}

int main() {

    int vet[20], vetP[20], vetD[20];
    int contaP = 0, contaD = 0;
    float media = 0;

    assVet(vet);
    initVet(vetP, vetD);
    assVetPD(vet, vetP, vetD, contaP, contaD);
    stampaVet(vet, vetP, vetD, contaP, contaD);
    cout << "\n\n";
    stampaMedia(vetP, vetD, contaP, contaD);
    
    return 0;
}
