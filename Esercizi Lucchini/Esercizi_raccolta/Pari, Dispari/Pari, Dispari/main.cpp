//
//  main.cpp
//  Pari, Dispari
//
//  Created by Alberto Lucchini on 1/8/25.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int vet[20];
    int contaP = 0, contaD = 0;
    int vetP[20];
    int vetD[20];
    float media = 0;
    srand(time(0));
    for(int i=0; i < 20; i++){
        vet[i] = rand() % 51;
    }
    
    for(int i = 0; i < 20; i++){
        vetP[i] = 99;
        vetD[i] = 99;
    }
    
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
    cout << "Numeri: ";
    
    for (int i = 0; i < 20; i++) {
       cout << vet[i] << "  ";
    }
    cout << endl;
    cout << "Numeri pari: ";
    
    for (int i = 0; i < 20 && vetP[i] != 99; i++) {
       cout << vetP[i] << "  ";
    }
    cout << endl;
    cout << "Numeri dispari: ";
    
    for (int i = 0; i < 20 && vetD[i] != 99; i++) {
       cout << vetD[i] << "  ";
    }
    cout << endl;
    
    for(int i = 0; i < contaP; i++){
        media += vetP[i];
    }
    if (media != 0) {
        media /= contaP;
        cout << "Media pari: " << media << endl;
    }
    else
        cout << "Non ci sono valori pari" << endl;
    
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
