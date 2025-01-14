//
//  LUCCHINI_GESTIONE_TRE_VALORI.cpp
//
//  Created by Alberto Lucchini on 11/12/24
//

#include <iostream>
using namespace std;

int ins_dato_x(){
    int x;
    cout << "Inserisci il primo valore ";
    cin >> x;
    return x;
}
int ins_dato_y(){
    int y;
    cout << "Inserisci il secondo valore ";
    cin >> y;
    return y;
}
int ins_dato_z(){
    int z;
    cout << "Inserisci il terzo valore ";
    cin >> z;
    return z;
}

int somma_valori(int x, int y, int z) {
    int somma = 0;
    somma = x + y + z;
    return somma;
}

int molt_valori(int x, int y, int z) {
    int molt = 0;
    molt = x * y * z;
    return molt;
}
int n_max(int x, int y, int z){
    if(x > y){
        if (x > z)
            return x;
        else
            return z;
    }
    else{
        if (y > z)
            return y;
        else
            return z;
    }
}
void menu(){
    int input, x = 0, y = 0, z = 0, somma = 0, molt = 0, max = 0;
    bool dati_ins = 0;
    do {
        cout << "\nScegli una delle seguenti opzioni:\n1) Inserimento dati\n2) Somma dei dati\n3) Moltiplicazione dei dati\n4) Ricerca del valore più alto tra i dati\n5) Stampa dei risultati\n0) Uscita\n\nInserisci la tua scelta: ";
        cin >> input;
        do {
            switch (input) {
                case 1:
                    x = ins_dato_x();
                    y = ins_dato_y();
                    z = ins_dato_z();
                    dati_ins = 1;
                    input = 5;
                    break;
                case 2:
                    if(dati_ins){
                        somma = somma_valori(x, y, z);
                    }
                    input = 5;
                    break;
                case 3:
                    if(dati_ins) {
                        molt = molt_valori(x, y, z);
                    }
                    input = 5;
                    break;
                case 4:
                    if (dati_ins) {
                        max = n_max(x, y, z);
                    }
                    input = 5;
                    break;
                case 5:
                    if (dati_ins) {
                        
                        if(x != 0 && y != 0 && z != 0)
                            cout << "\nI valori inseriti sono: " << x << ", " << y << ", " << z << endl;
                        if (somma != 0) {
                            cout << "La somma dei valori inseriti è " << somma << endl;
                        }
                        if (molt != 0) {
                            cout << "Il prodotto dai valori inseriti è: " << molt << endl;
                        }
                        if (max != 0) {
                            cout << "Il valore più alto tra i valori inseriti è: " << max << endl;
                        }
                        
                    }
                    else{
                        cout << "Non hai inserito alcun Valore riprova\n";
                    }
                    input = 1;
                    break;
                
                default:
                    break;
            }
        } while (input == 5);
            
    } while (input  != 0);
    
    
}

int main() {
    menu();
    return 0;
}
