//
//  main.cpp
//  Es29gennaio
//
//  Created by Alberto Lucchini on 1/18/25.


#include <iostream>
#include <cmath>

using namespace std;

void init_vet(int *vet, int ne){
    for (int i=0; i < ne; i++) {
        vet[i] = 0;
    }
}

void Carica_Ele(int *vet, int ne){
    for (int i=0; i < ne; i++) {
        vet[i] = rand()%71 + 10;
    }
}

void Stampa_Ele(int *vet, int ne){
    cout << "Elementi: ";
    for (int i=0; i < ne; i++) {
        if(vet[i] < 10)
           cout << " " << vet[i] << "   ";
        else
           cout << vet[i] << "   ";
    }
    cout << endl;
}

int trovoVetMin(int *vet, int ne, int x){
    int val = vet[x];
    int conta = 0;
    for (int i = 0; i < ne; i++) {
        if(vet[i] < val){
            conta++;
        }
    }
    
    return conta;
}

int trovoVetMax(int *vet, int ne, int x){
    int val = vet[x];
    int conta = 0;
    for (int i = 0; i < ne; i++) {
        if(vet[i] > val){
            conta++;
        }
    }
    return conta;
}

int Ricerca_Ele(int *vet, int ne, int x){
    int val = vet[x];
    int pos = 100;
    for (int i = 0; i < pos; i++) {
        if(vet[i] == val){
            pos = i;
        }
    }
    return pos;
}


int main() {
    srand(time(0));
    
    const int NE = 20;
    int vet[NE], x;
    
    x = rand() % (NE + 1);
    
    init_vet(vet, NE);
    Carica_Ele(vet, NE);
    Stampa_Ele(vet, NE);
    cout << "\nx = " << x;
    cout << "\n\nValori minori di " << vet[x] << ": " << trovoVetMin(vet, NE, x);
    cout << "\nValori maggiori di " << vet[x] << ": " << trovoVetMax(vet, NE, x);
    cout << "\nPosizione del primo valore uguale a " << vet[x] << ": " << Ricerca_Ele(vet, NE, x);
    cout << "\n";
    
    return 0;
}
