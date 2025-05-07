//
//  3 mag
//
//  Created by Alberto Lucchini on 5/3/25.
//
// 1) chi? input indice(p)
// 2) dove? input indice(s); stampa stanza
// 3) se input2 == rand()%5; cout << "Corretto!"
//
//
//
//
//
//
//
//
//
//



#include <iostream>
#include <iomanip>
using namespace std;
const int NE = 5;
string p[NE]={"A", "B", "C", "D", "E"};
string s[NE]={"s1", "s2", "s3", "s4", "s5"};

int inputN, inputS, stanza;

int main() {
    srand(time(0));
    cout << "Chi sei?\n";
    for(int i = 0; i < NE*2; i++){
        if (i < NE)
            cout << p[i] << setw(p[i%5].length()+3);

        else if (i == NE){
            cout << setw(1) << endl;
            cout << i%5 << setw(p[i%5].length()+3);
        }
        else
            cout << setw(p[i%5].length()+3) << i%5;
    }
    cout << endl;
    cin >> inputN;
    inputN %= 5;
    
    cout << "Ciao " << p[inputN] << ", dove ti trovi?\n";
    for(int i = 0; i < NE*2; i++){
        if (i < NE)
            cout << s[i] << setw(s[i%5].length()+3);

        else if (i == NE){
            cout << setw(1) << endl;
            cout << i%5 << setw(s[i%5].length()+3);
        }
        else
            cout << setw(s[i%5].length()+3) << i%5;
    }
    cout << endl;
    cin >> inputS;
    inputS %= 5;
    stanza = rand()%5;
    if (inputS == stanza) {
        cout << "Corretto!\n";
    }
    else
        cout << "Sbagliato, sei nella stanza: " << s[stanza] << endl;
    
    
    return 0;
}
