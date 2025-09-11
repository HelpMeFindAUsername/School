// Lucchini Alberto
//
// Lucchini_clessidra.cpp
//
#include <iostream>
using namespace std;

void superiore(int n) {
    for (int i = n; i > 0; i--) {
        int s = n - i;
        for (int j = 0; j < s; j++) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void inferiore(int n) {
    for (int i = 2; i <= n; i++) {
        int s = n - i;
        for (int j = 0; j < s; j++) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Inserisci un numero (0-50): \n";
    cin >> n;

    if (n < 0 || n > 50) {
        cout << "Il numero deve essere compreso tra 0 e 50" << endl;
        return 0;
    }
    superiore(n);
    inferiore(n);
    
    return 0;
}
