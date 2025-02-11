//
//  main.cpp
//  5Febbraio
//
//  Created by Alberto Lucchini on 2/5/25.
//

#include <iostream>


using namespace std;

void initVet(int* vet, int* vetP, int* vetD, int NE){
    for (int i = 0; i < NE; i++) {
        vet[i] = 0;
        vetP[i] = 0;
        vetD[i] = 0;
    }
}

void assVet(int* vet, int NE){
    for (int i = 0; i < 2; i++) {
        vet[i] = rand() % 6;
    }
}

void sommaVet(int* vet, int NE){
    for(int i = 2; i < NE; i++){
        vet[i] = vet[i-2] + vet[i - 1];
    }
}

void assP(int* vet, int* vetP, int NE, int contaP){
    int i = 0;
    while (i < NE) {
        vetP[contaP] = vet[i];
        contaP++;
        i++;
    }
}

void assD(int* vet, int* vetD, int NE, int contaD){
    int i = 0;
    do{
        vetD[contaD] = vet[i];
        contaD++;
        i++;
    }while (i < NE);
}

float media(int* vet, int NE){
    int somma = 0;
    for (int i = 0; i < NE; i++) {
        somma += vet[i];
    }
    return somma/NE;
}

int MinMedia(int media, int NE, int* vet){
    int min = 0;
    for (int i = 0; i < NE; i++) {
        if(vet[i] < media){
            min++;
        }
    }
    return min;
}

int MaxMedia(int media, int NE, int* vet){
    int max = 0;
    for (int i = 0; i < NE; i++) {
        if(vet[i] > media){
            max++;
        }
    }
    return max;
}

int Pivot(int media, int NE, int* vet){
    
    return (vet[0] + 1)*media;
}


int main() {
    const int NE = 16;
    int vet[NE], vetP[NE], vetD[NE];
    int contaP = 0, contaD = 0;
    
    srand(time(0));
    xq
    
    cout << "Vet: "
    for(int i = 0; i < NE; i++){
        cout << i << ":" <<vet[i] << "     ";
    }
    
    
    
    return 0;
}
